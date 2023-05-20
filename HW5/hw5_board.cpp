#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<chrono>
#include<thread>
#include"hw5_lib.h"

using namespace std;

namespace games
{
	void BoardGame2D::getInput()
	{
		int moveF, choice;
		string input;
		initialize();
		print();
		while(!endGame())
		{
			cout << "1. Play user\n" << "2. Play user until the end\n" << "3. Play computer for one move\n" << 
			"4. Play computer to the end\n" << "0. Exit\n";
			cin >> choice;
			switch (choice)
			{
			case 0:
				cout << "\nThe game is over. Your score(0 is the best score) is: " << boardScore() << endl;
				return;
			case 1:
				cout << endl << endl;

				while(!endGame())
				{
					cout << "Enter a move to play (2bd means move the peg in 2b to down). Enter 0 to quit: ";
					cin >> input;

					if (input == "0")
						break;

					moveF = playUser(input);

					cout << endl << endl;	
					print();

					if  (moveF == 0)	
						cout << "Invalıd input! Enter again\n\n";
					else if (moveF == -1)
						cout << "Invalıd move! Enter again\n\n";
				}
				break;
			case 2:
				playUser();
				break;
			case 3:
				playAuto();
				break;
			case 4:
				playAutoAll();
				break;
			default:
				cout << "Invalıd input! Enter again: ";
				break;
			}
		}
		cout << "\nThe game is over. Your score(0 is the best score) is: " << boardScore() << endl;
	}

	void BoardGame2D::playUser()
	{
		int moveF;
		string input;

		while(!endGame())
		{
			while(!endGame())
			{
				print();
				cout << "Enter a move to play (2bd means move the object in 2b to down): ";
				cin >> input;

				if (input == "0")
					break;

				moveF = playUser(input);

				if  (moveF == 0)	
					cout << "Invalıd input! Enter again\n\n";
				else if (moveF == -1)
					cout << "Invalıd move! Enter again\n\n";
				cout << endl << endl;	
			}
		}
	}

	void BoardGame2D::playVector(vector<BoardGame2D*> toPlay)
	{
		for (int i = 0; i < 6; ++i)
			toPlay[i]->initialize();
		for (int i = 0; i < 6; ++i)
			toPlay[i]->playAutoAll();
	}

	void BoardGame2D::playAutoAll()
	{
		while(!endGame())
		{
			this_thread::sleep_for( std::chrono::milliseconds(200) );
			playAuto();
		}
	}
}

