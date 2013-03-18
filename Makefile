
### Options: ###

# C++ compiler 
CXX = g++

# flags for C++
CXXFLAGS ?= -Wall -Wextra -pedantic -Wformat-security -Winit-self -Wswitch-default -Wswitch-enum -Wfloat-equal -Wundef -Wshadow -Wcast-qual -Wconversion -Wlogical-op -Winline -Wsuggest-attribute=pure -Wsuggest-attribute=const -Wsuggest-attribute=noreturn

# [Debug,Release]
BUILD ?= Debug

### Conditionally set variables: ###

ifeq ($(BUILD),Debug)
BUILD_FLAGS = -g3 -rdynamic -fstack-protector-all -fno-inline -O0 -D_DEBUG
endif
ifeq ($(BUILD),Release)
BUILD_FLAGS = -O2 -DNDEBUG
endif
ifeq ($(BUILD),Debug)
LINK_FLAGS = -g3 -rdynamic
endif
ifeq ($(BUILD),Release)
LINK_FLAGS =
endif

### Variables: ###

CPPDEPS = -MT $@ -MF`echo $@ | sed -e 's,\.o$$,.d,'` -MD -MP

ZMQCPP_CXXFLAGS = $(BUILD_FLAGS) $(CXXFLAGS)
ZMQCPP_TESTS_OBJECTS =  \
	$(BUILD)/Boost.o \
	$(BUILD)/Context.o \
	$(BUILD)/Socket.o \
	
### Targets: ###

all: $(BUILD) $(BUILD)/tests

clean: 
	rm -f $(BUILD)/*.o
	rm -f $(BUILD)/*.d
	rm -f $(BUILD)/tests

$(BUILD): $(BUILD)/
	mkdir -p $(BUILD)


$(BUILD)/tests: $(ZMQCPP_TESTS_OBJECTS)
	$(CXX) -o $@ $(ZMQCPP_TESTS_OBJECTS) $(LINK_FLAGS) -lzmq 


$(BUILD)/Boost.o: tests/Boost.cpp
	$(CXX) -c -o $@ $(ZMQCPP_CXXFLAGS) $(CPPDEPS) $<

$(BUILD)/Context.o: src/Context.cpp
	$(CXX) -c -o $@ $(ZMQCPP_CXXFLAGS) $(CPPDEPS) $<

$(BUILD)/Socket.o: src/Socket.cpp
	$(CXX) -c -o $@ $(ZMQCPP_CXXFLAGS) $(CPPDEPS) $<


.PHONY: all clean


# Dependencies tracking:
-include $(BUILD)/*.d


