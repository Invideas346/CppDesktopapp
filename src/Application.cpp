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
#include "Render/MasterRenderer.hpp"
#include "Components/Button.hpp"

Application::Application(const app_config& config) : m_isInitialized(false), closing(false)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_GL_SetSwapInterval(0);
    this->m_window = SDL_CreateWindow(
        config.name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, config.window_width,
        config.window_height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
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

void Application::clearScreen() const
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Application::poolForEvents()
{
    SDL_Event e;
    SDL_PollEvent(&e);

    // Poll for Window events.
    switch (e.type)
    {
    case SDL_QUIT:
        PLOGD << "Program quit after %i " << e.quit.timestamp << " ticks";
        SDL_Log("Program quit after %i ticks", e.quit.timestamp);
        this->closing = true;
        break;

    case SDL_WINDOWEVENT:
        if (e.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
        {
            glViewport(0, 0, e.window.data1, e.window.data2);
        }
        break;
    }

    // Poll for mouse events.
    i32 mouse_xpos, mouse_ypos;
    ui32 mouse_curser = SDL_GetMouseState(&mouse_xpos, &mouse_ypos);
}

void testBtnClick() { std::cout << "Hallo" << std::endl; }

AppResult Application::loop()
{
    // Was the initialization successful?
    if (!this->m_isInitialized)
    {
        return FAILED;
    }
    // Was the initialization successful?

    MasterRenderer masterRenderer;
    Vector2D vec = {0.3f, 0.0f};
    Vector2D btnpos = {0.0f, 0.0f};

    Button btn(btnpos, 200, 400);
    btn.setOnClick(testBtnClick);
    btn.m_onClick();

    // Main program loop.
    while (!this->closing)
    {
        this->clearScreen();
        this->poolForEvents();
        masterRenderer.addRec(&vec);
        masterRenderer.finishRendering();
        SDL_GL_SwapWindow(this->m_window);
    }
    return SUCCESS;
}