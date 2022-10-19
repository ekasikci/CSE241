#ifndef _HW6_BI_H
#define _HW6_BI_H

// std::shared_ptr<class> varName = std::make_shared<class>();
namespace Iterator{

	template<class T>
	class BaseIterator
	{
	public:
		typedef T value_type;
		typedef T& reference;
		typedef T* pointer;
		typedef std::forward_iterator_tag iterator_category;
        typedef int difference_type;
		BaseIterator() :pName(nullptr) {}
		BaseIterator(T* x) :pName(x) {}
		bool operator==(const BaseIterator& x) const {return pName==x.pName;}
	  	bool operator!=(const BaseIterator& x) const {return !(pName==x.pName);}
	  	BaseIterator& operator++() {++pName;return *this;}
	  	BaseIterator operator++(int) {BaseIterator temp(*this); ++(*this); return temp;}
	  	BaseIterator& operator--() {--pName;return *this;}
	  	BaseIterator operator--(int) {BaseIterator temp(*this); --(*this); return temp;}
	  	reference operator*() {return *pName;}
	  	pointer operator->() {return pName;}
	  	void operator=(const BaseIterator& x) {pName = x.pName;}
	protected:
		T* pName;
	};
}

#endif
