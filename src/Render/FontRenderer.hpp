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

#include <cstdio>
#include <GL/glew.h>
#include <string.h>
#include <stb_truetype.h>
#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "../macros.hpp"
#include "../typedefs.hpp"
#include "../Shader/FontShader.hpp"

struct FontVertex
{
    glm::vec2 position;
    glm::vec2 texCoords;
};

struct FontRenderer
{
    FontRenderer(const char* filename)
    {
        fontShader = new FontShader();
        ui8 ttfBuffer[1 << 20];
        ui8 tmpBitmap[512 * 512];

        fread(ttfBuffer, 1, 1 << 20, fopen(filename, "rb"));
        stbtt_BakeFontBitmap(ttfBuffer, 0, 32.0f, tmpBitmap, 512, 512, 32, 96, cdata);

        GLCALL(glGenTextures(1, &fontTexture));
        GLCALL(glBindTexture(GL_TEXTURE_2D, fontTexture));
        GLCALL(glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, 512, 512, 0, GL_ALPHA, GL_UNSIGNED_BYTE,
                            tmpBitmap));
        GLCALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
        GLCALL(glBindTexture(GL_TEXTURE_2D, 0));

        GLCALL(glGenVertexArrays(1, &fontVao));
        GLCALL(glBindVertexArray(fontVao));
        GLCALL(glGenBuffers(1, &fontVertexBufferId));
        GLCALL(glBindBuffer(GL_ARRAY_BUFFER, fontVertexBufferId));
        fontVertexBufferCapacity = 20;
        fontVertexBufferData = new FontVertex[fontVertexBufferCapacity * 6];
        GLCALL(glBufferData(GL_ARRAY_BUFFER, sizeof(FontVertex) * 6 * fontVertexBufferCapacity, 0,
                            GL_DYNAMIC_DRAW));
        GLCALL(glEnableVertexAttribArray(0));
        GLCALL(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(FontVertex), 0));
        GLCALL(glEnableVertexAttribArray(1));
        GLCALL(glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(FontVertex),
                                     (const void*) offsetof(FontVertex, texCoords)));
        GLCALL(glBindVertexArray(0));
    }

    ~FontRenderer()
    {
        if (fontVertexBufferData)
        {
            delete[] fontVertexBufferData;
        }
        if (fontShader)
        {
            delete fontShader;
        }
    }

    void render(float x, float y, const char* text)
    {
        fontShader->bind();
        glBindVertexArray(fontVao);
        glBindBuffer(GL_ARRAY_BUFFER, fontVertexBufferId);

        ui32 len = strlen(text);
        if (fontVertexBufferCapacity < len)
        {
            fontVertexBufferCapacity = len;
            glBufferData(GL_ARRAY_BUFFER, sizeof(FontVertex) * 6 * fontVertexBufferCapacity, 0,
                         GL_DYNAMIC_DRAW);
            delete[] fontVertexBufferData;
            fontVertexBufferData = new FontVertex[fontVertexBufferCapacity * 6];
        }

        GLCALL(glActiveTexture(GL_TEXTURE0));
        GLCALL(glBindTexture(GL_TEXTURE_2D, fontTexture));
        GLCALL(glUniform1i(glGetUniformLocation(fontShader->getProgram(), "u_texture"), 0));

        glm::mat4 ortho = glm::ortho(0.0f, (float) 1280, (float) 800, 0.0f);
        GLCALL(glUniformMatrix4fv(glGetUniformLocation(fontShader->getProgram(), "u_modelViewProj"),
                                  1, GL_FALSE, &ortho[0][0]));

        FontVertex* vData = fontVertexBufferData;
        ui32 numVertices = 0;
        while (*text)
        {
            if (*text >= 32 && *text < 128)
            {
                stbtt_aligned_quad q;
                stbtt_GetBakedQuad(cdata, 512, 512, *text - 32, &x, &y, &q, 1);

                vData[0].position = glm::vec2(q.x0, q.y0);
                vData[0].texCoords = glm::vec2(q.s0, q.t0);
                vData[1].position = glm::vec2(q.x1, q.y0);
                vData[1].texCoords = glm::vec2(q.s1, q.t0);
                vData[2].position = glm::vec2(q.x1, q.y1);
                vData[2].texCoords = glm::vec2(q.s1, q.t1);
                vData[3].position = glm::vec2(q.x0, q.y1);
                vData[3].texCoords = glm::vec2(q.s0, q.t1);
                vData[4].position = glm::vec2(q.x0, q.y0);
                vData[4].texCoords = glm::vec2(q.s0, q.t0);
                vData[5].position = glm::vec2(q.x1, q.y1);
                vData[5].texCoords = glm::vec2(q.s1, q.t1);

                vData += 6;
                numVertices += 6;
            }
            ++text;
        }

        GLCALL(glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(FontVertex) * numVertices,
                               fontVertexBufferData));
        GLCALL(glDrawArrays(GL_TRIANGLES, 0, numVertices));
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

  private:
    stbtt_bakedchar cdata[96];
    GLuint fontTexture;
    GLuint fontVao;
    GLuint fontVertexBufferId;
    FontVertex* fontVertexBufferData = 0;
    ui32 fontVertexBufferCapacity;
    FontShader* fontShader;
};

#endif // __FONT_HPP__