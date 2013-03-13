/**
 * @file  Context.hpp
 * @brief The Context manage all ZeroMQ sockets of an application.
 *
 * Copyright (c) 2013 Sebastien Rombauts (sebastien.rombauts@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#pragma once


#include <zmq.h>


// Compatibility defines
// TODO : move those defines in a central ZMQCpp.hpp include file
#ifndef ZMQ_DONTWAIT
#   define ZMQ_DONTWAIT   ZMQ_NOBLOCK
#endif
#ifndef ZMQ_RCVHWM
#   define ZMQ_RCVHWM     ZMQ_HWM
#endif
#ifndef ZMQ_SNDHWM
#   define ZMQ_SNDHWM     ZMQ_HWM
#endif
#if ZMQ_VERSION_MAJOR == 2
#   define more_t int64_t
#   define zmq_ctx_destroy(context) zmq_term(context)
#   define zmq_msg_send(msg,sock,opt) zmq_send (sock, msg, opt)
#   define zmq_msg_recv(msg,sock,opt) zmq_recv (sock, msg, opt)
#   define ZMQ_POLL_MSEC    1000        //  zmq_poll is usec
#elif ZMQ_VERSION_MAJOR == 3
#   define more_t int
#   define ZMQ_POLL_MSEC    1           //  zmq_poll is msec
#endif
#ifndef ZMQ_IO_THREADS_DFLT
#   define ZMQ_IO_THREADS_DFLT  1
#endif



/**
 * @brief The Context manage ZeroMQ sockets of an application.
 *
 * @todo This Context maintain a list of all open socket.
 *       Upon its destruction, it shall close them, in a non blocking fashion.
 *
 * @todo The underliying ØMQ context is thread safe and may be shared among as many application threads as necessary,
 *       without any additional locking required on the part of the caller,
 *       but this Context is NOT thread-safe !
 */
class Context
{
    friend class Socket;

public:
    /**
     * @brief Constructor of a new ØMQ context with zmq_new().
     */
    Context(void) :
        mpContext(NULL)
    {
#if (ZMQ_VERSION_MAJOR < 3)
        mpContext = zmq_init(ZMQ_IO_THREADS_DFLT);
#else
        mpContext = zmq_new();
#endif
        if (mpContext == NULL)
        {
            throw std::runtime_error(zmq_strerror(zmq_errno()));
        }
    }
    /**
     * @brief Destructor shall destroy the ØMQ context context.
     *
     * @todo will close any
     *
     * @see http://api.zeromq.org/3-2:zmq-ctx-destroy
     */
    ~Context(void)
    {
        int ret = zmq_ctx_destroy(mpContext);
        check(ret);
    }
private:
    void check(int aRet)
    {
        if (aRet < 0)
        {
            throw std::runtime_error(zmq_strerror(zmq_errno()));
        }
    }

    void* mpContext;
};
