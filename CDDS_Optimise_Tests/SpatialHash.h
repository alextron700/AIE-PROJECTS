#pragma once
#pragma once
#include "raylib.h"
#include <cmath>
#include <unordered_map>
#include <vector>
#include <set>
#include <cfloat>


struct roundedCoordinate
{
    int x;
    int y;
    bool operator==(const roundedCoordinate& other) const
    {
        return this->x == other.x && this->y == other.y;
    }
};

struct HF
{
    size_t operator()(const roundedCoordinate& c) const
    {
        return std::hash<int>()(c.x) ^ (std::hash<int>()(c.y) << 1);
    }
};

inline roundedCoordinate SnapPos(const Vector2& pos, float radius = 48)
{
    roundedCoordinate result = { 0, 0 };
    if (radius <= 0) return result;
    result = { static_cast<int>(floor(pos.x / radius)), static_cast<int>(floor(pos.y / radius)) }; // round everything down, such that the coordinates end up as multiples of a grid, 1x1 critters big
    return result;
}