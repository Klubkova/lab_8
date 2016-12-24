#ifndef FIGURE_H
#define FIGURE_H
class Figure
{
public:
	// виртуальные функции, которые присутствуют в производных классах и будут переопределены для каждого из них
	virtual double Square() = 0; // подсчет площади фигуры
	virtual void Print() = 0; // вывод значений элементов фигуры
	virtual ~Figure() {}; // удаление фигуры
};
#endif /* FIGURE_H */

