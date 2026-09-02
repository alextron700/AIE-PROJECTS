#pragma once
using Byte = unsigned char;

class Colour
{
private:
    unsigned int colour; //this is the "colour value integer"

public:
    Colour() {
        colour = 0;
    }

    Colour(Byte red, Byte green, Byte blue, Byte alpha) {
        colour = red << 24 | green << 16 | blue << 8 | alpha;
    }
    Colour(unsigned int other)
    {
        colour = other;
    }
    Colour& operator=(const Colour other)
    {
        this->colour = other.colour;
        return *this;
    }
    Byte getRed() 
    {
        return (colour & 0xFF000000) >> 24;
    }
    void setRed(Byte red) {
        colour &= ~0xFF000000;
        colour |= red << 24;
    }

    Byte getGreen() {
        return static_cast<Byte>((colour & 0x00FF0000) >> 16);
    }
    void setGreen(Byte green) {
        colour &= ~0x00FF0000;
        colour |= green << 16;
    }

    Byte getBlue() {
        return (colour & 0x0000FF00) >> 8;
    }
    void setBlue(Byte blue) {
        colour &= ~0x0000FF00;
        colour |= blue << 8;
    }

    Byte getAlpha() {
        return colour &0x000000FF;
    }
    void setAlpha(Byte alpha) {
        colour &= ~0x000000FF;
        colour |= alpha;
    }
    //proves that Red >> 16 == green
    Colour shiftRedToGreen()
    {
        colour = colour >> 8;
        return Colour(colour);
    }
};