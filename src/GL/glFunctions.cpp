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

void GL::unbindVAO() { glBindVertexArray(0); }

void GL::bindVertexBuffer(ui32 bufferID) { glBindBuffer(GL_ARRAY_BUFFER, bufferID); }

void GL::unbindVertexBuffer() { glBindBuffer(GL_ARRAY_BUFFER, 0); }

void GL::bindIndexBuffer(ui32 bufferID) { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferID); }

void GL::unbindIndexBuffer() { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }

void GL::deleteBuffer(ui32* bufferID) { glDeleteBuffers(1, bufferID); }

void GL::deleteVAO(ui32* vaoID) { glDeleteVertexArrays(1, vaoID); }