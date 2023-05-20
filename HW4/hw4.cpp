#include<iostream>
#include<vector>
#include <fstream>
#include <string>
#include "hw4_lib.h"

using namespace setofdays;
using namespace std;

int main()
{
	DayofYearSet::DayofYear var1(3), var2(6,11);

	auto x = { var1, var2}; // auto means vector<DayofYearSet::DayofYear> here
	
	DayofYearSet s1, s2(x), s4;

	decltype(s1) s3;

	s1.add(4,12);
	s1.add(14,8);
	s1.add(14,8); // duplication is not allowed
	s1.add(6);

	s2.add(14, 8);

	s3.add(1,9);
	s3.add(3,1);

	s4.add(6, 11);
	s4.add(2, 5);
	s4.add(4, 3);
	s4.add(4);

	cout << "s1:\n\n" << s1 << endl;
	cout << "s2:\n\n" << s2 << endl;
	cout << "s3:\n\n" << s3 << endl;

	cout << "s1 + s2:\n\n" << s1 + s2 << endl;
	cout << "s1 - s2:\n\n" << s1 - s2 << endl;
	cout << "s1 ^ s2:\n\n" << (s1 ^ s2) << endl;
	cout << "compelement of s1 ^ s2 has " << (!(s1 ^ s2)).size() << " elements\n\n";

	cout << "s1:\n\n" << s1 << endl;
	s1[0] = s2[0]; // changes s1's first element using [] overloading
	cout << "s1 with changed element with '[]':\n\n" << s1 << endl;
	cout << "[] overload is working\n\n";
	if ((!(s1 + s2)) == (!s1 ^ !s2) && (!(s1 + s3)) == (!s1 ^ !s3) && (!(s1 + s4)) == (!s1 ^ !s4) && // tests 6 different pair of sets
		(!(s2 + s3)) == (!s2 ^ !s3) && (!(s2 + s4)) == (!s2 ^ !s4) && (!(s3 + s4)) == (!s3 ^ !s4)) // to see if De morgan rule is working
			cout << "De Morgan rule is working\n\n";

	s1.printtoFile("s1");
	s2.printtoFile("s2");
	s3.printtoFile("s3");
	s4.printtoFile("s4");

	DayofYearSet::printTotalObjects(); // 
	return 0;
}