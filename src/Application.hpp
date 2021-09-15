/*
 * Filename: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\src\Application.hpp
 * Path: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\src
 * Created Date: Monday, September 13th 2021, 9:17:43 pm
 * Author: Wolfgang Aigner
 *
 * Copyright (c) 2021 Wolfgang Aigner
 */

#ifndef __APPLICATION_HPP__
#define __APPLICATION_HPP__

#include <string>
#include <SDL2/SDL.h>
#define GLEW_STATIC
#include <GL/glew.h>

#include "typedefs.hpp"

enum AppResult
{
    SUCCESS = 0,
    FAILED
};

#define APP_SUCCESS 0
#define APP_FAILED 1

class Application
{
  public:
    Application(std::string name, ui32 height, ui32 width);
    AppResult loop();

    SDL_Window* m_window;
    bool m_isInitialized;
    SDL_GLContext m_glContext;
};

#endif // __APPLICATION_HPP__