#pragma once
#include <stdexcept>
namespace MathLibrary
{
    struct Color
    {
        // Implement the fields and members as per the asSessment... 
        unsigned int rgba;
        Color()
        {
            rgba = 0x000000FF;
        }
        Color(const Color& input)
        {
            rgba = input.rgba;
        }
        Color(unsigned char Red, unsigned char Green, unsigned char Blue, unsigned char Alpha)
        {
            rgba = Red << 24 | Green << 16 | Blue << 8 | Alpha; 
        }
        unsigned char GetRed() const
        {
            return (rgba & 0xFF000000) >> 24;
        }
        void SetRed(unsigned char Red)
        {
            rgba &= ~0xFF000000;
            rgba |= Red << 24;
        }
        unsigned char GetGreen() const
        {
            return (rgba & 0x00FF0000) >> 16;
        }
        void SetGreen(unsigned char Green)
        {
            rgba &= ~0x00FF0000;
            rgba |= Green << 16;
        }
        unsigned char GetBlue() const
        {
            return (rgba & 0x0000FF00) >> 8;
        }
        void SetBlue(unsigned char Blue)
        {
            rgba &= ~0x0000FF00;
            rgba |= Blue << 8;
        }
        unsigned char GetAlpha() const
        {
            return rgba & 0x000000FF;
        }
        void SetAlpha(unsigned char Alpha)
        {
            rgba &= ~0x000000FF;
            rgba |= Alpha;
        }
        bool operator==(Color other)
        {
            return this->rgba == other.rgba;
        }

    };
   
}