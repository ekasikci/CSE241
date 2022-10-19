#ifndef _HW6_GTUCI_H
#define _HW6_GTUCI_H

#include "hw6_BI.h"

// std::shared_ptr<class> varName = std::make_shared<class>();
namespace Iterator{
	template<class T>
	class GTUItreatorConst : public BaseIterator<T>
	{
	public:
	  GTUItreatorConst(T* x) :pName(x) {}
	  GTUItreatorConst(const GTUItreatorConst& x) : pName(x.pName) {}
	  const GTUItreatorConst& operator++() {++pName;return *this;}
	  const GTUItreatorConst operator++(T) {GTUItreatorConst temp(*this); operator++(); return temp;}
	  const GTUItreatorConst& operator--() {--pName;return *this;}
	  const GTUItreatorConst operator--(T) {GTUItreatorConst temp(*this); operator--(); return temp;}
	  bool operator==(const GTUItreatorConst& x) const {return pName==x.pName;}
	  bool operator!=(const GTUItreatorConst& x) const {return !(pName==x.pName);}
	  const T& operator*(){return *pName;}
	  const T* operator->(){return pName;}
	private:
		T* pName;
	};
}

#endif