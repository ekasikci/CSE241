#include<iostream>
#include<vector>
#include <fstream>
#include <string>

using namespace std;

namespace setofdays{
	class DayofYearSet
	{
	public:

		class DayofYear
		{
			public:
				DayofYear(){day = 0; incStatic();} // default constructor
				// constructor for day or day and month numbers are entered objects 
				DayofYear(int dayV, int monthV = 1) {day = dayV + monthtoDay(monthV); incStatic();}
				void setDay(int x){day = x;} // sets day variable of the DayofYear object
				void static incStatic(int x = 1){totalDayofYear += x;} // increases one the static variable
				void static decStatic(int x = 1){totalDayofYear -= x;} // decreases one the static variable
				int getDay() const {return day;} // returns day variable of the DayofYear object
				int monthtoDay(int monthV); // returns day number for the given month number
				int static getStatic(){return totalDayofYear;} // returns static variable of the DayofYear object	
			private:
				int month, day, size, currentLoc;
				static int totalDayofYear;
		};
		DayofYearSet(){DayofYear *pObject = new DayofYear; currentLoc = 0; sizeSet = 1;} // default conctructor
		// constructor for DayofYear pointer entered objects
		DayofYearSet(DayofYear* pNew){DayofYear *pObject = pNew; currentLoc = 0; sizeSet = 1;} 
		DayofYearSet(vector<DayofYear> x);
		friend ostream& operator <<(ostream& outputStream, const DayofYearSet &x); // prints DayofYearSet details.
		void add(int dayV, int monthV = 1);  // add one element to DayofYear variable
		void remove(int dayV, int monthV = 1); // removes one element from DayofYear variable
		void remove(); // removes the last element of DayofYear variable
		void setcurrentLoc(int x){currentLoc = x;} // sets currentLoc variable of the DayofYearSet object
		void setSize(int x){sizeSet = x;} // sets size variable of the DayofYearSet object
		void daytoMonth(int dayV); // returns month for the given day number
		// prints how many DayofYear objects are alive in this program
		void static printTotalObjects(){cout << DayofYear::getStatic() << " DayofYear objects are alive" << endl;}
		void printtoFile(string name); // prints elements to a file
		int size() const {return getcurrentLoc();} // return number of elements in the class objects
		int getcurrentLoc() const {return currentLoc;} // returns currentLoc variable of the DayofYearSet object
		int getSize() const {return sizeSet;} // returns size variable of the DayofYearSet object
		bool const operator==(const DayofYearSet &x) const; // compares two DayofYearSet objects returns true if they are equal
		const DayofYearSet operator+(const DayofYearSet &x) const; // returns the union set of two DayofYearSet objects
		const DayofYearSet operator-(const DayofYearSet &x) const; // returns the difference set of two DayofYearSet objects
		const DayofYearSet operator^(const DayofYearSet &x) const; // returns the intersection set of two DayofYearSet objects
		//const DayofYearSet operator=(DayofYearSet x); // returns the same DayofYearSet object
		const DayofYearSet operator!() const; // returns the complement set of a DayofYearSet object
		DayofYear& operator[](int x) const
		{if (x <= getcurrentLoc())return pObject[x]; else cout << "Invalid index number !!\n\n"; return pObject[0];}
	private:
		DayofYear *pObject = new DayofYear;
		int sizeSet, currentLoc;
	};
}