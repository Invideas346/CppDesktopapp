/*
 * Filename: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\Code\src\Components\ComponentManager.cpp
 * Path: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\Code\src\Components
 * Created Date: Wednesday, September 22nd 2021, 11:08:31 am
 * Author: Wolfgang Aigner
 *
 * Copyright (c) 2021 Your Company
 */

#include "ComponentManager.hpp"

ComponentManager::ComponentManager() {}

ComponentManager::~ComponentManager() {}

void ComponentManager::add_button(Button* button) { this->m_buttons.push_back(button); }

void ComponentManager::remove_button(Button* button)
{
    for (ui32 i = 0; i < this->m_buttons.size(); i++)
    {
        if (this->m_buttons[i] == button)
        {
            this->m_buttons.erase(this->m_buttons.begin() + i);
        }
    }
}

void ComponentManager::clear_all_buttons() { this->m_buttons.clear(); }