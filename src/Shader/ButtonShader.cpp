/*
 * Filename: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\Code\src\Shader\ButtonShader.cpp
 * Path: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\Code\src\Shader
 * Created Date: Thursday, September 23rd 2021, 12:33:19 pm
 * Author: Wolfgang Aigner
 *
 * Copyright (c) 2021 Your Company
 */
#include "ButtonShader.hpp"

ButtonShader::ButtonShader()
    : Shader("./shader/button_vert.vert",
             "./shader/button_frag.frag")
{
}

ButtonShader::~ButtonShader() {}