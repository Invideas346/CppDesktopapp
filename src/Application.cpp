/*
 * Filename: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\src\Application.cpp
 * Path: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\src
 * Created Date: Monday, September 13th 2021, 9:18:46 pm
 * Author: Wolfgang Aigner
 *
 * Copyright (c) 2021 Wolfgang Aigner
 */

#include <plog/Log.h>

#include "Application.hpp"

Application::Application(std::string name, ui32 height, ui32 width) : m_isInitialized(false)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_GL_SetSwapInterval(0);
    this->m_window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                      width, height, SDL_WINDOW_OPENGL);
    this->m_glContext = SDL_GL_CreateContext(this->m_window);

    // Can glew get initalized?
    if (glewInit())
    {
        PLOGD << "Glew initalization failed";
        return;
    }
    // Can glew get initalized?

    // Was the window created successfully?
    if (this->m_window == NULL)
    {
        PLOGD << "Window initalization failed";
        return;
    }
    // Was the window created successfully?

    this->m_isInitialized = true;
    PLOGD << "App initalized";
}

AppResult Application::loop()
{
    // Was the initialization successful?
    if (!this->m_isInitialized)
    {
        return FAILED;
    }
    // Was the initialization successful?

    while (true)
    {
        SDL_Event e;
        SDL_PollEvent(&e);
        if (e.type == SDL_QUIT)
        {
            PLOGD << "Program quit after %i " << e.quit.timestamp << " ticks";
            SDL_Log("Program quit after %i ticks", e.quit.timestamp);
            break;
        }
    }
    return SUCCESS;
}