/*
 * Filename: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\Code\src\Components\Button.hpp
 * Path: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\Code\src\Components
 * Created Date: Thursday, September 16th 2021, 11:13:26 am
 * Author: Wolfgang Aigner
 *
 * Copyright (c) 2021 Wolfgang Aigner
 */

#ifndef __BUTTON_HPP__
#define __BUTTON_HPP__

#include "../typedefs.hpp"

class Button
{
  public:
    ui32 m_id;
    static ui32 current_id;

    Button();
    Button(const Vector2D& position, const f32& height, const f32& width, void (*onClick)(void));

    void setOnClick(void (*onClick)(void));

    Vector2D m_position;
    f32 m_height, m_width;
    void (*m_onClick)(void);

    bool m_isInitialized;
};

#endif // __BUTTON_HPP__