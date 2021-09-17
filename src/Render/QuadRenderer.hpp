/*
 * Filename: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\Code\src\shader\QuadRenderer.hpp
 * Path: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\Code\src\shader
 * Created Date: Wednesday, September 15th 2021, 2:39:05 pm
 * Author: Wolfgang Aigner
 *
 * Copyright (c) 2021 Wolfgang Aigner
 */

#ifndef __QUADRENDERER_HPP__
#define __QUADRENDERER_HPP__

#include "../typedefs.hpp"
#include "../Shader/Shader.hpp"

class QuadRenderer
{
  public:
    QuadRenderer(/* args */);
    ~QuadRenderer();

    void free();
    void render(Vector2D* vec) const;

    Shader* shader;
    ui32 vaoID;
    ui32 indexBufferID;
    ui32 vertexBufferID;
};

#endif // __QUADRENDERER_HPP__