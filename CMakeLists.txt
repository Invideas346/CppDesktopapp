cmake_minimum_required(VERSION 3.21.0)
project(DesktopApp)

#Set the output of the binaries to the bin folder.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


#Add the src subdirectory.
add_subdirectory(src)


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