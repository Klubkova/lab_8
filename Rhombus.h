// ��������� ������� ������ Rhombus
#ifndef RHOMBUS_H
#define RHOMBUS_H
#include <cstdlib>
#include <iostream>
#include "Figure.h"
class Rhombus : public Figure
{
public:
	Rhombus(std::istream &is); // �����������
	friend std::ostream& operator << (std::ostream &os, const Rhombus &object); // ���������� ��������� ������ � ����� ostream
	double Square() override;
	void Print() override;
	virtual ~Rhombus();
private:
	// 2 ��������� �����
	size_t diagonal_1;
	size_t diagonal_2;
};
#endif  RHOMBUS_H
