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
#include "../GL/glFunctions.hpp"

ButtonRenderer::ButtonRenderer()
{
    this->m_fontRenderer = new FontRenderer(
        "./fonts/OpenSans-Regular.ttf");

    this->m_buttonShader = new ButtonShader();

    // Rectangle indices.
    const ui32 indices[] = {0, 1, 2, 2, 3, 0};

    // Generate a VAO.
    glGenVertexArrays(1, &this->m_vaoID);
    glBindVertexArray(this->m_vaoID);

    // Generate the vertex buffer.
    glGenBuffers(1, &this->m_vertexBufferID);
    glBindBuffer(GL_ARRAY_BUFFER, this->m_vertexBufferID);

    // Set the vertex array attribute pointer
    // (needed for the vertex shader to interprate the data in the VRAM).
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex2D),
                          (void*) offsetof(Vertex2D, x));

    // Set the index buffer and populate it.
    glGenBuffers(1, &this->m_indexBufferID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_indexBufferID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(ui32), indices, GL_STATIC_DRAW);
    glBindVertexArray(0);
}

ButtonRenderer::~ButtonRenderer()
{
    // Delete the shader from the GPU.
    this->m_buttonShader->delete_shader();

    // Finally free the memory from the heap.
    delete this->m_buttonShader;
    GL::deleteBuffer(&this->m_vertexBufferID);
    GL::deleteBuffer(&this->m_indexBufferID);
    GL::deleteVAO(&this->m_vaoID);
}

void ButtonRenderer::free()
{
    // Delete the shader from the GPU.
    this->m_buttonShader->delete_shader();

    // Finally free the memory from the heap.
    delete this->m_buttonShader;
    GL::deleteBuffer(&this->m_vertexBufferID);
    GL::deleteBuffer(&this->m_indexBufferID);
    GL::deleteVAO(&this->m_vaoID);
}

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

    // Bind the ButtonShader to be used.
    this->m_buttonShader->bind();

    // Bind the VAO of the quadRenderer.
    GL::bindVAO(this->m_vaoID);
    GL::bindVertexBuffer(this->m_vertexBufferID);
    // Not really clean.
    glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(Vertex2D), vertecies, GL_DYNAMIC_DRAW);
    GL::drawElements(6);
    GL::unbindVertexBuffer();
    GL::unbindVAO();
    m_fontRenderer->render(((button->m_position.x + 1.0f) + (button->m_width / 2)) * 640.0f,
                            (1.0f - (button->m_position.y + button->m_height / 2)) * 400.0f,
                            button->label.c_str());
}