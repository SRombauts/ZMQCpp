/**
 * @file  Boost.hpp
 * @brief Boost Unit Tests of this ZMQ C++ wrapper 
 *
 * Copyright (c) 2013 Sebastien Rombauts (sebastien.rombauts@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#define BOOST_TEST_MODULE ZMQCpp
#include <boost/test/included/unit_test.hpp>

#include "../src/Context.hpp"

BOOST_AUTO_TEST_CASE (context_test_case)
{
    // Initialize the ZMQ context
    Context context;
}
