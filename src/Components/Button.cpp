/*
 * Filename: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\Code\src\Components\Button.cpp
 * Path: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\Code\src\Components
 * Created Date: Thursday, September 16th 2021, 11:13:30 am
 * Author: Wolfgang Aigner
 *
 * Copyright (c) 2021 Wolfgang Aigner
 */

#include <iostream>

#include "Button.hpp"
Button::Button() : m_isInitialized(false) {}

Button::Button(const Vector2D& position, const f32& height, const f32& width, void (*onClick)(void))
    : m_isInitialized(false)
{
    this->m_position = position;
    this->m_height = height;
    this->m_width = width;
    this->m_onClick = onClick;
}

void Button::setOnClick(void (*onClick)(void)) { this->m_onClick = onClick; }