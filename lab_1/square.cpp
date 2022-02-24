#include "square.h"

Square::Square(const float& w, const float& x, const float& y) : Rectangle(w, w, x, y) { };

float Square::GetPerimetr() {
	return 4 * width;
};
