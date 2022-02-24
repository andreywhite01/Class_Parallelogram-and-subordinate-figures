#pragma once
#include "rectangle.h"
#include "parallelogramm.h"
#include "rhomb.h"
#include "square.h"



template <class T1, class T2>
void Assert(const T1& left, const T2& right, string hint) {
	if (left != right)
		cerr << "������ � ����� " << hint << ": " << left << " != " << right << endl;
	else
		cerr << "���� " << hint << " is OK\n";
}
void Test();

void UserTasting();