/*
 * Filename: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\Code\src\QuadRenderer.cpp
 * Path: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\Code\src
 * Created Date: Wednesday, September 15th 2021, 2:39:40 pm
 * Author: Wolfgang Aigner
 *
 * Copyright (c) 2021 Wolfgang Aigner
 */

#include <plog/Log.h>
#include <iostream>

#include "QuadRenderer.hpp"
#include "../GL/glFunctions.hpp"

QuadRenderer::QuadRenderer(/* args */)
{
    // For some weird reason relative paths don't seem to work.
    this->shader = new Shader(
        "E:/Wolfgang_Aigner/Documents/5BHELS/Projekt/Code/build/bin/shader/button_vert.vert",
        "E:/Wolfgang_Aigner/Documents/5BHELS/Projekt/Code/build/bin/shader/button_frag.frag");

    // Rectangle indices.
    const ui32 indices[] = {0, 1, 2, 2, 3, 0};

    // Generate a VAO.
    glGenVertexArrays(1, &this->vaoID);
    glBindVertexArray(this->vaoID);

    // Generate the vertex buffer.
    glGenBuffers(1, &this->vertexBufferID);
    glBindBuffer(GL_ARRAY_BUFFER, this->vertexBufferID);

    // Set the vertex array attribute pointer
    // (needed for the vertex shader to interprate the data in the VRAM).
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex2D),
                          (void*) offsetof(Vertex2D, x));

    // Set the index buffer and populate it.
    glGenBuffers(1, &this->indexBufferID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->indexBufferID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(ui32), indices, GL_STATIC_DRAW);
}

QuadRenderer::~QuadRenderer()
{
    // Delete the shader from the GPU.
    this->shader->delete_shader();

    // Finally free the memory from the heap.
    delete this->shader;
    GL::deleteBuffer(&this->vertexBufferID);
    GL::deleteBuffer(&this->indexBufferID);
    GL::deleteVAO(&this->vaoID);
}

void QuadRenderer::free()
{
    // Delete the shader from the GPU.
    this->shader->delete_shader();

    // Finally free the memory from the heap.
    delete this->shader;
    GL::deleteBuffer(&this->vertexBufferID);
    GL::deleteBuffer(&this->indexBufferID);
    GL::deleteVAO(&this->vaoID);
}

void QuadRenderer::render(Vertex2D* vertecies) const
{
    // Bind the ButtonShader to be used.
    this->shader->bind();

    // Not really clean.
    glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(Vertex2D), vertecies, GL_DYNAMIC_DRAW);

    // Bind the VAO of the quadRenderer.
    GL::bindVAO(this->vaoID);
    GL::drawElements(6);
}