#ifndef _HW6_GTUI_H
#define _HW6_GTUI_H

#include "hw6_BI.h"

// std::shared_ptr<class> varName = std::make_shared<class>();
namespace Iterator{
	template<class T>
	class GTUIterator
	{
	public:
		GTUIterator() :pName(nullptr) {}
		GTUIterator(T* x) :pName(x) {}
		bool operator==(const GTUIterator& x) const {return pName==x.pName;}
	  	bool operator!=(const GTUIterator& x) const {return !(pName==x.pName);}
	  	GTUIterator& operator++() {++pName;return *this;}
	  	GTUIterator operator++(T) {GTUIterator temp(*this); ++(*this); return temp;}
	  	GTUIterator& operator--() {--pName;return *this;}
	  	GTUIterator operator--(T) {GTUIterator temp(*this); --(*this); return temp;}
	  	T& operator*() {return *pName;}
	  	T* operator->() {return pName;}
	  	void operator=(const GTUIterator& x) {pName = x.pName;}
	protected:
		T* pName;
	};
}

#endif
