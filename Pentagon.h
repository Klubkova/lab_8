// Заголовки методов класса Pentagon
#ifndef PENTAGON_H
#define PENTAGON_H
#include <cstdlib>
#include <iostream>
#include "Figure.h"
class Pentagon : public Figure
{
public:
	Pentagon(std::istream &is); // конструктор
	friend std::ostream& operator << (std::ostream &os, const Pentagon &object); // перегрузка оператора вывода в поток ostream
	double Square() override;
	void Print() override;
	virtual ~Pentagon();
private:
	// разбиваем пятиугольник на треугольник и трапецию
	size_t side; // длина стороны
	size_t diagonal; // отрезок между двумя не соседними вершинами
	size_t height_1; // высота, опущенная на диагональ
	size_t height_2; // высота, опущенная на сторону
};
#endif  PENTAGON_H