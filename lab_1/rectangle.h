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

	//�����������
	Rectangle(const float &w, const float &h, const float &x, const float &y);

	//�������� ��������� �������������� (������, ������, ���������� ������)
	vector<float> GetParams() const;

	//����������� �� ����� ������� ��������������
	bool IsBoarder(const pair<float, float> &point) const;

	//���������� �� ������������� ��� �������
	bool IsCrossesAbscissa() const;

	//���������� �� ������������� ��� �������
	bool IsCrossesOrdinate() const;

	//�������� �������� ��������������
	float GetPerimetr() const;

	//���������� ������, ��������� �� ����������� ������� �������
	vector<pair<float, float>> GetVertices() const;

private:

	//���������� �� ����� "p0" �� ������, �������� �� ���� ������ "p1" � "p2"
	float DistancePointLine(const pair<float, float> &p0,
		const pair<float, float> &p1, const pair<float, float> &p2) const;

	//���������� ����� �������
	float DistanceBetweenPoints(const pair<float, float>& p1, const pair<float, float>& p2) const;

	//������ ��������������
	const float width;

	//������ ��������������
	const float height;

	//�������� ������ �������������
	const float center_x;

	//�������� ������ ��������������
	const float center_y;

	//�������� ������
	vector<float> vertices_x;

	//�������� ������
	vector<float> vertices_y;

	//������� ��������������
	vector<pair<float, float>> vertices;
};
