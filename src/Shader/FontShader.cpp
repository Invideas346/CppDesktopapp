/*
 * Filename: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\Code\src\Shader\FontShader.cpp
 * Path: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\Code\src\Shader
 * Created Date: Wednesday, September 29th 2021, 1:52:38 pm
 * Author: Wolfgang Aigner
 *
 * Copyright (c) 2021 Your Company
 */

#include "FontShader.hpp"

FontShader::FontShader()
    : Shader("./shader/font_vert.vert",
             "./shader/font_frag.frag")
{
}

FontShader::~FontShader() {}
