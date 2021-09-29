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

#define STB_TRUETYPE_IMPLEMENTATION
#include <stb_truetype.h>

#include <plog/Log.h>
#include <plog/Initializers/RollingFileInitializer.h>

#include "Application.hpp"

void load_config(app_config& config)
{
    std::ifstream configFile(
        "E:/Wolfgang_Aigner/Documents/5BHELS/Projekt/Code/build/bin/config/config.txt");
    std::string key;

    if (configFile.is_open())
    {
        while (configFile >> key)
        {
            if (key == "fullscreen")
            {
                configFile >> config.isFullscreen;
                std::cout << "Config: Full screen mode: " << std::boolalpha << config.isFullscreen
                          << '\n';
            }
            else if (key == "windowsize")
            {
                configFile >> config.window_width >> config.window_height;
                std::cout << "Config: Window Size: " << config.window_width << " x "
                          << config.window_height << '\n';
            }
        }
    }
    else
    {
        std::cerr << "Error: Could not find config.txt file! Using defaults.\n";
    }
}

int main(int argc, char const* argv[])
{
    plog::init(plog::debug, "Log.txt");

    // Load the config file.
    app_config config;
    load_config(config);

    Application* app = new Application(config);
    ui32 result = app->loop();

    // Did the app terminate correctly?
    if (result == APP_FAILED)
    {
        PLOGD << "App Failed to start";
    }
    // Did the app terminate correctly?

    return result;
}