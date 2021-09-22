/*
 * Filename: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\Code\src\MasterRenderer.cpp
 * Path: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\Code\src
 * Created Date: Thursday, September 16th 2021, 9:03:02 am
 * Author: Wolfgang Aigner
 *
 * Copyright (c) 2021 Wolfgang Aigner
 */

#include <iostream>

#include "MasterRenderer.hpp"
#include "../GL/glFunctions.hpp"

MasterRenderer::MasterRenderer() {}

MasterRenderer::~MasterRenderer() {}

void MasterRenderer::finishRendering()
{
    // Iterate over every button passed in to be rendered.
    for (size_t i = 0; i < this->m_buttons.size(); i++)
    {
        this->m_buttonRenderer.render(this->m_buttons[i]);
    }

    // Clear the list of to be rendered buttons.
    this->clearStack();
}

void MasterRenderer::renderButton(Button* button) { this->m_buttons.push_back(button); }

void MasterRenderer::clearStack() { this->m_buttons.clear(); }