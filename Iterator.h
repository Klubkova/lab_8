#ifndef ITERATOR_H
#define ITERATOR_H

#include <memory>
#include <iostream>
#include "ArrayItem.cpp"

template<class T1, class T2, class T3>
class Iterator
{
	public:
		Iterator();
		Iterator(ArrayItem<T1, T2, T3>* p);

		ArrayItem<T1, T2, T3>* operator *();

		bool operator==(Iterator i);
		bool operator != (Iterator i);

		void operator ++ ();

	private:
		ArrayItem<T1, T2, T3>* element;

};
#endif
