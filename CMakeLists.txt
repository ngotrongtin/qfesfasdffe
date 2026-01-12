cmake_minimum_required(VERSION 3.10)
project(Tutorial VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SFML_DIR "D:/System_setup/sfml/SFML-2.6.1/lib/cmake/SFML")

find_package(SFML 2.6 COMPONENTS graphics window system audio REQUIRED)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

add_executable(Tutorial ${SOURCES})

target_include_directories(Tutorial PRIVATE
    "${PROJECT_SOURCE_DIR}/include"
)

target_link_libraries(Tutorial PRIVATE
    sfml-graphics
    sfml-window
    sfml-system
    sfml-audio
)
