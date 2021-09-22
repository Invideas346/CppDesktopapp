/*
 * Filename: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\Code\src\Render\ButtonRenderer.cpp
 * Path: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\Code\src\Render
 * Created Date: Friday, September 17th 2021, 5:28:13 pm
 * Author: Wolfgang Aigner
 *
 * Copyright (c) 2021 Wolfgang Aigner
 */

#include <iostream>

#include "ButtonRenderer.hpp"

ButtonRenderer::ButtonRenderer(/* args */) {}

ButtonRenderer::~ButtonRenderer() {}

void ButtonRenderer::render(Button* button)
{
    /*
        1. Index bottom left corner
        2. Index top left corner
        3. Index top right corner
        4. Index bottom right corner

        2. --------  3.
        |            |
        |            |
        1. --------  4.

        Not sure if offset should get applied only in the shader or here.
    */

    // Calculate the vertecies of the to be rendered button.
    Vertex2D vertecies[4];
    vertecies[0] = {button->m_position.x, button->m_position.y};
    vertecies[1] = {button->m_position.x, button->m_position.y + button->m_height};
    vertecies[2] = {button->m_position.x + button->m_width,
                    button->m_position.y + button->m_height};
    vertecies[3] = {button->m_position.x + button->m_width, button->m_position.y};

    // Pass the vertecies to the QuadRenderer.
    m_quadRenderer.render(vertecies);
}