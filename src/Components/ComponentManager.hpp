/*
 * Filename: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\Code\src\Components\ComponentManager.hpp
 * Path: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\Code\src\Components
 * Created Date: Wednesday, September 22nd 2021, 11:07:51 am
 * Author: Wolfgang Aigner
 *
 * Copyright (c) 2021 Wolfgang Aigner
 */

#ifndef __COMPONENTMANAGER_HPP__
#define __COMPONENTMANAGER_HPP__

#include "../typedefs.hpp"
#include "Button.hpp"
#include <vector>

class ComponentManager
{
  public:
    ComponentManager();
    ~ComponentManager();

    void add_button(Button* button);
    void remove_button(Button* button);
    void clear_all_buttons();

    std::vector<Button*> m_buttons;
};

#endif // __COMPONENTMANAGER_HPP__