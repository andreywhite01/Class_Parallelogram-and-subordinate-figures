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

	//�����������
	Parallelogramm(const float& w, const float& h, const float& x, const float& y, const float& alpha);

	//�������� ��������� ������� (������, ������, ���������� ������)
	vector<float> GetParams() const;

	//����������� �� ����� ������� �������
	bool IsBoarder(const pair<float, float>& point) const;

	//���������� �� ������� ��� �������
	bool IsCrossesAbscissa() const;

	//���������� �� ������� ��� �������
	bool IsCrossesOrdinate() const;

	//�������� �������� �������
	virtual float GetPerimetr() const;

	//���������� ������, ��������� �� ����������� ������� �������
	vector<pair<float, float>> GetVertices() const;

	//��������� ������ ������
	void SetNewCenter(const float& x, const float& y);

	//������� ������ ������ �� dx � �� dy
	void MoveCenter(const float& dx, const float& dy);

	//����� ���� ��������� (������� � �������������� ����������)
	void BackToOriginal();

	//�������� ������ � ���������� ���� beta
	void Rotate(const float& beta);
protected:

	//���������� �� ����� "p0" �� ������, �������� �� ���� ������ "p1" � "p2"
	float DistancePointLine(const pair<float, float>& p0,
		const pair<float, float>& p1, const pair<float, float>& p2) const;

	//���������� ����� �������
	float DistanceBetweenPoints(const pair<float, float>& p1, const pair<float, float>& p2) const;

	//����� ������ ������� ���������������
	const float width;

	//����� ������� ������� ���������������
	const float height;

	//���������� ����� ������� ������
	void SetVertices(const float& x, const float& y);

	void SetNewVertices(const float& x, const float& y);

	void MoveVertices(const float& x, const float& y);

	//�������� ������ ������
	const float original_center_x;
	float center_x;

	//�������� ������ ������
	const float original_center_y;
	float center_y;

	//�������� ������
	vector<float> original_vertices_x;
	vector<float> vertices_x;

	//�������� ������
	vector<float> original_vertices_y;
	vector<float> vertices_y;

	//������� ������
	vector<pair<float, float>> original_vertices;
	vector<pair<float, float>> vertices;

	//���� ��� ������ ��������� � ����� ������� ���������������
	const float alpha;

	//���� �������� ������ (�� ��������� beta = 0)
	float beta = 0;
};