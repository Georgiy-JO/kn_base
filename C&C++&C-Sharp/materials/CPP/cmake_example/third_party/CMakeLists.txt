cmake_minimum_required(VERSION 3.21)
project(MatrixLib)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Source/header lists
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/matrix)

set(MATRIX_SOURCES
  matrix/matrix.cpp
)
set(MATRIX_HEADERS
  matrix/matrix_exceptions.hpp
  matrix/matrix_service.hpp
  matrix/matrix.hpp
)

# Create static library 
add_library(matrix STATIC
  ${MATRIX_SOURCES}
  ${MATRIX_HEADERS}  # optional
)

# Target compile options (scoped)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
  target_compile_options(matrix PRIVATE
    -Wall -Wextra -Wpedantic -Werror -g -D_POSIX_C_SOURCE=201706L -O0
  )
endif()

target_include_directories(matrix PUBLIC $<BUILD_INTERFACE:${INCLUDE_DIR}>)
