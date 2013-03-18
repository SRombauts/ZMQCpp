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
     * @brief Constructor of a new ØMQ socket with zmq_socket().
     *
     * @see http://api.zeromq.org/3-2:zmq_socket
     */
    Socket(void);

    /**
     * @brief Destructor shall destroy the ØMQ socket with zmq_close().
     *
     * @see http://api.zeromq.org/3-2:zmq_close
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
    void* mpSocket; //!< The underlying ØMQ socket
};


}   // namespace ZMQ
