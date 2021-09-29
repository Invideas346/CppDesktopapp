/*
 * Filename: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\Code\src\GL\glFunctions.hpp
 * Path: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\Code\src\GL
 * Created Date: Thursday, September 16th 2021, 8:48:30 am
 * Author: Wolfgang Aigner
 *
 * Copyright (c) 2021 Wolfgang Aigner
 */

#ifndef __GLFUNCTIONS_HPP__
#define __GLFUNCTIONS_HPP__

#include "../typedefs.hpp"

namespace GL
{
void drawElements(ui32 indeciesCount);

void bindVAO(ui32 vaoID);

void unbindVAO();

void bindVertexBuffer(ui32 bufferID);

void unbindVertexBuffer();

void bindIndexBuffer(ui32 bufferID);

void unbindIndexBuffer();

void deleteBuffer(ui32* bufferID);

void deleteVAO(ui32* vaoID);
} // namespace GL

#endif // __GLFUNCTIONS_HPP__