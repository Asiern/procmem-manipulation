# Minimum required CMake version
cmake_minimum_required(VERSION 3.12)

# Project name
project(imgui_dx11)

# Add ImGui source files
set(IMGUI_SOURCES
    imgui/imgui.cpp
    imgui/imgui_demo.cpp
    imgui/imgui_draw.cpp
    imgui/imgui_widgets.cpp
    imgui/imgui_tables.cpp
    imgui/backends/imgui_impl_dx11.cpp
    imgui/backends/imgui_impl_win32.cpp
)

# Add ImGui header files
set(IMGUI_HEADERS
    imgui/imgui.h
    imgui/imgui_internal.h
    imgui/imconfig.h
    imgui/imstb_rectpack.h
    imgui/imstb_textedit.h
    imgui/imstb_truetype.h
    imgui/backends/imgui_impl_dx11.h
    imgui/backends/imgui_impl_win32.h
)

# Add library target
add_library(${PROJECT_NAME} STATIC ${IMGUI_SOURCES} ${IMGUI_HEADERS})

# Include directories
target_include_directories(imgui_dx11 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/imgui)

# Link libraries
target_link_libraries(imgui_dx11 PRIVATE d3d11)

# Set compiler flags
target_compile_definitions(imgui_dx11 PRIVATE IMGUI_IMPL_WIN32_DISABLE_GAMEPAD)

# Set output directory
set_target_properties(imgui_dx11 PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
