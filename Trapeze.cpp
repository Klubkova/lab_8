// Описание методов класса Trapeze
#include "Trapeze.h"
#include <iostream>
#include <cmath>
Trapeze::Trapeze(std::istream &is)
{
	std::cout << "Enter a b h: ";
	is >> base_1;
	is >> base_2;
	is >> height;
	std::cout << "Trapeze created" << std::endl;
}
std::ostream& operator << (std::ostream &os, const Trapeze &object)
{
	os << "base_1=" << object.base_1 << " " << "base_2=" << object.base_2 << " " << "height=" << object.height;
	return os;
}
double Trapeze::Square()
{
	return (base_1 + base_2)*height / 2;
}
void Trapeze::Print()
{
	std::cout << "a=" << base_1 << ", b=" << base_2 << ", h=" << height << std::endl;
}
Trapeze::~Trapeze()
{
	std::cout << "Trapeze deleted" << std::endl;
}