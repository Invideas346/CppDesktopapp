/*
 * Filename: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\src\Application.cpp
 * Path: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\src
 * Created Date: Monday, September 13th 2021, 9:18:46 pm
 * Author: Wolfgang Aigner
 *
 * Copyright (c) 2021 Wolfgang Aigner
 */

#include <plog/Log.h>
#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Application.hpp"
#include "Render/MasterRenderer.hpp"
#include "Components/Components.hpp"
#include "macros.hpp"

Application::Application(const app_config& config) : m_isInitialized(false), closing(false)
{
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_GL_SetSwapInterval(0);
    this->m_window = SDL_CreateWindow(
        config.name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, config.window_width,
        config.window_height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    this->m_windowHeight = config.window_height;
    this->m_windowWidth = config.window_width;
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

void buttonIntersect(f32 mouse_xpos, f32 mouse_ypos, std::vector<Button*> buttons)
{
    for (ui32 i = 0; i < buttons.size(); i++)
    {
        if (buttons[i]->m_position.x <= mouse_xpos &&
            buttons[i]->m_position.x + buttons[i]->m_width >= mouse_xpos &&
            buttons[i]->m_position.y <= mouse_ypos &&
            buttons[i]->m_position.y + buttons[i]->m_height >= mouse_ypos)
        {
            buttons[i]->m_onClick();
        }
    }
}

void Application::poolForEvents(std::vector<Button*> btns)
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
            SDL_GetWindowSize(this->m_window, &this->m_windowWidth, &this->m_windowHeight);
        }
        break;
    }

    i32 mouse_xpos, mouse_ypos;
    ui32 mouse_curser = SDL_GetMouseState(&mouse_xpos, &mouse_ypos);

    if ((mouse_curser & SDL_BUTTON_LMASK) != 0)
    {
        f32 rel_mouse_xpos = (((f32) mouse_xpos / this->m_windowWidth) * 2) - 1.0f;
        f32 rel_mouse_ypos = -((((f32) mouse_ypos / this->m_windowHeight) * 2) - 1.0f);

        buttonIntersect(rel_mouse_xpos, rel_mouse_ypos, btns);
    }
}

void testBtnClick1() { std::cout << "1" << std::endl; }
void testBtnClick2() { std::cout << "2" << std::endl; }
void testBtnClick3() { std::cout << "3" << std::endl; }

AppResult Application::loop()
{
    // Was the initialization successful?
    if (!this->m_isInitialized)
    {
        return FAILED;
    }
    // Was the initialization successful?

    MasterRenderer masterRenderer;
    std::vector<Button*> buttons;
    buttons.push_back(new Button({-0.9f, -0.5f}, 0.5f, 0.5f, testBtnClick1, "Button 1"));
    buttons.push_back(new Button({-0.25f, -0.5f}, 0.5f, 0.5f, testBtnClick2, "Button 2"));
    buttons.push_back(new Button({0.4f, -0.5f}, 0.5f, 0.5f, testBtnClick3, "Button 3"));

    // Main program loop.
    while (!this->closing)
    {
        this->clearScreen();
        this->poolForEvents(buttons);
        for (ui32 i = 0; i < buttons.size(); i++)
        {
            masterRenderer.renderButton(buttons[i]);
        }
        masterRenderer.finishRendering();
        SDL_GL_SwapWindow(this->m_window);
    }
    return SUCCESS;
}