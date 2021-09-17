/*
 * Filename: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\Code\src\Shader.hpp
 * Path: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\Code\src
 * Created Date: Wednesday, September 15th 2021, 8:17:24 am
 * Author: Wolfgang Aigner
 *
 * Copyright (c) 2021 Wolfgang Aigner
 */

#ifndef __SHADER_HPP__
#define __SHADER_HPP__

#include <GL/glew.h>
#include <string>

#include "../typedefs.hpp"

class Shader
{
  public:
    Shader(const char* vertexShader, const char* fragmentShader);
    ~Shader();
    void delete_shader();

    void bind() const;

    ui32 getProgram() const;
    ui32 getUniformLocation(const char* name) const;

  private:
    ui32 m_program;

    ui32 compile(const char* shaderSource, GLenum type);
    std::string parse(const char* filename);
    ui32 createShader(const char* vertexShaderFilename, const char* fragmentShaderFilename);
};

#endif // __SHADER_HPP__