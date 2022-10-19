#include <iostream>
#include <memory>
#include <algorithm>
#include "hw6_GTUV.cpp"
#include "hw6_GTUS.cpp"
#include "hw6_GTUA.cpp"

using namespace std;
using namespace Iterator;

void multiply3(int a) // Multiplies the given parameter with 3
{
    cout << a * 3 << " ";
}

int main()
{
	GTUVector<int> v1, v2, v3;
	GTUVector<int>::iterator vI;

	GTUSet<int> s1, s2, s3;
	GTUSet<int>::iterator sI;

	GTUArray<int, 5> a1, a2, a3;
	GTUArray<int, 5>::iterator aI;

	int variableforFind = 4;

	v1.add(3);
	v1.add(1);
	v1.add(7);
	v1.add(3);
	v1.add(variableforFind);

	s1.add(3);
	s1.add(1);
	s1.add(7);
	s1.add(3);
	s1.add(variableforFind);

	s2.add(36);
	s2.add(8);
	s2.add(7);
	s2.add(3);
	s2.add(variableforFind);


	cout << "GTUVector Test:\n\n\n";

	for (vI = v1.begin(); vI!=v1.end(); ++vI)
		cout << *vI << " ";
	cout << "add function is working.\n\n";

	
	vI = find (v1.begin(), v1.end(), variableforFind);
	if (vI != v1.end())
		std::cout << *vI << " is found, std::find is working.\n\n";
	else
		std::cout << "Element not found \n\n";

	sort(v1.returnP(), v1.returnP() + v1.size()); 

	for (vI = v1.begin(); vI!=v1.end(); ++vI)
		cout << *vI << " ";
	cout << "std::sort is working.\n\n";

	for_each(v1.begin(), v1.end(), multiply3); 
    cout << "std::for_each is working.\n\n";

	GTUVector<int> nvV(move(v1)); // or it could be GTUVector<int> nvV((GTUVector<int>&&)v1);

	cout << "\n\nGTUSet Test:\n\n\n";

	for (sI = s1.begin(); sI!=s1.end(); ++sI)
		cout << *sI << " ";

	cout << "add function is working.\n\n";

	
	sI = find (s1.begin(), s1.end(), variableforFind);
	if (sI != s1.end())
		std::cout << *sI << " is found, std::find is working.\n\n";
	else
		std::cout << "Element not found \n\n";

	sort(s1.returnP(), s1.returnP() + s1.size()); 

	for (sI = s1.begin(); sI!=s1.end(); ++sI)
		cout << *sI << " ";
	cout << "std::sort is working.\n\n";

	for_each(s1.begin(), s1.end(), multiply3); 
    cout << "std::for_each is working.\n\n";
	
	for (sI = s1.begin(); sI!=s1.end(); ++sI)
		cout << *sI << " ";
	cout << endl;

	for (sI = s2.begin(); sI!=s2.end(); ++sI)
		cout << *sI << " ";

	cout << endl;

	s3 = s1.unionF(s2);
	for (sI = s3.begin(); sI!=s3.end(); ++sI)
		cout << *sI << " ";

	cout << "Union function is working.\n\n";

	for (sI = s1.begin(); sI!=s1.end(); ++sI)
		cout << *sI << " ";

	cout << endl;

	for (sI = s2.begin(); sI!=s2.end(); ++sI)
		cout << *sI << " ";

	cout << endl;
	s3 = s1.intersect(s2);

	for (sI = s3.begin(); sI!=s3.end(); ++sI)
		cout << *sI << " ";

	cout << "Intersect function is working.\n\n";

	if (s3.search(variableforFind))
		cout << "Search function is working.\n\n";

	GTUSet<int> nsV(move(s1)); // or it could be GTUSet<int> nsV((GTUVector<int>&&)s1);

	cout << "\n\nGTUArray Test:\n\n\n";

	for (aI = a1.begin(); aI!=a1.end(); ++aI)
		cout << *aI << " ";

	cout << endl;

	a1[0] = 6;
	a1[1] = 4;
	a1[2] = 7;
	a1[3] = 9;
	a1[4] = 3;

	for (aI = a1.begin(); aI!=a1.end(); ++aI)
		cout << *aI << " ";

	cout << "\n\n";

	aI = find (a1.begin(), a1.end(), variableforFind);
	
	if (aI != a1.end())
		cout << *aI << " is found, std::find is working.\n\n";
	else
		cout << "Element not found \n\n";

	sort(a1.returnP(), a1.returnP() + a1.size()); 
	for (aI = a1.begin(); aI!=a1.end(); ++aI)
		cout << *aI << " ";
	cout << "std::sort is working.\n\n";

	for_each(a1.begin(), a1.end(), multiply3); 
    cout << "std::for_each is working.\n\n";

    GTUArray<int, 5> nA(move(a1)); // or it could be GTUArray<int, 5> nA((GTUArray<int, 5>&&)a1);
	
}