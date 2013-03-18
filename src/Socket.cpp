/**
 * @file    Socket.cpp
 * @ingroup ZMQCpp
 * @brief   Manage a ZeroMQ socket.
 *
 * Copyright (c) 2013 Sebastien Rombauts (sebastien.rombauts@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#pragma once

#include "Utils.h"  // libzmq "zmq.h" include file
#include "Socket.h"
#include "Exception.h"


namespace ZMQ
{

// Constructor of a new ØMQ socket with zmq_().
Socket::Socket(void)
{
}

// Destructor shall destroy the ØMQ socket.
Context::~Context(void)
{
}

// Check a ZeroMQ return code : must be nul ou positive.
void check(int aRet)
{
    if (0 > aRet)
    {
        throw Exception(zmq_strerror(zmq_errno()));
    }
}


}   // namespace ZMQ
