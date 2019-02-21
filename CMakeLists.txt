cmake_minimum_required(VERSION 3.12.2)

project (hello)

set (CMAKE_CXX_STANDARD 11)

include_directories(
  /usr/local/Cellar/nlohmann_json/3.4.0/include
  )

add_executable(hello src/hello.cpp)

