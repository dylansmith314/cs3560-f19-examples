cmake_minimum_required(VERSION 3.11)
project(example)

option(USE_CPP_DOTENV                   "Use cpp-dotenv" ON)
option(CMAKE_USE_OPENSSL                "Enable this on school server" OFF)
option(CMAKE_EXPORT_COMPILE_COMMANDS    "To create clangd compile_commands.json" OFF)

find_package(Git)

if(NOT Git_FOUND)
  string(CONCAT GIT_NOT_FOUND_WARNING
    "GIT was not found, CMake list will likely fail. "
    "Please make sure that GIT is inside your PATH variable")
  message(WARNING ${GIT_NOT_FOUND_WARNING})
endif()

# Base on https://medium.com/analytics-vidhya/c-dependency-management-with-cmakes-fetchcontent-4ceca4693a5d
include(FetchContent)
FetchContent_Declare(sleepy-discord
  GIT_REPOSITORY "https://github.com/yourWaifu/sleepy-discord"
  GIT_TAG "28bc72fa0c03ccb4afdf48f6410c4183597978cd")
FetchContent_Declare(cpp-dotenv
  GIT_REPOSITORY "https://github.com/adeharo9/cpp-dotenv"
  GIT_TAG "8ed6f82dd5fdd437f6c2820b37ef88103b4e8360")

FetchContent_MakeAvailable(sleepy-discord cpp-dotenv)

add_executable(bot source.cpp)

target_link_libraries(bot sleepy-discord)
target_link_libraries(bot cpp_dotenv)
