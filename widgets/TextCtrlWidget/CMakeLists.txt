# CMakeList.txt : CMake project for WxWdigets - Tutorials, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.15)
project(TextCtrlExample)

# Find wxWidgets
find_package(wxWidgets CONFIG REQUIRED)

# Build executable
add_executable(TextCtrlExample WIN32 main.cpp)
target_link_libraries(TextCtrlExample PRIVATE wxWidgets::wxWidgets)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET TextCtrlExample PROPERTY CXX_STANDARD 20)
endif()