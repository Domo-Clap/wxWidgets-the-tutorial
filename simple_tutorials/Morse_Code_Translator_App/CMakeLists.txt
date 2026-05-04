# CMakeList.txt : CMake project for WxWdigets - Tutorials, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.15)
project(Morse_Code_Translator_App)

# Find wxWidgets
find_package(wxWidgets CONFIG REQUIRED)

# Build executable
add_executable(Morse_Code_Translator_App WIN32 main.cpp "main.h")
target_link_libraries(Morse_Code_Translator_App PRIVATE wxWidgets::wxWidgets)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Morse_Code_Translator_App PROPERTY CXX_STANDARD 20)
endif()