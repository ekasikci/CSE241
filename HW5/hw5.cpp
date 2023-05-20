#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<chrono>
#include<thread>
#include"hw5_lib.h"

using namespace std;
using namespace games;

int main()
{
	BoardGame2D *ptr;
	PegSolitaire p1, p2, a;
	EightPuzzle e1, e2, b;
	Klotski k1, k2, c;

	vector<BoardGame2D*> vec;

	int choice1, choice2;
	bool game1 = true, game2 = true;

	while(game1) // Main menu
	{
		cout << "Select:\n\n";
		cout << "1. Menu for games\n";
		cout << "2. playVector function\n";;
		cout << "0. Exit\n";
		cin >> choice1;

		switch(choice1)
		{
		case 1:
			while(game2)
			{
				cout << "Select a game:\n\n";
				cout << "1. Peg Solitaire\n";
				cout << "2. Eight Puzzle\n";
				cout << "3. Klotski\n";
				cout << "0. Exit\n";
				cin >> choice2;
					
				switch(choice2)
				{
				case 1:
					a.getInput();
					break;
				case 2:
					b.getInput();
					break;
				case 3:
					c.getInput();
					break;
				case 0:
					game2 = false;
				break;
				}	
			}
			break;
		case 2:
			ptr =  &p1; // these lines pushes pointer objects to the vector
			vec.push_back(ptr);
			ptr =  &p2;
			vec.push_back(ptr);
			ptr =  &e1;
			vec.push_back(ptr);
			ptr =  &e2;
			vec.push_back(ptr);
			ptr =  &k1;
			vec.push_back(ptr);
			ptr =  &k2;
			vec.push_back(ptr);

			BoardGame2D::playVector(vec);
			break;
		case 0:
			game1 = false;
			break;
		}
	}
}
