// Заголовки методов класса Trapeze
#ifndef TRAPEZE_H
#define TRAPEZE_H
#include <cstdlib>
#include <iostream>
#include "Figure.h"
class Trapeze : public Figure
{
public:
	Trapeze(std::istream &is); // конструктор
	friend std::ostream& operator << (std::ostream &os, const Trapeze &object); // перегрузка оператора вывода в поток ostream
	double Square() override;
	void Print() override;
	virtual ~Trapeze();
private:
	// 2 основания и высота
	size_t base_1;
	size_t base_2;
	size_t height;
};
#endif  TRAPEZE_H 

