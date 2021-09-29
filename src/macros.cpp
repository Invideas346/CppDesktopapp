/*
 * Filename: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\Code\src\macros.cpp
 * Path: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\Code\src
 * Created Date: Wednesday, September 29th 2021, 8:21:02 am
 * Author: Wolfgang Aigner
 *
 * Copyright (c) 2021 Your Company
 */

#include <GL/glew.h>

#include "macros.hpp"

void _GLGetError(const char* file, int line, const char* call)
{
    while (GLenum error = glGetError())
    {
        PLOGD << "[OpenGL Error] " << glewGetErrorString(error) << " in " << file << ":" << line
              << " Call: " << call << std::endl;
    }
}