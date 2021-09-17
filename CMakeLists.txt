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

target_include_directories(${PROJECT_NAME}
    PUBLIC external/glew/include
    PUBLIC external/sdl/include
    PUBLIC external/plog/include
)

target_link_directories(${PROJECT_NAME}
    PUBLIC external/glew/src
    PUBLIC external/sdl
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE glew
    PRIVATE SDL2
)


#Add logger library.
target_include_directories(${PROJECT_NAME}
    PUBLIC external/plog/include
)