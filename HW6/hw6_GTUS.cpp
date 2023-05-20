#include "hw6_GTUS.h"

namespace Iterator
{
	template<class T>
	GTUSet<T>::GTUSet(const GTUSet<T>& x)
	{
		sizeC = x.sizeC; 
		capacityC = x.capacityC;

		std::shared_ptr<T[]> newP (new T[capacityC]); 

		for (int i = 0; i < x.sizeC; ++i)
			newP[i] = x.pData[i];

		pData = newP;
	}

	template<class T>
	GTUSet<T>::GTUSet(GTUSet<T>&& x)
	{
		sizeC = x.sizeC; 
		capacityC = x.capacityC; 
		pData = x.pData;

		x.sizeC = 0; 
		x.pData = nullptr; 

		std::cout << "Move semantic function is working.\n\n";
	}

	template<class T>
	bool GTUSet<T>::empty()
	{
		if (sizeC == 0)
			return true;

		return false;
	}

	template<class T>
	void GTUSet<T>::realloc (unsigned int newCapacity)
	{
		std::shared_ptr<T[]> newP (new T[newCapacity]); 

		if (sizeC > capacityC)
			sizeC = capacityC;

		for (int i = 0; i < sizeC; ++i)
			newP[i] = pData[i];

		pData = newP;
		capacityC = newCapacity;
	}

	template<class T>
	void GTUSet<T>::add(const T& value)
	{
		for (int i = 0; i < sizeC; ++i) // Prevents adding the same value more than one
			if (pData[i] == value)
				return;

		if (sizeC >= capacityC)
			realloc(2*capacityC);

		pData[sizeC] = value;
		++sizeC;

		std::sort(pData.get(), pData.get() + sizeC); 
	}

	template<class T>
	void GTUSet<T>::deleteF()
	{
		--sizeC;
	}

	template<class T>
	T& GTUSet<T>::operator[](unsigned int index)
	{
		if (index <= sizeC)
			return pData[index];
		return pData[sizeC];
	}

	template<class T>
	GTUSet<T> GTUSet<T>::intersect(const GTUSet<T>& x)
	{
		GTUSet<T> newS;

		for (int i = 0; i < sizeC; ++i)
		{
			for (int j = 0; j < x.sizeC; ++j)
			{
				if (pData[i] == x.pData[j])
					newS.add(pData[i]);
			}
		}
		return newS;
	}

	template<class T>
	GTUSet<T> GTUSet<T>::unionF(const GTUSet<T>& x)
	{
		GTUSet newP;

		for (int i = 0; i < sizeC; ++i)
			newP.add(pData[i]);

		for (int i = 0; i < x.sizeC; ++i)
			newP.add(x.pData[i]);

		return newP;
	}

	template<class T>
	GTUSet<T> GTUSet<T>::operator=(const GTUSet<T>& x)
	{
		sizeC = x.sizeC; 
		capacityC = x.capacityC;

		T* newP = new T[x.capacityC];

		for (int i = 0; i < x.sizeC; ++i)
			newP[i] = x.pData[i];

		pData = newP;
		return *this;
	}

	template<class T>
	GTUSet<T> GTUSet<T>::operator=(GTUSet<T>&& x)
	{
		sizeC = x.sizeC; 
		capacityC = x.capacityC;

		pData = x.pData;

		x.pData = nullptr;

		return *this;
	}

	template<class T>
	bool GTUSet<T>::search(const T& x)
	{
		for (int i = 0; i < sizeC; ++i)
			if(pData[i] == x)
				return true;
		return false;
	}
}