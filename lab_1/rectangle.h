#pragma once
#include <iostream>
#include <utility>
#include <vector>
#include <exception>
#include <algorithm>

#define PRECISION 0.005
using namespace std;

class Rectangle
{
public:

	//конструктор
	Rectangle(const float &w, const float &h, const float &x, const float &y);

	//получить параметры прямоугольника (ширина, высота, координаты центра)
	vector<float> GetParams() const;

	//принадлежит ли точка границе прямоугольника
	bool IsBoarder(const pair<float, float> &point) const;

	//пересекает ли прямоугольник ось абсцисс
	bool IsCrossesAbscissa() const;

	//пересекает ли прямоугольник ось ординат
	bool IsCrossesOrdinate() const;

	//получить периметр прямоугольника
	float GetPerimetr() const;

	//координаты вершин, найденные по направлению часовой стрелки
	vector<pair<float, float>> GetVertices() const;

private:

	//расстояние от точки "p0" до прямой, заданной по двум точкам "p1" и "p2"
	float DistancePointLine(const pair<float, float> &p0,
		const pair<float, float> &p1, const pair<float, float> &p2) const;

	//расстояние между точками
	float DistanceBetweenPoints(const pair<float, float>& p1, const pair<float, float>& p2) const;

	//ширина прямоугольника
	const float width;

	//высота прямоугольника
	const float height;

	//абсцисса центра прямугольника
	const float center_x;

	//ордината центра прямоугольника
	const float center_y;

	//абсциссы вершин
	vector<float> vertices_x;

	//ординаты вершин
	vector<float> vertices_y;

	//вершины прямоугольника
	vector<pair<float, float>> vertices;
};
