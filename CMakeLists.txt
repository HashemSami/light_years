cmake_minimum_required(VERSION 4.0.2)

project(
  LightYears
  VERSION 1.0.0
  LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS       OFF)


# a cmake library fot fetching cpp libraries using github
include(FetchContent)
# setting a variable with value of SFML
set(SFML_LIB_NAME SFML)

FetchContent_Declare(
  ${SFML_LIB_NAME}
  GIT_REPOSITORY https://github.com/SFML/SFML
  GIT_TAG 3.0.0
  GIT_SHALLOW FALSE
  EXCLUDE_FROM_ALL
  SYSTEM
)
FetchContent_MakeAvailable(${SFML_LIB_NAME})

# setting a custom variable
set(LIGHT_YEARS_ENGINE_TARGET_NAME light_years_engine)
set(LIGHT_YEARS_GAME_TARGET_NAME light_years_game)
# adding another CMakeList located inside source folders
add_subdirectory(light_years_engine)
add_subdirectory(light_years_game)
