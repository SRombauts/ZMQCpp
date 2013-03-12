ZMQC++
----------

ZMQC++ (ZMQCpp) is a C++ wrapper of the ZeroMQ messaging library

### About ZeroMQ:

The socket library that acts as a concurrency framework.
Carries messages across inproc, IPC, TCP, and multicast.
Asynch I/O for scalable multicore message-passing apps.
LGPL free software with static linking exception.
http://www.zeromq.org/

### About ZMQC++:

ZMQC++ offers an encapsulation arround the native C APIs of libzmq,
with a few intuitive and well documented C++ class.

### The goals of ZMQC++ are:

- to offer the best of existing simple C++ libzmq wrappers
- to be elegantly written with good C++ design, STL, exceptions and RAII idiom
- to keep dependencies to a minimum (STL and libzmq, optionnal Boost)
- to be portable
- to be light and fast
- to be thread-safe
- to have a good unit test coverage
- to use API names sticking with those of the zmq library (except frame vs message for multi-part message)
- to be well documented with Doxygen tags, and with some good examples
- to be well maintained
- to use a permissive MIT license, similar to BSD or Boost, for proprietary/commercial usage

It is designed using the Resource Acquisition Is Initialization (RAII) idom
(see http://en.wikipedia.org/wiki/Resource_Acquisition_Is_Initialization),
and throwing exceptions in case of ZeroMQ errors (exept in destructors,
where assert() are used instead).
Each ZMQC++ object must be constructed with a valid ZeroMQ context or socket,
and then is always valid until destroyed.

### Suported platforms:

Developements and tests are done under the following OSs :
- Debian 7 (testing)
- Ubuntu 12.10
- Windows XP/7/8
And following IDEs/Compilers
- GCC 4.7.x with a provided Makefile
- Eclipse CDT under Linux, using the provided Makefile
- Visual Studio Express 2008/2010/2012 for testing compatibility purpose

### Dependencies:

- a STL implementation (even an old one, like those provided with VC6/eVC4 should work)
- exception support (the class Exception inherit from std::runtime_error)
- the zmq library, either by linking to it dynamicaly or staticaly (libzmq-dev under Linux).

### Installation

To use this wrappers, you need to add the ZMQC++ source files from the src/ directory
in your project code base, and compile/link against the zmq library.

### License

Copyright (c) 2013 Sébastien Rombauts (sebastien.rombauts@gmail.com)

Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
or copy at http://opensource.org/licenses/MIT)

## Getting started
### First sample demonstrates how to initialize a context, create a socket and bind/connect it:
```C++
// TODO
```

## How to contribute
### GitHub website
The most efficient way to help and contribute to this wrapper project is to
use the tools provided by GitHub:
- please fill bug reports and feature requests here: https://github.com/SRombauts/ZMQCpp/issues
- fork the repository, make some small changes and submit them with pull-request

### Contact
You can also email me directly, I will answer any questions and requests.

### Coding Style Guidelines
The source code use the CamelCase naming style variant where :
- type names (class, struct, typedef, enums...) begins with a capital letter
- files (.cpp/.h) are named like the class they contains
- function and variable names begins with a lower case letter
- member variables begins with a 'm', function arguments begins with a 'a', boolean with a 'b', pointers with a 'p'
- each file, class, method and member variable is documented using Doxygen tags
See also http://www.appinf.com/download/CppCodingStyleGuide.pdf for good guidelines
