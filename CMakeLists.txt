cmake_minimum_required(VERSION 3.13)

set(PROJECT_NAME c-logger)
project(${PROJECT_NAME} VERSION 0.1.0 LANGUAGES C CXX)

# Specify C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add main project
add_subdirectory(${PROJECT_NAME})