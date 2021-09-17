/*
 * Filename: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\Code\src\MasterRenderer.cpp
 * Path: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\Code\src
 * Created Date: Thursday, September 16th 2021, 9:03:02 am
 * Author: Wolfgang Aigner
 *
 * Copyright (c) 2021 Wolfgang Aigner
 */

#include "MasterRenderer.hpp"
#include "../GL/glFunctions.hpp"

MasterRenderer::MasterRenderer() {}

MasterRenderer::~MasterRenderer() {}

void MasterRenderer::finishRendering()
{
    for (size_t i = 0; i < this->vecs.size(); i++)
    {
        this->quadRenderer.render(&this->vecs[i]);
    }
}

void MasterRenderer::addRec(Vector2D* vec) { this->vecs.push_back(*vec); }
