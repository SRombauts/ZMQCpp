/**
 * @file    ZMQCpp.h
 * @ingroup ZMQCpp
 * @brief   ZMQC++ (ZMQCpp) is a smart and easy to use C++ wrapper of the ZeroMQ messaging library.
 *
 * Include this main header file in your project to gain access to all functionality provided by the wrapper.
 *
 * Copyright (c) 2013 Sebastien Rombauts (sebastien.rombauts@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
/**
 * @defgroup ZMQCpp ZMQC++
 * @brief    ZMQC++ (ZMQCpp) is a smart and easy to use C++ wrapper of the ZeroMQ messaging library.
 */
#pragma once


// ZMQC++.h requires libzmq, and the corresponding library header
#include <zmq.h>

// Include useful headers of ZMQC++
#include "Exception.h"
#include "Context.h"


/**
 * @brief Version numbers for ZMQC++
 *
 * The [ZMQCPP_VERSION] C preprocessor macro in the SQLiteC++.h header
 * evaluates to a string literal that is the SQLite version in the
 * format "X.Y.Z" where X is the major version number
 * and Y is the minor version number and Z is the release number.
 *
 * The [ZMQCPP_VERSION_NUMBER] C preprocessor macro resolves to an integer
 * with the value (X*1000000 + Y*1000 + Z) where X, Y, and Z are the same
 * numbers used in [ZMQCPP_VERSION].
 */
#define ZMQCPP_VERSION              "0.0.0"
#define ZMQCPP_VERSION_NUMBER       0005000
