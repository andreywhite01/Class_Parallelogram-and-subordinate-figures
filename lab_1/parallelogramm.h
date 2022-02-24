#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include <exception>
#include <algorithm>
#define PRECISION 0.005

#define PI 3.1415926535

using namespace std;
ostream& operator<<(ostream& out, const pair<double, double>& p);
template<class T>
ostream& operator<<(ostream& out, const vector<T>& v) {
	out << "[ ";
	auto it = v.begin();
	if (it != v.end())
	{
		while (next(it) != v.end())
		{
			out << *it << ", ";
			it++;
		}
		out << *it;
	}
	out << " ]";
	return out;
}

using namespace std;
class Parallelogramm
{
public:

	//конструктор
	Parallelogramm(const float& w, const float& h, const float& x, const float& y, const float& alpha);

	//получить параметры фигруры (ширина, высота, координаты центра)
	vector<float> GetParams() const;

	//принадлежит ли точка границе фигруры
	bool IsBoarder(const pair<float, float>& point) const;

	//пересекает ли фигрура ось абсцисс
	bool IsCrossesAbscissa() const;

	//пересекает ли фигрура ось ординат
	bool IsCrossesOrdinate() const;

	//получить периметр фигруры
	virtual float GetPerimetr() const;

	//координаты вершин, найденные по направлению часовой стрелки
	vector<pair<float, float>> GetVertices() const;

	//установка центра фигуры
	void SetNewCenter(const float& x, const float& y);

	//перенос центра фигуры на dx и на dy
	void MoveCenter(const float& dx, const float& dy);

	//сброс всех изменений (возврат к первоначальным параметрам)
	void BackToOriginal();

	//вращение фигуры с изменением поля beta
	void Rotate(const float& beta);
protected:

	//расстояние от точки "p0" до прямой, заданной по двум точкам "p1" и "p2"
	float DistancePointLine(const pair<float, float>& p0,
		const pair<float, float>& p1, const pair<float, float>& p2) const;

	//расстояние между точками
	float DistanceBetweenPoints(const pair<float, float>& p1, const pair<float, float>& p2) const;

	//длина нижней стороны параллелипипеда
	const float width;

	//длина боковой стороны параллелипипеда
	const float height;

	//установить новые вершины фигуры
	void SetVertices(const float& x, const float& y);

	void SetNewVertices(const float& x, const float& y);

	void MoveVertices(const float& x, const float& y);

	//абсцисса центра фигуры
	const float original_center_x;
	float center_x;

	//ордината центра фигуры
	const float original_center_y;
	float center_y;

	//абсциссы вершин
	vector<float> original_vertices_x;
	vector<float> vertices_x;

	//ординаты вершин
	vector<float> original_vertices_y;
	vector<float> vertices_y;

	//вершины фигуры
	vector<pair<float, float>> original_vertices;
	vector<pair<float, float>> vertices;

	//угол при нижнем основании и левой стороне параллелипипеда
	const float alpha;

	//угол поворота фигуры (по умолчанию beta = 0)
	float beta = 0;
};