/*
 * Filename: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\src\main.cpp
 * Path: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\src
 * Created Date: Monday, September 13th 2021, 6:45:31 pm
 * Author: Wolfgang Aigner
 *
 * Copyright (c) 2021 Wolfgang Aigner
 */

#include <iostream>

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#define GLEW_STATIC
#include <GL/glew.h>

#include <plog/Log.h>
#include <plog/Initializers/RollingFileInitializer.h>

#include "Application.hpp"

int main(int argc, char const* argv[])
{
    plog::init(plog::debug, "Log.txt");
    Application* app = new Application("Hallo", 600, 800);
    ui32 result = app->loop();
    if (result == APP_FAILED)
    {
        PLOGD << "App Failed to start";
    }
    return result;
}