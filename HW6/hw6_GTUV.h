#ifndef _HW6_GTUV_H
#define _HW6_GTUV_H

#include "hw6_I.h"

// std::shared_ptr<class> varName = std::make_shared<class>();
namespace Iterator{
	template<class T>
	class GTUVector : public Iterable<T>
	{
	public:
		friend class BaseIterator<T>;
		using iterator = BaseIterator<T>; 
		GTUVector() {realloc(10);} // Beggining capacity of the vector is arranged to be 10
		GTUVector(const GTUVector<T>& x); // Copy constructor
		GTUVector(GTUVector<T>&& x); // Move constructor
		BaseIterator<T> erase(){return BaseIterator<T>(pData.get());} //	Erases element pointed by the given iterator 
		BaseIterator<T> begin(){return BaseIterator<T>(pData.get());} //	Returns iterator to beginning 
		BaseIterator<T> end(){return BaseIterator<T>(pData.get() + sizeC);} //	Returns iterator to end 
		const BaseIterator<T> cbegin(){return BaseIterator<T>(pData.get());} //	Returns a constant iterator to beginning 
		const BaseIterator<T> cend(){return BaseIterator<T>(pData.get() + sizeC);} //	Returns a constant iterator to end
		void clear(){pData = nullptr;} //	Clears all content 
		bool empty(); //	Tests whether container is empty 
		unsigned int size() { return sizeC; } //	Returns container size 
		unsigned int capacity() { return capacity; }
		void add(const T& value); // Add one element to the vector
		void pop_back();
		void realloc (unsigned int newCapacity); // Allocates memory if the capacity of the vector has been reached
		GTUVector<T> operator= (const GTUVector<T>& x);
		GTUVector<T> operator= (GTUVector<T>&& x);
		T& operator[](unsigned int index);
		T* operator+(int x) {pData += x; return this;}
		T* returnP() {return pData.get();} // Returns pointer of the vector
	private:
		std::shared_ptr<T[]> pData;
		unsigned int sizeC = 0, capacityC = 0;
	};
}

#endif
