/**
 * @file    Context.cpp
 * @brief   The Context manage all ZeroMQ sockets of an application.
 * @ingroup ZMQCpp
 *
 * Copyright (c) 2013 Sebastien Rombauts (sebastien.rombauts@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#pragma once

#include "Utils.h"  // libzmq "zmq.h" include file
#include "Context.h"
#include "Exception.h"


namespace ZMQ
{

// Constructor of a new ØMQ context with zmq_new().
Context::Context(void) :
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

// Destructor shall destroy the ØMQ context context.
Context::~Context(void)
{
    int ret = zmq_ctx_destroy(mpContext);
    ZMQ_CPP_ASSERT(0 == ret);
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
