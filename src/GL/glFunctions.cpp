/*
 * Filename: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\Code\src\GL\glFunctions.cpp
 * Path: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\Code\src\GL
 * Created Date: Thursday, September 16th 2021, 8:48:35 am
 * Author: Wolfgang Aigner
 *
 * Copyright (c) 2021 Wolfgang Aigner
 */

#include <GL/glew.h>

#include "glFunctions.hpp"

void GL::drawElements(ui32 indeciesCount)
{
    glDrawElements(GL_TRIANGLES, indeciesCount, GL_UNSIGNED_INT, (const void*) 0);
}

void GL::bindVAO(ui32 vaoID) { glBindVertexArray(vaoID); }

void GL::deleteBuffer(ui32* bufferID) { glDeleteBuffers(1, bufferID); }

void GL::deleteVAO(ui32* vaoID) { glDeleteVertexArrays(1, vaoID); }