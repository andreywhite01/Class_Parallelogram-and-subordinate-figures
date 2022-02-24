#pragma once
#include "rectangle.h"

class Square :
    public Rectangle
{
public:
    Square(const float& w, const float& x, const float& y);

    float GetPerimetr();
};

