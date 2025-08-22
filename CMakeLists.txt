cmake_minimum_required(VERSION 4.0.2)

project(
  LightYears
  VERSION 1.0.0
  LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS       OFF)


add_executable(
  LightYears
  ${CMAKE_CURRENT_SOURCE_DIR}/light_years/src/main.cpp
)