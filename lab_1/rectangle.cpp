#include "Rectangle.h"

Rectangle::Rectangle(const float& w, const float& h, const float& x, const float& y) :
	Parallelogramm(w,h,x,y,90) { }

float Rectangle::GetPerimetr() const {
	return 2 * (width + height);
}