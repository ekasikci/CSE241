#include "hw6_GTUA.h"

namespace Iterator
{
	template<class T, unsigned int sizeA>
	GTUArray<T, sizeA>::GTUArray(const GTUArray<T, sizeA>& x)
	{
		std::shared_ptr<T[]> tempP (new T[sizeA]); 
		pData = tempP;

		for(int i= 0; i < sizeA; ++i)
			pData[i] = x.pData[i];
	}

	template<class T, unsigned int sizeA>
	GTUArray<T, sizeA>::GTUArray(GTUArray<T, sizeA>&& x)
	{
		pData = x.pData;
		x.pData = nullptr; 

		std::cout << "Move semantic function is working.\n\n";
	}

	template<class T, unsigned int sizeA>
	bool GTUArray<T, sizeA>::empty()
	{
		if (sizeA == 0)
			return true;
		return false;
	}

	template<class T, unsigned int sizeA>
	T& GTUArray<T, sizeA>::operator[](unsigned int index)
	{
		if(index < sizeA)
			return pData[index];
		return pData[sizeA - 1];
	}

	template<class T, unsigned int sizeA>
	GTUArray<T, sizeA> GTUArray<T, sizeA>::operator=(const GTUArray<T, sizeA>& x)
	{
		pData = x.pData;
		return *this;
	}

	template<class T, unsigned int sizeA>
	GTUArray<T, sizeA> GTUArray<T, sizeA>::operator=(GTUArray<T, sizeA>&& x)
	{
		pData = x.pData;
		x.pData = nullptr;

		return *this;
	}
}