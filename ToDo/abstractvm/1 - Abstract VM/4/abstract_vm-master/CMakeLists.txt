cmake_minimum_required(VERSION 3.7)
project(abstract_vm_new)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/Read.cpp
        src/Tools.cpp
        src/LexerParser.cpp
        src/LexerParser2.cpp
        src/VirtualMachine.cpp
        src/Factory.cpp src/main.cpp)
add_executable(abstract_vm_new ${SOURCE_FILES})

#set(TEST_SOURCEF_FILES ${SOURCE_FILES} test/test.cpp)
#add_executable(mytest ${TEST_SOURCEF_FILES})