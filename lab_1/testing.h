#pragma once
#include "rectangle.h"
#include "parallelogramm.h"
#include "rhomb.h"
#include "square.h"
#include <utility>


template <class T1, class T2>
void Assert(const T1& left, const T2& right, string hint) {
	if (left != right) {
		cerr << "Ошибка в тесте " << hint << ": " << left << " != " << right << endl;
	}
//	cerr << "Тест " << hint << " is OK\n";
}
void Test();

void UserTasting();