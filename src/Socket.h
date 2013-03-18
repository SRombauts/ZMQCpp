/**
 * @file    Socket.h
 * @ingroup ZMQCpp
 * @brief   Manage a ZeroMQ socket.
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
 * @brief Manage a ZeroMQ socket.
 */
class Socket
{
public:
    /**
     * @brief Constructor of a new ØMQ socekt with zmq_().
     */
    Socket(void);

    /**
     * @brief Destructor shall destroy the ØMQ socket.
     *
     * @todo must close any socket still open
     *
     * @see http://api.zeromq.org/3-2:zmq-ctx-destroy
     */
    ~Socket(void);

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
