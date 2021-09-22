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
        "E:/Wolfgang_Aigner/Documents/5BHELS/Projekt/Code/build/bin/shader/basic_vert.vert",
        "E:/Wolfgang_Aigner/Documents/5BHELS/Projekt/Code/build/bin/shader/basic_frag.frag");

    // Rectangle vertecies.
    const Vertex2D vertecies[] = {
        {-0.75f, -0.75f}, {-0.75f, 0.75f}, {0.75f, 0.75f}, {0.75f, -0.75f}};

    // Rectangle indices.
    const ui32 indices[] = {0, 1, 2, 2, 3, 0};

    glGenVertexArrays(1, &this->vaoID);
    glBindVertexArray(this->vaoID);

    glGenBuffers(1, &this->vertexBufferID);
    glBindBuffer(GL_ARRAY_BUFFER, this->vertexBufferID);
    glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(Vertex2D), vertecies, GL_DYNAMIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex2D),
                          (void*) offsetof(Vertex2D, x));

    glGenBuffers(1, &this->indexBufferID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->indexBufferID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(ui32), indices, GL_STATIC_DRAW);
}

QuadRenderer::~QuadRenderer()
{
    this->shader->delete_shader();
    delete this->shader;
    GL::deleteBuffer(&this->vertexBufferID);
    GL::deleteBuffer(&this->indexBufferID);
    GL::deleteVAO(&this->vaoID);
}

void QuadRenderer::free()
{
    this->shader->delete_shader();
    delete this->shader;
    GL::deleteBuffer(&this->vertexBufferID);
    GL::deleteBuffer(&this->indexBufferID);
    GL::deleteVAO(&this->vaoID);
}

// TODO: Instead of allocatiog the vertecies in the vram these could just get passed in by a uniform to the GPU.
void QuadRenderer::render(Vector2D* vec, Vertex2D* vertecies) const
{
    this->shader->bind();
    ui32 offsetLocation = this->shader->getUniformLocation("in_offset");
    glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(Vertex2D), vertecies, GL_DYNAMIC_DRAW);
    GL::bindVAO(this->vaoID);
    GL::drawElements(6);
}