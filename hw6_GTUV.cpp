#include "hw6_GTUV.h"

namespace Iterator
{
	template<class T>
	GTUVector<T>::GTUVector(const GTUVector<T>& x)
	{
		sizeC = x.sizeC; 
		capacityC = x.capacityC;

		std::shared_ptr<T[]> newP (new T[capacityC]);

		for (int i = 0; i < x.sizeC; ++i)
			newP[i] = x.pData[i];

		pData = newP;
	}

	template<class T>
	GTUVector<T>::GTUVector(GTUVector<T>&& x)
	{
		sizeC = x.sizeC; 
		capacityC = x.capacityC; 
		pData = x.pData;

		x.sizeC = 0; 
		x.pData = nullptr; 

		std::cout << "Move semantic function is working.\n\n";
	}
	

	template<class T>
	bool GTUVector<T>::empty()
	{
		if (sizeC == 0)
			return true;

		return false;
	}

	template<class T>
	void GTUVector<T>::realloc (unsigned int newCapacity)
	{
		std::shared_ptr<T[]> newP (new T[capacityC]);

		if (sizeC > capacityC)
			sizeC = capacityC;

		for (int i = 0; i < sizeC; ++i)
			newP[i] = pData[i];

		pData = newP;
		capacityC = newCapacity;
	}

	template<class T>
	void GTUVector<T>::add(const T& value)
	{
		if (sizeC >= capacityC)
			realloc(2*capacityC);

		pData[sizeC] = value;
		++sizeC;
	}

	template<class T>
	void GTUVector<T>::pop_back()
	{
		--sizeC;
	}

	template<class T>
	T& GTUVector<T>::operator[](unsigned int index)
	{
		if (index <= sizeC)
			return pData[index];

		return pData[sizeC];
	}

	template<class T>
	GTUVector<T> GTUVector<T>::operator=(const GTUVector<T>& x)
	{
		sizeC = x.sizeC; 
		capacityC = x.capacityC;

		std::shared_ptr<T[]> newP (new T[capacityC]);

		for (int i = 0; i < x.sizeC; ++i)
			newP[i] = x.pData[i];

		pData = newP;
		return *this;
	}

	template<class T>
	GTUVector<T> GTUVector<T>::operator=(GTUVector<T>&& x)
	{
		sizeC = x.sizeC; 
		capacityC = x.capacityC;

		pData = x.pData;

		x.pData = nullptr;
		return *this;
	}
}