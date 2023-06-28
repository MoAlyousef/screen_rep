cmake_minimum_required(VERSION 3.15)
project(screen_rep)

include(FetchContent)

set(FLTK_BUILD_TEST OFF CACHE BOOL " " FORCE)

FetchContent_Declare(
    fltk
    GIT_REPOSITORY https://github.com/fltk/fltk
    GIT_SHALLOW True
)

FetchContent_MakeAvailable(fltk)

find_package(Threads REQUIRED)
add_executable(main main.cpp)
target_include_directories(main PRIVATE ${fltk_SOURCE_DIR} ${fltk_BINARY_DIR})
target_link_libraries(main PRIVATE fltk Threads::Threads)