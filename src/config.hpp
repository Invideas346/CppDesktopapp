/*
 * Filename: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\Code\src\config.hpp
 * Path: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\Code\src
 * Created Date: Wednesday, September 15th 2021, 3:21:29 pm
 * Author: Wolfgang Aigner
 *
 * Copyright (c) 2021 Wolfgang Aigner
 */
#ifndef __CONFIG_HPP__
#define __CONFIG_HPP__

#include <string>
#include <fstream>
#include <iostream>
#include "typedefs.hpp"

struct app_config
{
    ui32 window_height = 800;
    ui32 window_width = 1280;
    bool isFullscreen = false;
    std::string name = "Default Name";
};

#endif // __CONFIG_HPP__