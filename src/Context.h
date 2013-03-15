/**
 * @file    Context.hpp
 * @brief   The Context manage all ZeroMQ sockets of an application.
 * @ingroup ZMQC++
 *
 * Copyright (c) 2013 Sebastien Rombauts (sebastien.rombauts@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#pragma once

#include <zmq.h>

#include "Exception.h"
#include "Utils.h"


namespace ZMQ
{

/**
 * @brief The Context manage ZeroMQ sockets of an application.
 *
 * @todo This Context maintain a list of all open socket.
 *       Upon its destruction, it shall close them, in a non blocking fashion.
 *
 * @todo The underlying ØMQ context is thread safe and may be shared among as many application threads as necessary,
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
        mpContext = zmq_ctx_new();
#endif
        if (NULL == mpContext)
        {
            throw Exception(zmq_strerror(zmq_errno()));
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
        ZMQ_CPP_ASSERT(0 == ret);
    }
private:
    void check(int aRet)
    {
        if (0 > aRet)
        {
            throw Exception(zmq_strerror(zmq_errno()));
        }
    }

    void* mpContext;
};


}   // namespace ZMQ
