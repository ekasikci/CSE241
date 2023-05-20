#include<iostream>
#include<vector>
#include <fstream>
#include <string>
#include "hw4_lib.h"


using namespace std;

namespace setofdays
{

// compares two DayofYearSet objects returns true if they are not equal
bool const operator!=(const DayofYearSet x, const DayofYearSet y) {if (x == y) return false; else return true;} 
int DayofYearSet::DayofYear::totalDayofYear = 0;


DayofYearSet::DayofYearSet(vector<DayofYear> x)
{
	DayofYear *newP = new DayofYear[x.size()];

	for (int i = 0; i < x.size(); ++i)
		newP[i].setDay(x[i].getDay());

	pObject = newP;
	sizeSet = x.size();
	currentLoc = x.size();
}

int DayofYearSet::DayofYear::monthtoDay(int monthV)
{
	switch(monthV)
	{
		case 1: return 0;
			break;
		case 2:	return 31;
			break;
		case 3: return 59;
			break;
		case 4:	return 90;
			break;
		case 5:	return 120;
			break;
		case 6:	return 151;
			break;
		case 7:	return 181;
			break;
		case 8:	return 212;
			break;
		case 9:	return 243;
			break;
		case 10: return 273;
			break;
		case 11: return 304;
			break;
		case 12: return 334;
			break;
		default: cout << "Invalid date !\n\n"; return 0;
			break;
	} 
}

void daytoMonth(int dayV)
{
	if(dayV >= 1 && dayV <= 31) cout << dayV << " January" << endl;
	else if(dayV >= 32 && dayV <= 59) cout << dayV - 31 << " February" << endl;
	else if(dayV >= 60 && dayV <= 90) cout << dayV - 59 << " March" << endl; 
	else if(dayV >= 91 && dayV <= 120) cout << dayV - 90 << " April" << endl;
	else if(dayV >= 121 && dayV <= 151) cout << dayV - 120 << " May" << endl;
	else if(dayV >= 152 && dayV <= 181) cout << dayV - 151 << " June" << endl;
	else if(dayV >= 182 && dayV <= 212) cout << dayV - 181 << " July" << endl;
	else if(dayV >= 213 && dayV <= 243) cout << dayV - 212 << " August" << endl;
	else if(dayV >= 244 && dayV <= 273) cout << dayV - 243 << " September" << endl;
	else if(dayV >= 274 && dayV <= 304) cout << dayV - 273 << " October" << endl;
	else if(dayV >= 305 && dayV <= 334) cout << dayV - 304 << " November" << endl;
	else if(dayV >= 335 && dayV <= 365) cout << dayV - 334 << " December" << endl;
	else cout << "Invalid date !! \n";
}

void DayofYearSet::printtoFile(string name)
{
	ofstream savedSet;
    savedSet.open(name+".txt");

	for (int i = 0; i < getcurrentLoc(); ++i)
	{
		if(pObject[i].getDay() >= 1 && pObject[i].getDay() <= 31) savedSet << i+1 << ". element is: " << pObject[i].getDay() << " January" << endl;
		else if(pObject[i].getDay() >= 32 && pObject[i].getDay() <= 59) savedSet << i+1 << ". element is: " << pObject[i].getDay() - 31 << " February" << endl;
		else if(pObject[i].getDay() >= 60 && pObject[i].getDay() <= 90) savedSet << i+1 << ". element is: " << pObject[i].getDay() - 59 << " March" << endl; 
		else if(pObject[i].getDay() >= 91 && pObject[i].getDay() <= 120) savedSet << i+1 << ". element is: " << pObject[i].getDay() - 90 << " April" << endl;
		else if(pObject[i].getDay() >= 121 && pObject[i].getDay() <= 151) savedSet << i+1 << ". element is: " << pObject[i].getDay() - 120 << " May" << endl;
		else if(pObject[i].getDay() >= 152 && pObject[i].getDay() <= 181) savedSet << i+1 << ". element is: " << pObject[i].getDay() - 151 << " June" << endl;
		else if(pObject[i].getDay() >= 182 && pObject[i].getDay() <= 212) savedSet << i+1 << ". element is: " << pObject[i].getDay() - 181 << " July" << endl;
		else if(pObject[i].getDay() >= 213 && pObject[i].getDay() <= 243) savedSet << i+1 << ". element is: " << pObject[i].getDay() - 212 << " August" << endl;
		else if(pObject[i].getDay() >= 244 && pObject[i].getDay() <= 273) savedSet << i+1 << ". element is: " << pObject[i].getDay() - 243 << " September" << endl;
		else if(pObject[i].getDay() >= 274 && pObject[i].getDay() <= 304) savedSet << i+1 << ". element is: " << pObject[i].getDay() - 273 << " October" << endl;
		else if(pObject[i].getDay() >= 305 && pObject[i].getDay() <= 334) savedSet << i+1 << ". element is: " << pObject[i].getDay() - 304 << " November" << endl;
		else if(pObject[i].getDay() >= 335 && pObject[i].getDay() <= 365) savedSet << i+1 << ". element is: " << pObject[i].getDay() - 334 << " December" << endl;
	}
    savedSet.close();
}

void DayofYearSet::add(int dayV, int monthV)
{
	bool flag = true;

	for (int i = 0; i < getcurrentLoc() ; ++i) // checks if the element is exist in the set
	{
		if((pObject[i]).getDay() == pObject->monthtoDay(monthV) + dayV)
		{
			flag = false;
			break;
		}
	}

	if(flag)
	{
		if(getcurrentLoc() == getSize())
		{
			DayofYear *temp = new DayofYear[(getSize()) * 2]; // creates temp DayofYear pointer with double size and passes the elements to it

			for (int i = 0; i < getcurrentLoc(); ++i)
				(temp[i]).setDay((pObject[i]).getDay());
			DayofYear::decStatic(getSize());
			delete [] pObject;
			pObject = temp;
			setSize((getSize()) * 2);
		}
		DayofYearSet::DayofYear temp(dayV,monthV);
		(pObject[getcurrentLoc()]).setDay(temp.getDay());
		setcurrentLoc(getcurrentLoc() + 1);
	}
}

void DayofYearSet::remove(int dayV, int monthV)
{
	DayofYearSet newO;

	for (int i = 0; i < getcurrentLoc(); ++i)
		if(pObject[i].getDay() != dayV + pObject[i].monthtoDay(monthV)) 
			newO.add(pObject[i].getDay());

	DayofYear::decStatic(getSize());
	delete [] pObject;
	pObject = newO.pObject;
	setcurrentLoc(getcurrentLoc() - 1);
	setSize(newO.getSize());
}

void DayofYearSet::remove()
{
	DayofYearSet newO;

	for (int i = 0; i < getcurrentLoc() - 1; ++i)
		newO.add(pObject[i].getDay());

	DayofYear::decStatic(getSize());
	delete [] pObject;
	pObject = newO.pObject;
	setcurrentLoc(getcurrentLoc() - 1);
	setSize(newO.getSize());
}


ostream& operator <<(ostream& outputStream, const DayofYearSet &x)
{
	for (int i = 0; i < x.getcurrentLoc(); ++i)
	{ outputStream << i+1 << ". element is: "; daytoMonth(x[i].getDay()); }
    return outputStream;
}

const DayofYearSet DayofYearSet::operator!() const
{
	DayofYearSet x;
	int k = 0, i = 0; bool flag;

	for (i = 0; i < 365; ++i) // checks which of the elements are not exist in the set and returns them in a class
	{
		flag = true;
		for (int j = 0; j < getcurrentLoc(); ++j)
		{
			if (pObject[j].getDay() == i + 1)
			{
				flag = false;
				break;
			}
		}
		if (flag) x.add(i + 1);
	}

	return x;
}

const DayofYearSet DayofYearSet::operator+(const DayofYearSet &x) const
{
	DayofYearSet newO;
	bool flag;

	for (int i = 0; i < getcurrentLoc(); ++i) // adds elements of the first object to a new object
		newO.add((pObject[i]).getDay());

	for (int i = 0; i < x.getcurrentLoc(); ++i) // adds elements of the second object to the same object but excludes the present ones
	{
		flag = true;
		for (int j = 0; j < getcurrentLoc(); ++j)
		{
			if ((x.pObject[i]).getDay() == (pObject[j]).getDay())
			{
				flag = false;
				break;
			}
		}
		if (flag) newO.add(x.pObject[i].getDay());
	}	
	return newO;
}

const DayofYearSet DayofYearSet::operator-(const DayofYearSet &x) const
{
	DayofYearSet newO;
	bool flag;

	for (int i = 0; i < getcurrentLoc(); ++i) // removes the elements that are exist in both of the objects
	{
		flag = true;
		for (int j = 0; j < x.getcurrentLoc(); ++j)
		{
			if ((pObject[i]).getDay() == (x.pObject[j]).getDay())
			{
				flag = false;
				break;
			}
		}
		if (flag) newO.add((pObject[i]).getDay());
	}
	return newO;
}

const DayofYearSet DayofYearSet::operator^(const DayofYearSet &x) const
{
	DayofYearSet newO;
	bool flag;

	for (int i = 0; i < getcurrentLoc(); ++i) // adds elements to a new objects if they exist in both of the objects
	{
		flag = false;
		for (int j = 0; j < x.getcurrentLoc(); ++j)
		{
			if ((pObject[i]).getDay() == (x.pObject[j]).getDay())
			{
				flag = true;
				break;
			}
		}
		if (flag) newO.add((pObject[i]).getDay());
	}
	return newO;
}

bool const DayofYearSet::operator==(const DayofYearSet &x) const
{
	bool flag;

	for (int i = 0; i < getcurrentLoc(); ++i) // return false if it see an element that exist both of the objects otherwise returns true
	{
		flag = false;
		for (int j = 0; j < x.getcurrentLoc(); ++j)
		{
			if (pObject[i].getDay() == x.pObject[j].getDay())
			{
				flag = true;
				break;
			}
		}
		if (flag == false) return false;
	}
	return true;
}

}