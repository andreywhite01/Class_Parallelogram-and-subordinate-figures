#include "parallelogramm.h"

ostream& operator<<(ostream& out, const pair<double, double>& p) {
	return out << "{ " << round(p.first * 1000) / 1000.f << ", " << round(p.second * 1000) / 1000.f << " }";
}

Parallelogramm::Parallelogramm(const float& w, const float& h, const float& x, const float& y, const float& alpha_) :
	width(w), height(h), original_center_x(x), original_center_y(y),  alpha(alpha_) {
	try
	{
		if (width <= 0)
			throw exception("Ўирина должна иметь положительное значение!");
		else if (height <= 0)
			throw exception("¬ысота должна иметь положительное значение!");
	}
	catch (const exception& e)
	{
		cerr << "Ќе удалось создать объект: " << e.what();
	}

	center_x = original_center_x;
	center_y = original_center_y;
	SetVertices(center_x, center_y);
}

void Parallelogramm::Rotate(const float &beta) {
	this->beta += beta;
	float x0 = center_x;
	float y0 = center_y;
	vertices_x = {};
	vertices_y = {};
	for (auto &item : vertices) {
		float x = item.first;
		float y = item.second;
		item.first = (x - x0) * cos(beta * PI / 180.) - (y - y0) * sin(beta * PI / 180.) + x0;
		vertices_x.push_back(item.first);
		item.second = (x - x0) * sin(beta * PI / 180.) + (y - y0) * cos(beta * PI / 180.) + y0;
		vertices_y.push_back(item.second);
	}
}

void Parallelogramm::SetVertices(const float& x, const float &y) {
	float Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;
	Bx = x - (width - height * cos(alpha * PI / 180.)) / 2.;
	By = y + (height * sin(alpha * PI / 180.)) / 2.;
	Dx = 2 * x - Bx;
	Dy = 2 * y - By;
	Cx = Bx + width;
	Cy = By;
	Ax = Dx - width;
	Ay = Dy;

	original_vertices_x = { Ax, Bx, Cx, Dx };
	vertices_x = original_vertices_x;

	original_vertices_y = { Ay, By, Cy, Dy };
	vertices_y = original_vertices_y;

	original_vertices = {};
	for (unsigned int i = 0; i < vertices_x.size(); ++i) {
		original_vertices.push_back({ vertices_x[i], vertices_y[i] });
	}
	vertices = original_vertices;
}

void Parallelogramm::SetNewVertices(const float& x, const float& y) {
	vertices_x = {};
	vertices_y = {};
	for (auto &item : vertices) {
		item.first += (x - center_x); 
		vertices_x.push_back(item.first);
		
		item.second += (y - center_y);
		vertices_y.push_back(item.second);
	}
}

void Parallelogramm::MoveVertices(const float& dx, const float& dy) {
	vertices_x = {};
	vertices_y = {};
	for (auto& item : vertices) {
		item.first += dx;
		vertices_x.push_back(item.first);

		item.second += dy;
		vertices_y.push_back(item.second);
	}
}

void Parallelogramm::MoveCenter(const float& dx, const float& dy) {
	MoveVertices(dx, dy);
	center_x = center_x + dx;
	center_y = center_y + dy;
}

void Parallelogramm::SetNewCenter(const float& x, const float& y) {
	SetNewVertices(x, y);
	center_x = x;
	center_y = y;
}

void Parallelogramm::BackToOriginal() {
	vertices_x = original_vertices_x;
	vertices_y = original_vertices_y;
	vertices = original_vertices;
	center_x = original_center_x;
	center_y = original_center_y;
}

vector<float> Parallelogramm::GetParams() const {
	vector<float> params = {
		round(width * 1000) / 1000.f,
		round(height * 1000) / 1000.f,
		round(center_x * 1000) / 1000.f,
		round(center_y * 1000) / 1000.f,
		round(alpha * 1000) / 1000.f };
	return params;
}

bool Parallelogramm::IsBoarder(const pair<float, float>& point) const {
	float x = point.first;
	float y = point.second;
	pair<float, float> p0 = { x, y };
	vector<pair<float, float>> ver = vertices;
	ver.push_back(ver[0]);
	for (unsigned int i = 0; i < ver.size() - 1; ++i) {
		// если рассто€ние от точки до пр€мой, на которой лежит сторона пр€моугольника меньше 0,005
		if (round(DistancePointLine(p0, ver[i], ver[i + 1]) * 1000) / 1000.f < PRECISION) {
			float len_1 = DistanceBetweenPoints(p0, ver[i]),
				len_2 = DistanceBetweenPoints(p0, ver[i + 1]),
				len_3 = DistanceBetweenPoints(ver[i], ver[i + 1]);
			// провер€ем, что точка принадлежит стороне пр€моугольника
			if (round(max(len_1, len_2) * 1000) <= round(len_3 * 1000))
				return true;
		}
	}
	return false;
}

bool Parallelogramm::IsCrossesAbscissa() const {
	//если знаки значени€ ординат каких либо 2 вершин различны, то фигура пересекает ось абсцисс
	return ((*min_element(vertices_y.begin(), vertices_y.end())) * (*max_element(vertices_y.begin(), vertices_y.end()))) <= 0;
}

bool Parallelogramm::IsCrossesOrdinate() const {
	//если знаки значени€ абсцисс каких либо 2 вершин различны, то фигура пересекает ось ординат
	return ((*min_element(vertices_x.begin(), vertices_x.end())) * (*max_element(vertices_x.begin(), vertices_x.end()))) <= 0;
}

float Parallelogramm::GetPerimetr() const {
	vector<pair<float, float>> ver = vertices;
	ver.push_back(vertices[0]);
	float perimetr = 0;
	//ищем периметр как сумму длин всех сторон фигуры
	for (unsigned int i = 0; i < ver.size() - 1; ++i) {
		perimetr += DistanceBetweenPoints(ver[i], ver[i + 1]);
	}
	return round(perimetr * 1000) / 1000.f;
}

float Parallelogramm::DistanceBetweenPoints(const pair<float, float>& p1, const pair<float, float>& p2) const {
	float x1 = p1.first,
		y1 = p1.second,
		x2 = p2.first,
		y2 = p2.second;
	float distance = (float)sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	return distance;
}

float Parallelogramm::DistancePointLine(const pair<float, float>& p0,
	const pair<float, float>& p1, const pair<float, float>& p2) const {
	float x0 = p0.first,
		y0 = p0.second,
		x1 = p1.first,
		y1 = p1.second,
		x2 = p2.first,
		y2 = p2.second;
	float distance = abs((y2 - y1) * x0 - (x2 - x1) * y0 - x1 * (y2 - y1) + y1 * (x2 - x1)) /
		(float)sqrt(pow((y2 - y1), 2) + pow((x2 - x1), 2));
	return distance;
}

vector<pair<float, float>> Parallelogramm::GetVertices() const {
	return vertices;
}