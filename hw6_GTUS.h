#ifndef _HW6_GTUS_H
#define _HW6_GTUS_H

#include "hw6_I.h"

// std::shared_ptr<class> varName = std::make_shared<class>();
namespace Iterator{
	template<class T>
	class GTUSet : public Iterable<T>
	{
	public:
		friend class BaseIterator<T>;
		using iterator = BaseIterator<T>;
		GTUSet() {realloc(10);} // beggining capacity of the set is arranged to be 10
		GTUSet(const GTUSet<T>& x);
		GTUSet(GTUSet<T>&& x);
		BaseIterator<T> erase(){return BaseIterator<T>(pData.get());} //	Erases element pointed by the given iterator 
		BaseIterator<T> begin(){return BaseIterator<T>(pData.get());} //	Returns iterator to beginning 
		BaseIterator<T> end(){return BaseIterator<T>(pData.get() + sizeC);} //	Returns iterator to end 
		const BaseIterator<T> cbegin(){return BaseIterator<T>(pData.get());} //	Returns a constant iterator to beginning 
		const BaseIterator<T> cend(){return BaseIterator<T>(pData.get() + sizeC);} //	Returns a constant iterator to end
		void clear(){pData = nullptr;} //	Clears all content 
		bool search(const T& x);// Returns an iterator to the parameter element if it was found 
		bool empty(); //	Tests whether container is empty 
		unsigned int size() { return sizeC; } //	Returns container size 
		unsigned int capacity() { return capacity; }
		void deleteF();
		void add(const T& value); // Add one element to the set
		void realloc (unsigned int newCapacity); // Allocates memory if the capacity of the vector has been reached
		GTUSet<T> operator=(const GTUSet<T>& x);
		GTUSet<T> operator=(GTUSet<T>&& x);
		T& operator[](unsigned int index);
		T* operator+(int x) {pData.get() += x; return this;}
		T* returnP() {return pData.get();}
		GTUSet<T> intersect(const GTUSet<T>& x);
		GTUSet<T> unionF(const GTUSet<T>& x);
	private:
		std::shared_ptr<T[]> pData;
		unsigned int sizeC = 0, capacityC = 0;
	};
}
#endif
