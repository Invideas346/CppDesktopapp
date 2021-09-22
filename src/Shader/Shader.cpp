/*
 * Filename: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\Code\src\Shader.cpp
 * Path: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\Code\src
 * Created Date: Wednesday, September 15th 2021, 8:17:57 am
 * Author: Wolfgang Aigner
 *
 * Copyright (c) 2021 Wolfgang Aigner
 */

#include <plog/Log.h>

#include "Shader.hpp"
#include "../macros.hpp"

Shader::Shader(const char* vertexShader, const char* fragmentShader)
{
    m_program = createShader(vertexShader, fragmentShader);
}

Shader::~Shader() { glDeleteProgram(m_program); }

void Shader::delete_shader() { glDeleteProgram(m_program); }

void Shader::bind() const { glUseProgram(m_program); }

ui32 Shader::getProgram() const { return m_program; }

ui32 Shader::getUniformLocation(const char* name) const
{
    return glGetUniformLocation(this->m_program, name);
}

ui32 Shader::compile(const char* shaderSource, GLenum type)
{
    uint32_t id = glCreateShader(type);
    glShaderSource(id, 1, &shaderSource, 0);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result != GL_TRUE)
    {
        int length = 0;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = new char[length];
        glGetShaderInfoLog(id, length, &length, message);
        DEBUG_LOG("Shader compilation error: " << message);
        delete[] message;
        return 0;
    }
    return id;
}

std::string Shader::parse(const char* filename)
{
    FILE* file;
    file = fopen(filename, "rb");

    // Was the file found?
    if (file == NULL)
    {
        DEBUG_LOG("FILE: " << filename << " Filename not found");
        return NULL;
    }
    // Was the file found?

    std::string contents;

    // How big the file to be read?
    fseek(file, 0, SEEK_END);
    size_t filesize = ftell(file);
    rewind(file);
    // How big the file to be read?

    // Resize the std::string to the size of the to be read file.
    contents.resize(filesize);
    fread(&contents[0], 1, filesize, file);
    fclose(file);

    return contents;
}

ui32 Shader::createShader(const char* vertexShaderFilename, const char* fragmentShaderFilename)
{
    std::string vertexShaderSource = parse(vertexShaderFilename);
    std::string fragmentShaderSource = parse(fragmentShaderFilename);

    uint32_t program = glCreateProgram();
    uint32_t vs = compile(vertexShaderSource.c_str(), GL_VERTEX_SHADER);
    uint32_t fs = compile(fragmentShaderSource.c_str(), GL_FRAGMENT_SHADER);
    DEBUG_LOG("Shader compilation successful");

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    DEBUG_LOG("Shader implementation successful");

#ifdef _RELEASE_
    glDetachShader(program, vs);
    glDetachShader(program, fs);

    glDeleteShader(vs);
    glDeleteShader(fs);
#endif //  _RELEASE_

    return program;
}
