cmake_minimum_required(VERSION 3.11)
project(example)

find_package(Git)

if(NOT Git_FOUND)
  string(CONCAT GIT_NOT_FOUND_WARNING
    "GIT was not found, CMake list will likely fail. "
    "Please make sure that GIT is inside your PATH variable")
  message(WARNING ${GIT_NOT_FOUND_WARNING})
endif()

# Base on https://medium.com/analytics-vidhya/c-dependency-management-with-cmakes-fetchcontent-4ceca4693a5d
include(FetchContent)
FetchContent_Declare(aegis-cpp
  GIT_REPOSITORY "https://github.com/krerkkiat/aegis.cpp.git"
  GIT_TAG "a4cc7721f0e71182431b4172254a19209279de06")

FetchContent_MakeAvailable(aegis-cpp)

add_executable(bot app.cpp)
set_property(TARGET bot PROPERTY CXX_STANDARD 14)
set_property(TARGET bot PROPERTY CXX_STANDARD_REQUIRED ON)
target_link_libraries(bot PRIVATE Aegis::aegis)

if(MSVC)
    add_compile_options("/W3" "$<$<CONFIG:RELEASE>:/O2>")
endif()

target_include_directories(bot
	PUBLIC
	$<INSTALL_INTERFACE:include>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
