#ifndef _HW6_I_H
#define _HW6_I_H

#include "hw6_GTUI.h"
#include "hw6_GTUCI.h"

// std::shared_ptr<class> varName = std::make_shared<class>();
namespace Iterator{

	template<class T>
	class Iterable
	{
	public:
		virtual BaseIterator<T> erase() = 0; //	Erase element pointed by the given iterator 
		virtual BaseIterator<T> begin() = 0; //	Return iterator to beginning 
		virtual BaseIterator<T> end() = 0; //	Return iterator to end 
		virtual const BaseIterator<T> cbegin() = 0; //	Return a constant iterator to beginning 
		virtual const BaseIterator<T> cend() = 0; //	Return a constant iterator to end
		virtual void clear() = 0; //	Clear all content 
		virtual bool empty() = 0; //	Test whether container is empty 
		virtual unsigned int size() = 0; //	Return container size 
		void realloc (unsigned int newCapacity);
	private:
		std::shared_ptr<T[]> pData;
		unsigned int sizeC = 0, capacityC = 0;

	};
}

#endif
