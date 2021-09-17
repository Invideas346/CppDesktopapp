cmake_minimum_required(VERSION 3.21.0)

set(SOURCE_FILES
    main.cpp
    Application.cpp
    Shader/Shader.cpp
    Render/QuadRenderer.cpp
    Render/MasterRenderer.cpp
    GL/glFunctions.cpp
    Components/Button.cpp
)

configure_file("shader_prgrams/basic_frag.frag" ${CMAKE_BINARY_DIR}/bin/shader/basic_frag.frag COPYONLY)
configure_file("shader_prgrams/basic_vert.vert" ${CMAKE_BINARY_DIR}/bin/shader/basic_vert.vert COPYONLY)
configure_file("config/config.txt" ${CMAKE_BINARY_DIR}/bin/config/config.txt COPYONLY)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})