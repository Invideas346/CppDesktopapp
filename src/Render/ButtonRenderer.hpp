/*
 * Filename: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\Code\src\Render\ButtonRenderer.hpp
 * Path: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\Code\src\Render
 * Created Date: Friday, September 17th 2021, 5:28:07 pm
 * Author: Wolfgang Aigner
 *
 * Copyright (c) 2021 Wolfgang Aigner
 */

#ifndef __BUTTONRENDERER_HPP__
#define __BUTTONRENDERER_HPP__

#include "QuadRenderer.hpp"
#include "../Shader/ButtonShader.hpp"
#include "../Components/Button.hpp"

class ButtonRenderer
{
  public:
    ButtonRenderer();
    ~ButtonRenderer();

    void free();
    void render(Button* button);

    ui32 m_vaoID, m_vertexBufferID, m_indexBufferID;

    ButtonShader* m_buttonShader;
    QuadRenderer m_quadRenderer;
};

#endif // __BUTTONRENDERER_HPP__