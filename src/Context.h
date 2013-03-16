/**
 * @file    Context.h
 * @brief   The Context manage all ZeroMQ sockets of an application.
 * @ingroup ZMQCpp
 *
 * Copyright (c) 2013 Sebastien Rombauts (sebastien.rombauts@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#pragma once


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
    Context(void);

    /**
     * @brief Destructor shall destroy the ØMQ context context.
     *
     * @todo must close any socket still open
     *
     * @see http://api.zeromq.org/3-2:zmq-ctx-destroy
     */
    ~Context(void);

private:
    /**
     * @brief Check a ZeroMQ return code : must be nul ou positive.
     *
     * @param[in] aRet A ZeroMQ return code
     */
    void check(int aRet);

private:
    void* mpContext;
};


}   // namespace ZMQ
