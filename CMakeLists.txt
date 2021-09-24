cmake_minimum_required(VERSION 3.21.0)
project(DesktopApp)

#Set the output of the binaries to the bin folder.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

#Definition to enable built in debug logs.
add_definitions(-D_DEBUG_)

#Definition to enable build in release commands.
#add_definitions(-D_RELEASE_)

#Add the src subdirectory.
add_subdirectory(src)

#Add compiler warnings.
if ( CMAKE_COMPILER_IS_GNUCC )
    target_compile_options(DesktopApp PRIVATE "-Wall")
endif()
if ( MSVC )
    target_compile_options(DesktopApp PRIVATE "/W4")
endif()

#Add the external libaries.
add_subdirectory(external/glew/build/cmake external/glew)
add_subdirectory(external/plog external/plog)
add_subdirectory(external/glm external/glm)
add_subdirectory(external/sdl2)
#add_subdirectory(external/freetype external/freetype)

target_include_directories(${PROJECT_NAME}
    PUBLIC external/glew/include
    PUBLIC external/sdl/include
    PUBLIC external/plog/include
    PUBLIC external/glm
    PUBLIC external/stb
    #PUBLIC external/freetype/include
)

target_link_directories(${PROJECT_NAME}
    PUBLIC external/glew/src
    PUBLIC external/sdl
    PUBLIC external/glm
    #PUBLIC external/freetype
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE glew
    PRIVATE SDL2
    PRIVATE glm_shared
    #PRIVATE freetype
)


#Add logger library.
target_include_directories(${PROJECT_NAME}
    PUBLIC external/plog/include
)