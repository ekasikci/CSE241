#ifndef _HW6_GTUA_H
#define _HW6_GTUA_H

#include "hw6_I.h"

// std::shared_ptr<class> varName = std::make_shared<class>();
namespace Iterator{
	
	template<class T, unsigned int sizeA>
	class GTUArray : public Iterable<T>
	{
	public:
		friend class BaseIterator<T>;
		using iterator = BaseIterator<T>;
		GTUArray() {std::shared_ptr<T[]> tempP (new T[sizeA]); pData = tempP;} // beggining capacity of the set is arranged to be 10
		GTUArray(const GTUArray<T, sizeA>& x);
		GTUArray(GTUArray<T, sizeA>&& x);
		BaseIterator<T> erase(){return BaseIterator<T>(pData.get());} //	Erases element pointed by the given iterator 
		BaseIterator<T> begin(){return BaseIterator<T>(pData.get());} //	Returns iterator to beginning 
		BaseIterator<T> end(){return BaseIterator<T>(pData.get() + sizeA);} //	Returns iterator to end 
		const BaseIterator<T> cbegin(){return BaseIterator<T>(pData.get());} //	Returns a constant iterator to beginning 
		const BaseIterator<T> cend(){return BaseIterator<T>(pData.get() + sizeA);} //	Returns a constant iterator to end
		void clear(){pData = nullptr;} //	Clears all content 
		bool empty(); //	Tests whether container is empty 
		unsigned int size() { return sizeA; } //	Returns container size ;
		GTUArray<T, sizeA> operator=(const GTUArray<T, sizeA> & x);
		GTUArray<T, sizeA> operator=(GTUArray<T, sizeA>&& x);
		T& operator[](unsigned int index);
		T* returnP() {return pData.get();}
	private:
		std::shared_ptr<T[]> pData;
	};
}

#endif
