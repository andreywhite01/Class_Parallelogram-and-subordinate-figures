#include <iostream>
#include "rectangle.h"
#include "testing.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "russian");
	Test();
	
	float width, height, center_x, center_y;
	cout << "\nПараметры прямоугольника через пробел - ширина, высота, абсцисса центра, ордината центра: ";
	cin >> width >> height >> center_x >> center_y;
	Rectangle r(width, height, center_x, center_y);
	Test(width, height, center_x, center_y, r);
	short num;
	float x, y;
	while (1)
	{
		cout << "\nКакой метод Вы хотите протестировать?\n";
		cout << "\n0 - Завершение программы\n1 - IsBoarder\n2 - IsCrossesAbscissa\n3 - IsCrossesOrdinate\n";
		cin >> num;
		switch (num)
		{
		case 0:
			return 0;
		case 1:
		{
			cout << "\nВведите координаты точки через пробел: ";
			cin >> x >> y;
			if (r.IsBoarder({ x,y }))
				cout << "принадлежит границе" << endl;
			else 
				cout << "НЕ принадлежит границе" << endl;
			break;
		}
		case 2:
		{
			if (r.IsCrossesAbscissa())
				cout << "пересекает" << endl;
			else
				cout << "НЕ пересекает" << endl;
			break;
		}
		case 3:
		{
			if (r.IsCrossesOrdinate())
				cout << "пересекает" << endl;
			else
				cout << "НЕ пересекает" << endl;
			break;
		}
		default:
			break;
		}
	}
	return 0;
}