#include <iostream>
#include <memory>
#include <algorithm>
#include "hw6_lib.h"

namespace Iterator
{
	template<class T>
	BaseIterator<T> Iterable<T>::erase()
	{
		return BaseIterator<T>(pData);
	}

	template<class T>
	BaseIterator<T> Iterable<T>::begin()
	{
		return BaseIterator<T>(pData);
	}

	template<class T>
	BaseIterator<T> Iterable<T>::end()
	{
		return BaseIterator<T>(pData +sizeC);
	}

	template<class T>
	const BaseIterator<T> Iterable<T>::cbegin()
	{
		return BaseIterator<T>(pData);
	}

	template<class T>
	const BaseIterator<T> Iterable<T>::cend()
	{
		return BaseIterator<T>(pData +sizeC);
	}

	template<class T>
	void Iterable<T>::clear()
	{
		
	}

	template<class T>
	bool Iterable<T>::empty()
	{
		return sizeC == 0;
	}

	template<class T>
	void Iterable<T>::realloc (unsigned int newCapacity)
	{
		T* newP = new T[newCapacity];

		if (sizeC > capacityC)
			sizeC = capacityC;

		for (int i = 0; i < sizeC; ++i)
			newP[i] = pData[i];

		delete []pData;
		pData = newP;
		capacityC = newCapacity;
	}
}