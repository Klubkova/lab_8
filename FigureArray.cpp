// описание методов класса FigureArray
#include "FigureArray.h"
#include <algorithm>
//#include "Iterator.cpp"
template <class T1, class T2, class T3> FigureArray<T1,T2,T3>::FigureArray(int size)
{
	data = new ArrayItem<T1, T2, T3>[size];
	FigureArray<T1, T2, T3>::size = size;
	for (int i = 0; i < size; i++)
	{
		data[i].SetIndex(i);
	}
	first = Iterator<T1, T2, T3>(data);
	last = Iterator<T1, T2, T3>(&data[size]);
}

template <class T1, class T2, class T3> void FigureArray<T1, T2, T3>::Insert(std::shared_ptr<T1> &pentagon, int index)
{
	data[index] = ArrayItem<T1,T2,T3>(pentagon, index);
}
template <class T1, class T2, class T3> void FigureArray<T1, T2, T3>::Insert(std::shared_ptr<T2> &rhombus, int index)
{
	data[index] = ArrayItem<T1, T2, T3>(rhombus, index);
}
template <class T1, class T2, class T3> void FigureArray<T1, T2, T3>::Insert(std::shared_ptr<T3> &trapeze, int index)
{
	data[index] = ArrayItem<T1, T2, T3>(trapeze, index);
}

template <class T1, class T2, class T3> bool FigureArray<T1, T2, T3>::IsPentagon(int index)
{
	return data[index].IsPentagon();
}
template <class T1, class T2, class T3> bool FigureArray<T1, T2, T3>::IsRhombus(int index)
{
	return data[index].IsRhombus();
}
template <class T1, class T2, class T3> bool FigureArray<T1, T2, T3>::IsTrapeze(int index)
{
	return data[index].IsTrapeze();
}

template <class T1, class T2, class T3> std::shared_ptr<T1> FigureArray<T1, T2, T3>::GetPentagon(int index)
{
	return data[index].GetPentagon();
}
template <class T1, class T2, class T3> std::shared_ptr<T2> FigureArray<T1, T2, T3>::GetRhombus(int index)
{
	return data[index].GetRhombus();
}
template <class T1, class T2, class T3> std::shared_ptr<T3> FigureArray<T1, T2, T3>::GetTrapeze(int index)
{
	return data[index].GetTrapeze();
}

//template <class T1, class T2, class T3> std::shared_ptr<ArrayItem<T1, T2, T3>> FigureArray<T1, T2, T3>::GetNext(int index)
//{
//	//std::shared_ptr<ArrayItem<T1, T2, T3>> p;
//	return (std::shared_ptr<ArrayItem<T1, T2, T3>>)&(data[index + 1]);
//}

template <class T1, class T2, class T3> void FigureArray<T1,T2,T3>::Delete(int index)
{
	data[index] = ArrayItem<T1, T2, T3>();
}

template <class T1, class T2, class T3> std::ostream& operator << (std::ostream &os, FigureArray<T1, T2, T3> &array)
{
	for (int i = 0; i < array.size; i++)
	{
		os << "["<<i<<"] "<<array.data[i] << std::endl;
	}
	return os;
}

template <class T1, class T2, class T3> Iterator<T1, T2, T3> FigureArray<T1, T2, T3>::begin()
{
	//return begin;
	return Iterator<T1, T2, T3>(data);
}

template <class T1, class T2, class T3> Iterator<T1, T2, T3> FigureArray<T1, T2, T3>::end()
{
	//return end;
	return Iterator<T1, T2, T3>(&data[size]);
}

template <class T1, class T2, class T3>
FigureArray<T1, T2, T3>::~FigureArray() {}

template <class T1, class T2, class T3>
void FigureArray<T1, T2, T3>::QuickSort(int L, int R)
{
	int left = L;
	int right = R;

	ArrayItem<T1,T2,T3> middle = data[(right + left) / 2];

	do
		//while (left <= right)
	{
		while (data[left] < middle) left++;
		while (data[right] > middle) right--;

		if (left <= right)
		{
			if (data[left]>data[right]) std::swap(data[left], data[right]);
			left++;
			right--;
		}
	} while (left <= right);

	if (right > L) QuickSort(L, right);
	if (left < R) QuickSort(left, R);
}

template <class T1, class T2, class T3>
std::future<void> FigureArray<T1, T2, T3>::QuickSortInBackground(int L, int R)
{
	std::packaged_task<void(int, int)> task
	(
		std::bind
		(
			&FigureArray<T1, T2, T3>::QuickSortParallel,
			this,
			std::placeholders::_1,
			std::placeholders::_2
		)
	);
	std::future<void> res(task.get_future());
	std::thread th(std::move(task),L,R);
	th.detach();
	return res;
}

template <class T1, class T2, class T3>
void FigureArray<T1, T2, T3>::QuickSortParallel(int L, int R)
{
	int left = L;
	int right = R;

	ArrayItem<T1, T2, T3> middle = data[(right + left) / 2];

	do
	{
		while (data[left] < middle) left++;
		while (data[right] > middle) right--;

		if (left <= right)
		{
			if (data[left]>data[right]) std::swap(data[left], data[right]);
			left++;
			right--;
		}
	} while (left <= right);

	std::future<void> left_res;
	std::future<void> right_res;

	if (right > L)
	{
		 left_res= QuickSortInBackground(L, right);
	}
	if (left < R)
	{
		 right_res = QuickSortInBackground(left, R);
	}
	if (right > L) left_res.get();
	if (left < R) right_res.get();
	/*if (right > L)
	{
		std::thread t1(&FigureArray<T1, T2, T3>::QuickSortParallel,this,L,right);
		t1.join();
	}
	if (left < R) 
	{
		std::thread t2(&FigureArray<T1, T2, T3>::QuickSortParallel,this,left,R);
		t2.join();
	}*/
	
	
	
}
//template <class T1, class T2, class T3> FigureArray<T1, T2, T3>::~FigureArray()
//{
//	for (int i = 0; i < size; i++)
//	{
//		delete data[i];
//	}
//	size = 0;
//}