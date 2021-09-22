/*
 * Filename: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\src\typ2defs.hpp
 * Path: e:\Wolfgang_Aigner\Documents\5BHELS\Projekt\src
 * Created Date: Monday, September 13th 2021, 9:19:39 pm
 * Author: Wolfgang Aigner
 *
 * Copyright (c) 2021 Wolfgang Aigner
 */

#ifndef __TYPEDEFS_HPP__
#define __TYPEDEFS_HPP__

#include <stdint.h>

typedef uint8_t ui8;
typedef uint16_t ui16;
typedef uint32_t ui32;
typedef uint64_t ui64;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef float f32;
typedef double f64;

struct Vertex2D
{
    Vertex2D() {}
    Vertex2D(f32 x, f32 y)
    {
        this->x = x;
        this->y = y;
    }

    Vertex2D& operator=(const Vertex2D& other)
    {
        this->x = other.x;
        this->y = other.y;
        return *this;
    }

    f32 x, y;
};

struct Vertex3D
{
    Vertex3D() {}
    Vertex3D(f32 x, f32 y, f32 z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Vertex3D& operator=(const Vertex3D& other)
    {
        this->x = other.x;
        this->y = other.y;
        this->z = other.z;
        return *this;
    }

    f32 x, y, z;
};

typedef Vertex2D Vector2D;

#endif // __TYPEDEFS_HPP__