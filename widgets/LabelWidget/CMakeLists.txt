# CMakeList.txt : CMake project for WxWdigets - Tutorials, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
project(LabelExample)

# Find wxWidgets
find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

# Build executable
add_executable(LabelExample WIN32 main.cpp)
target_link_libraries(LabelExample ${wxWidgets_LIBRARIES})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET LabelExample PROPERTY CXX_STANDARD 20)
endif()