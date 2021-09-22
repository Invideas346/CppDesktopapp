/*
 * Filename: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\Code\src\MasterRenderer.hpp
 * Path: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\Code\src
 * Created Date: Thursday, September 16th 2021, 9:03:09 am
 * Author: Wolfgang Aigner
 *
 * Copyright (c) 2021 Wolfgang Aigner
 */

#ifndef __MASTERRENDERER_HPP__
#define __MASTERRENDERER_HPP__

#include <vector>

#include "../Components/Components.hpp"
#include "QuadRenderer.hpp"
#include "ButtonRenderer.hpp"

class MasterRenderer
{
  public:
    MasterRenderer();
    ~MasterRenderer();

    void finishRendering();
    void renderButton(Button* button);

    void clearStack();

    ButtonRenderer m_buttonRenderer;
    std::vector<Button*> m_buttons;
};

#endif // __MASTERRENDERER_HPP__