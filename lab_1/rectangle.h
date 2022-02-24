#pragma once
#include "parallelogramm.h"

class Rectangle: 
	public Parallelogramm
{
public:

	Rectangle(const float& w, const float& h, const float& x, const float& y);
	
	float GetPerimetr() const;
};