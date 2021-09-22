/*
 * Filename: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\Code\src\Render\TextRenderer.hpp
 * Path: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\Code\src\Render
 * Created Date: Wednesday, September 22nd 2021, 1:29:22 pm
 * Author: Wolfgang Aigner
 *
 * Copyright (c) 2021 Your Company
 */

#ifndef __TEXTRENDERER_HPP__
#define __TEXTRENDERER_HPP__

#include <map>
#include <glm/glm.hpp>

#include "../Shader/Shader.hpp"

/// Holds all state information relevant to a character as loaded using FreeType
struct Character
{
    unsigned int TextureID; // ID handle of the glyph texture
    glm::ivec2 Size;        // size of glyph
    glm::ivec2 Bearing;     // offset from baseline to left/top of glyph
    unsigned int Advance;   // horizontal offset to advance to next glyph
};

// A renderer class for rendering text displayed by a font loaded using the
// FreeType library. A single font is loaded, processed into a list of Character
// items for later rendering.
/*class TextRenderer
{
  public:
    // holds a list of pre-compiled Characters
    std::map<char, Character> Characters;
    // shader used for text rendering
    Shader* TextShader;
    // constructor
    TextRenderer(unsigned int width, unsigned int height);
    ~TextRenderer();
    // pre-compiles a list of characters from the given font
    void Load(std::string font, unsigned int fontSize);
    // renders a string of text using the precompiled list of characters
    void RenderText(std::string text, float x, float y, float scale,
                    glm::vec3 color = glm::vec3(1.0f));

  private:
    // render state
    unsigned int VAO, VBO;
};*/

#endif // __TEXTRENDERER_HPP__