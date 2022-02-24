#pragma once
#include "parallelogramm.h"

class Rhomb :
    public Parallelogramm
{
public:
    Rhomb(const float& w, const float& x, const float& y, const float& alpha);
    float GetPerimetr();
};

