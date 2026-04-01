# CMakeList.txt : CMake project for WxWdigets - Tutorials, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.15)
project(ButtonExample)

# Find wxWidgets
find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

# Build executable
add_executable(ButtonExample WIN32 main.cpp)
target_link_libraries(ButtonExample ${wxWidgets_LIBRARIES})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ButtonExample PROPERTY CXX_STANDARD 20)
endif()