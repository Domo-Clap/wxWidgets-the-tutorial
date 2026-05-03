# CMakeList.txt : CMake project for WxWdigets - Tutorials, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.15)
project(Calculator_App_Example)

# Find wxWidgets
find_package(wxWidgets CONFIG REQUIRED)

# Build executable
add_executable(Calculator_App_Example WIN32 main.cpp "main.h")
target_link_libraries(Calculator_App_Example PRIVATE wxWidgets::wxWidgets)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Calculator_App_Example PROPERTY CXX_STANDARD 20)
endif()