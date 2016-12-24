// Описание методов класса Pentagon
#include "Pentagon.h"
#include <iostream>
#include <cmath>
Pentagon::Pentagon(std::istream &is)
{
	std::cout << "Enter a b h1 h2: ";
	is >> side;
	is >> diagonal;
	is >> height_1;
	is >> height_2;
	std::cout << "Pentagon created" << std::endl;
}
std::ostream& operator << (std::ostream &os, const Pentagon &object)
{
	os << "side = " << object.side << " " << "diagonal = " << object.diagonal << " " << "height_1 = " << object.height_1 << " " <<"height_2 = " << object.height_2;
	return os;
}
double Pentagon::Square()
{
	return (side + diagonal)*height_1 / 2 + height_2*diagonal / 2;
}
void Pentagon::Print()
{
	std::cout << "a=" << side << ", b=" << diagonal << ", h1=" << height_1 << ", h2=" << height_2 << std::endl;
}
Pentagon::~Pentagon()
{
	std::cout << "Pentagon deleted" << std::endl;
}