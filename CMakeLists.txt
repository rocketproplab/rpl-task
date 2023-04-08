cmake_minimum_required(VERSION 3.14)
project(rpl-task)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 11)

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

add_executable(
  PrecompTesting
  PrecompTest.cpp
  PrecompTopSort.cpp
  TestTaskFolder
)
target_link_libraries(
  PrecompTesting
  GTest::gtest_main
)
include(GoogleTest)
#gtest_discover_tests(LinkedListTest)
#gtest_discover_tests(TopologicalTest)
gtest_discover_tests(PrecompTesting)
#gtest_discover_tests(HelloTest)

