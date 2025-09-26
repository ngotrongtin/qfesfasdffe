# CMakeLists.txt
# ✅ Đặt phiên bản tối thiểu của CMake
cmake_minimum_required(VERSION 3.10)
# ✅ Đặt tên dự án và phiên bản
project(Tutorial VERSION 1.0)
# ✅ Chỉ định chuẩn C++ cần dùng
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(SFML_DIR "D:/System_setup/sfml/SFML-2.6.1")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
configure_file(TutorialConfig.h.in TutorialConfig.h)


file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)
# ✅ Tạo file thực thi
add_executable(Tutorial ${SOURCES})

# ✅ Include thư mục SFML
target_include_directories(Tutorial PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}/include"
    ${SFML_DIR}/include
)

# ✅ Liên kết thư viện từ lib/
link_directories(${SFML_DIR}/lib)

# ✅ Link thư viện .lib (dùng dạng động - không thêm `-s`)
target_link_libraries(Tutorial
    ${SFML_DIR}/lib/libsfml-graphics.a
    ${SFML_DIR}/lib/libsfml-window.a
    ${SFML_DIR}/lib/libsfml-system.a
    ${SFML_DIR}/lib/libsfml-audio.a
)