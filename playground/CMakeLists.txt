cmake_minimum_required(VERSION 3.12)
project(Playground VERSION 0.0.1 LANGUAGES CXX)

# Add your source files here
set(SOURCES
    src/main.cpp
)

include_directories(include)
add_subdirectory(lib)

set(HEADERS
)

# Add the executable target
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_link_libraries(${PROJECT_NAME} PRIVATE imgui_dx11)