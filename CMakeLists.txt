cmake_minimum_required(VERSION 3.14)
project(rpl-task)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

if(FALSE)
add_executable(
  LinkedListTest
  LinkedListTest.cpp
  RplTask.cpp
  TaskLinkedList.cpp
)
target_link_libraries(
  LinkedListTest
  GTest::gtest_main
)
endif()

if(FALSE)
add_executable(
  TopologicalTest
  TopologicalSortTest.cpp
  RplTask.cpp
  TaskLinkedList.cpp
  TopologicalSort.cpp
)
target_link_libraries(
  TopologicalTest
  GTest::gtest_main
)
endif()

add_executable(
  PrecompTest
  PrecompTest.cpp
  PrecompTopSort.cpp
  #iOutputStrategyPattern.h
  #ArduinoStrategyPattern.h
)
target_link_libraries(
  PrecompTest
  GTest::gtest_main
)

add_executable(
  HelloTest
  HelloTest.cpp
)
target_link_libraries(
  HelloTest
  GTest::gtest_main
)
include(GoogleTest)
#gtest_discover_tests(LinkedListTest)
#gtest_discover_tests(TopologicalTest)
gtest_discover_tests(PrecompTest)
gtest_discover_tests(HelloTest)

