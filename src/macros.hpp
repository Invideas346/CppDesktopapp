/*
 * Filename: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\Code\src\macros.hpp
 * Path: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\Code\src
 * Created Date: Wednesday, September 15th 2021, 8:30:08 am
 * Author: Wolfgang Aigner
 * 
 * Copyright (c) 2021 Wolfgang Aigner
 */

#ifndef __MACROS_HPP__
#define __MACROS_HPP__

#include <plog/Log.h>

#ifdef _DEBUG_
    #define DEBUG_LOG(x)\
        PLOGD << x
#else
    #define DEBUG_LOG(x) 0
#endif // _DEBUG_

#endif // __MACROS_HPP__