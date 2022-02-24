#include "rhomb.h"

Rhomb::Rhomb(const float& w, const float& x, const float& y, const float& alpha) : Parallelogramm(w, w, x, y, alpha) { };

float Rhomb::GetPerimetr() {
	return 4 * width;
}