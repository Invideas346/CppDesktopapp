cmake_minimum_required(VERSION 3.21.0)

#Source filese to be compiled
set(SOURCE_FILES
    main.cpp
    Application.cpp
    macros.cpp
    Shader/Shader.cpp
    Shader/ButtonShader.cpp
    Shader/FontShader.cpp
    Render/QuadRenderer.cpp
    Render/MasterRenderer.cpp
    Render/ButtonRenderer.cpp
    Render/TextRenderer.cpp
    Render/ButtonRenderer.cpp
    Components/ComponentManager.cpp
    GL/glFunctions.cpp
    Components/Button.cpp
)

# Shader
configure_file("shader_programs/button_frag.frag" ${CMAKE_BINARY_DIR}/bin/shader/button_frag.frag COPYONLY)
configure_file("shader_programs/button_vert.vert" ${CMAKE_BINARY_DIR}/bin/shader/button_vert.vert COPYONLY)
configure_file("shader_programs/font_frag.frag" ${CMAKE_BINARY_DIR}/bin/shader/font_frag.frag COPYONLY)
configure_file("shader_programs/font_vert.vert" ${CMAKE_BINARY_DIR}/bin/shader/font_vert.vert COPYONLY)

#Fonts
configure_file("fonts/OpenSans-Regular.ttf" ${CMAKE_BINARY_DIR}/bin/fonts/OpenSans-Regular.ttf COPYONLY)

#Config
configure_file("config/config.txt" ${CMAKE_BINARY_DIR}/bin/config/config.txt COPYONLY)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})