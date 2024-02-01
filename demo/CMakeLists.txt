cmake_minimum_required(VERSION 3.12)
project(DEMO LANGUAGES CXX)

# Add your source files here
set(SOURCES
    src/main.cpp
    src/mem.cpp
    src/proc.cpp
)

# Add your header files here
set(HEADERS
    include/mem.hpp
    include/proc.hpp
)

# Add the executable target
add_executable(${PROJECT_NAME} ${SOURCES})

# Include any directories containing header files
target_include_directories(${PROJECT_NAME} PRIVATE include) 
