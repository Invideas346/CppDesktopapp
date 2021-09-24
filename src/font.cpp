/*
 * Filename: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\Code\src\font.cpp
 * Path: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\Code\src
 * Created Date: Thursday, September 23rd 2021, 2:23:19 pm
 * Author: Wolfgang Aigner
 *
 * Copyright (c) 2021 Your Company
 */
#include <cstdio>
#include <GL/glew.h>

#include "font.hpp"
#include "typedefs.hpp"

void font::initFont(const std::string& filename)
{
    ui8 ttfBuffer[1 << 20];
    ui8 tmpBitmap[512 * 512];

    fread(ttfBuffer, 1 << 20, 1, fopen(filename.c_str(), "r+b"));
    stbtt_BakeFontBitmap(ttfBuffer, 0, 32.0f, tmpBitmap, 512, 512, 32, 96, cdata);

    glGenTextures(1, &m_fontTextureID);
    glBindTexture(GL_TEXTURE_2D, m_fontTextureID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, 512, 512, 0, GL_ALPHA, GL_UNSIGNED_BYTE, tmpBitmap);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
}

void font::drawString(f32 x, f32 y, const std::string& text, Shader* shader) {}