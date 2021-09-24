/*
 * Filename: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\Code\src\font.hpp
 * Path: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\Code\src
 * Created Date: Thursday, September 23rd 2021, 2:20:12 pm
 * Author: Wolfgang Aigner
 *
 * Copyright (c) 2021 Your Company
 */
#ifndef __FONT_HPP__
#define __FONT_HPP__

#define STB_TRUETYPE_IMPLEMENTATION
#include <stb_truetype.h>
#include <glm/glm.hpp>

#include "Shader/Shader.hpp"

#include <string>

struct fontVertex
{
    glm::vec2 position;
    glm::vec2 texCoords;
};

struct font
{
  public:
    void initFont(const std::string& filename);

    void drawString(f32 x, f32 y, const std::string& text, Shader* shader);

    stbtt_bakedchar cdata[96];
    ui32 m_fontTextureID;
    ui32 m_vaoID;
    ui32 m_vertexBufferID;
    fontVertex* m_fontVertexBuffer = 0;
    ui32 m_fontVertexBufferCapacity;
};

#endif // __FONT_HPP__