/**
 * @file    Boost.hpp
 * @brief   Boost Unit Tests of this ZMQ C++ wrapper
 * @ingroup ZMQC++
 *
 * Copyright (c) 2013 Sebastien Rombauts (sebastien.rombauts@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#include "../src/Context.h"

#define BOOST_TEST_MODULE ZMQCpp
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE (context_test_case)
{
    // Initialize the ZMQ context
    ZMQ::Context context;
}

