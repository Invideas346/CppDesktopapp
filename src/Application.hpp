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
#include "Components/Button.hpp"
#include "config.hpp"

/**
 * @brief Internally used enum.
 */
enum AppResult
{
    SUCCESS = 0,
    FAILED
};

#define APP_SUCCESS 0
#define APP_FAILED 1

/**
 * @brief Main application class.
 * This class is used as an general entry point.
 */
class Application
{
  public:
    Application(const app_config&);
    AppResult loop();

    void clearScreen() const;
    void poolForEvents(std::vector<Button*> btns);

    /* SDL window context */
    SDL_Window* m_window;
    bool m_isInitialized;
    SDL_GLContext m_glContext;

    bool closing;
    i32 m_windowHeight, m_windowWidth;
};

#endif // __APPLICATION_HPP__