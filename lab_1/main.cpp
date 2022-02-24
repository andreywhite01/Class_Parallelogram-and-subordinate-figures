#include <iostream>
#include <map>
#include "rectangle.h"
#include "testing.h"
using namespace std;

void UserTasting();
void TestingFigure(shared_ptr<Parallelogramm> fig);

int main() {
	setlocale(LC_ALL, "russian");
	Test();
	UserTasting();
	return 0;
}

void TextInfo() {
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	cout << "Вы можете построить следующие фигуры командами:\n\n";
	cout << "1) <PARAL width height x y alpha - параллелограмм с нижнем основанием width, боковым - height, координатами центра (x,y) и нижнем левым углом alpha\n";
	cout << "2) <RECT width height x y - прямоугольник с нижнем основанием width, боковым - height, координатами центра (x,y)\n";
	cout << "3) <RHOMB a x y alpha - ромб со стороной a и координатами центра (x,y) и нижнем левым углом alpha" << endl;
	cout << "4) <SQUARE a x y - квадрат со стороной a и координатами центра (x,y)\n\n";

	cout << "Также вы можете перемещать эти фигруы на плоскости с помощью команд:\n\n";
	cout << "1) MOVEBY x y - переместить центр фигуры на вектор {x,y}\n";
	cout << "2) SETC x y - переместить центр фигуры в точку с координатами (x,y)\n";
	cout << "3) ROTATE beta - повернуть фигуру на угол beta (в грудусах) по часовой стрелке\n\n";

	cout << "Тестировать фигуру Вы можете с помощью команд:\n\n";
	cout << "1) BOARD x y - является ли точка граничной\n";
	cout << "2) ABS - пересекает ли фигура ось абсцисс\n";
	cout << "3) ORD - пересекает ли фигура ось ординат\n";
	cout << "4) VERT - выводит координаты вершин фигуры\n";
	cout << "5) PERIM - выводит периметр фигуры\n\n";
	cout << "6) NEW - удалить текущую фигуру и создать новую\n";
	cout << "7) ORIG - сбросить все изменения\n";

	cout << "INFO - еще раз вывести эту информацию\n";
	cout << "EXIT - завершить программу\n";
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
}

enum class CREAT_OPS {
	EXIT,
	INFO,
	PARAL,
	RECT,
	RHOMB,
	SQUARE,
};

enum class TEST_OPS {
	NEW,
	MOVEBY,
	SETC,
	ROTATE,
	BOARD,
	ABS,
	ORD,
	VERT,
	PERIM,
	ORIG,
};

void UserTasting() {
	TextInfo();
	map<string, int> creat_ops = {
		{"EXIT",0},
		{"INFO",1},
		{"PARAL",2},
		{"RECT",3},
		{"RHOMB",4},
		{"SQUARE",5} };


	string op = "";

	while (op != "EXIT") {
		cout << "<< ";
		cin >> op;
		if (creat_ops.find(op) != creat_ops.end())
		{
			CREAT_OPS operation = (CREAT_OPS)creat_ops[op];
			switch (operation)
			{
			case CREAT_OPS::EXIT: {
				return;
				break;
			}
			case CREAT_OPS::INFO: {
				TextInfo();
				break;
			}
			case CREAT_OPS::PARAL: {
				float w, h, x, y, beta;
				cin >> w >> h >> x >> y >> beta;
				Parallelogramm fig(w, h, x, y, beta);
				cout << "Параллелограмм создан\n";
				TestingFigure(make_shared<Parallelogramm>(fig));
				break;
			}
			case CREAT_OPS::RECT: {
				float w, h, x, y;
				cin >> w >> h >> x >> y;
				Rectangle fig(w, h, x, y);
				cout << "Прямоугольник создан\n";
				TestingFigure(make_shared<Parallelogramm>(fig));
				break;
			}
			case CREAT_OPS::RHOMB: {
				float a, x, y, beta;
				cin >> a >> x >> y >> beta;
				Rhomb fig(a, x, y, beta);
				cout << "Ромб создан\n";
				TestingFigure(make_shared<Parallelogramm>(fig));
				break;
			}
			case CREAT_OPS::SQUARE: {
				float a, x, y;
				cin >> a >> x >> y;
				Square fig(a, x, y);
				cout << "Квадрат создан\n";
				TestingFigure(make_shared<Parallelogramm>(fig));
				break;
			}
			default: {
				break;
			}
			}
		}
		else {
			cout << "Сначала необходимо создать фигуру\n";
		}
	}
}


void TestingFigure(shared_ptr<Parallelogramm> fig) {
	map<string, int> test_ops = {
		{"NEW",0},
		{"MOVEBY",1},
		{"SETC",2},
		{"ROTATE",3},
		{"BOARD", 4},
		{"ABS",5},
		{"ORD",6},
		{"VERT",7},
		{"PERIM",8},
		{"ORIG",9}};
	string op;
	while (op != "NEW") {
		cout << "\t>>";
		cin >> op;
		if (test_ops.find(op) != test_ops.end())
		{
			TEST_OPS operation = (TEST_OPS)test_ops[op];
			switch (operation)
			{
			case TEST_OPS::NEW: {
				cout << "\tВы действительно хотите удалить текущую фигру и создать новую? Y - согласие, другой символ - отмена\n";
				char answ;
				cout << "\t>>";
				cin >> answ;
				if (answ == 'Y') {
					cout << "\tФигруа удалена\n";
					return;
				}
				else {
					op = "";
					break;
				}
			}
			case TEST_OPS::MOVEBY: {
				float x, y;
				cin >> x >> y;
				fig->MoveCenter(x, y);
				cout << "\tФигура перемещена на вектор { " << x << ", " << y << " }\n";
				break;
			}
			case TEST_OPS::SETC: {
				float x, y;
				cin >> x >> y;
				fig->SetNewCenter(x, y);
				cout << "\tЦентр фигуры перемещен в точку ( " << x << ", " << y << " )\n";
				break;
			}
			case TEST_OPS::ROTATE: {
				float beta;
				cin >> beta;
				fig->Rotate(beta);
				cout << "\tФигура была повернута на " << beta << " градусов по часовой стрелке\n";
				break;
			}
			case TEST_OPS::BOARD: {
				float x, y;
				cin >> x >> y;
				if (fig->IsBoarder({ x, y }))
					cout << "\tTRUE\n";
				else
					cout << "\tFALSE\n";
				break;
			}
			case TEST_OPS::ABS: {
				if (fig->IsCrossesAbscissa())
					cout << "\tTRUE\n";
				else
					cout << "\tFALSE\n";
				break;
			}
			case TEST_OPS::ORD: {
				if (fig->IsCrossesOrdinate())
					cout << "\tTRUE\n";
				else
					cout << "\tFALSE\n";
				break;
			}
			case TEST_OPS::VERT: {
				cout << "\tВершины фигуры:\t" << fig->GetVertices() << endl;
				break;
			}
			case TEST_OPS::PERIM: {
				cout << "\tПериметр фигуры:\t" << fig->GetPerimetr() << endl;
				break;
			}
			case TEST_OPS::ORIG: {
				fig->BackToOriginal();
				cout << "\tНастройки фигуры сброшены к первоначальным\n" << endl;
				break;
			}
			default:
				cout << "\tВы ввели несуществующую команду, введите INFO, чтобы получить список команд\n";
				break;
			}
		}
		else
			cout << "Неизвестная команда\n";
	}
}