#include "Iterator.h"
template<class T1, class T2, class T3> Iterator<T1, T2, T3>::Iterator()
{
	element = nullptr;
}
template<class T1, class T2, class T3> Iterator<T1, T2, T3>::Iterator(ArrayItem<T1, T2, T3>* p)
{
	element = p;
}

template<class T1, class T2, class T3> ArrayItem<T1, T2, T3>* Iterator<T1, T2, T3>::operator * ()
{
	return element;
}

template<class T1, class T2, class T3> bool Iterator<T1, T2, T3>::operator ==(Iterator i)
{
	return element == i.element;
}

template<class T1, class T2, class T3> bool Iterator<T1, T2, T3>::operator !=(Iterator i)
{
	return !(*this == i);
}

template<class T1, class T2, class T3> void Iterator<T1, T2, T3>::operator ++ ()
{
	element++;
}