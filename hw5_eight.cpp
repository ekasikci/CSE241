#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<chrono>
#include<thread>
#include"hw5_lib.h"

using namespace std;

namespace games{

	void EightPuzzle::initialize()
	{
		vector<vector<int>> temp = {
			{1, 2, 3},
			{4, 5, 6},
			{7, 8, 0}
		};
		board = temp;

		shuffle();
	}

	void EightPuzzle::shuffle()
	{
		int temp, r1, r2, r3, r4;
		srand(time(0));

		for (int i = 0; i < 50; ++i)
		{
			r1 = rand() % board.size(); r2 = rand() % board.size(); r3 = rand() % board.size(); r4 = rand() % board.size();
			temp = board[r1][r2];
			board[r1][r2] = board[r3][r4];
			board[r3][r4] = temp;
		}
	}

	bool EightPuzzle::isStringValid(string &input) const
	{
		if((input[0] - '0') < 1 || (input[0] - '0') > board.size())
			return false;

		if(input[1] >= 'A' && input[1] <= 'Z')
			input[1] += 32;
		else if(input[1] >= 'a' && input[1] <= 'z');
		else
			return false;

		if(((int)input[1] -96) > board[input[0] - '0'].size())
			return false;

		if(input[2] != 'u' && input[2] != 'd' && input[2] != 'l' && input[2] != 'r' && 
			input[2] != 'U' && input[2] != 'D' && input[2] != 'L' && input[2] != 'R')
			return false;

		return true;
	}

	int EightPuzzle::playUser(string input)
	{
		int lineI, columnI;
		if(isStringValid(input))
		{
			columnI = (int)input[1] -97;
			lineI = (input[0] - '1');

			if(move(lineI, columnI, input[2]))
				return 1;

			return - 1;
		}
		return 0;
	}

    bool EightPuzzle::move(int lineI, int columnI, char moveD)
    {
    	// Checks if the movement is valid then implements the movement according to sended direction
    	if((moveD == 'r' &&  columnI == board[0].size() - 1) || (moveD == 'l' && columnI == 0) ||
	        	(moveD == 'u' && lineI == 0) || (moveD == 'd' && lineI == board.size() - 1))
    		return false;

    	
	    switch (moveD)
	    {
	    case 'R':
        case 'r':
            if (board[lineI][columnI + 1] != 0)
                return false;
            board[lineI][columnI + 1] = board[lineI][columnI];
            board[lineI][columnI] = 0;
            return true;
        case 'L':
        case 'l':
            if (board[lineI][columnI - 1] != 0)
                return false;
            board[lineI][columnI - 1] = board[lineI][columnI];
            board[lineI][columnI] = 0;
            return true;
        case 'U':
        case 'u':
            if (board[lineI - 1][columnI] != 0)
                return false;
            board[lineI - 1][columnI] = board[lineI][columnI];
            board[lineI][columnI] = 0;
            return true;
        case 'D':
        case 'd':
            if (board[lineI + 1][columnI] != 0)
                return false;
            board[lineI + 1][columnI] = board[lineI][columnI];
            board[lineI][columnI] = 0; 
            return true;
	    }
        return false;
    }

    void EightPuzzle::print()
	{
	    char letter;   
	    // Prints the board
	    cout << "\033[H\033[J";
	    for(int i = 0; i < board.size() + 1; ++i) 
	    {
	        for(int j = 0; j < board[0].size() + 2; ++j)
	        {
	        	if (j == 1);
	            else if (i == 0 && j > 1)
	            {
	                letter = j + 95;
	                cout << letter;
	            }    
	            else if (i != 0 && j == 0)
	                cout << i;
	            else if (i == 0 && j == 0)
	            	cout << " ";
	            else
	            {
	            	if (board[i - 1][j - 2] != 0)
	                	cout << board[i - 1][j - 2];
	                else
	                	cout << " ";	
	            }
	            	
	            cout << " ";
	        }
	        cout << endl;
	    }
	    cout << "\n\n";
	}

	void EightPuzzle::playAuto()
	{
		int lineI, columnI, c_move_6 = 0, s_c_direction;
	    char moveD;
	    bool validMove = false;

	    srand(time(0));

	    while (!validMove)
	    {
	        lineI = rand() % board.size();
	        columnI = rand() % board[0].size();
      
	        s_c_direction = rand() % 4;
	        switch (s_c_direction)
	        {
	            case 0:
	                moveD = 'r';
	                break;
	            case 1:
	                moveD = 'l';
	                break;
	            case 2:
	                moveD = 'u';
	                break;
	            case 3:
	                moveD = 'd';
	                break;
	        }

	        if(!((moveD == 'r' &&  columnI == board[0].size() - 1) || (moveD == 'l' && columnI == 0) ||
	        	(moveD == 'u' && lineI == 0) || (moveD == 'd' && lineI == board.size() - 1)))
	        	validMove = move(lineI, columnI, moveD);
	        
	        if (validMove)
	            print();
    	}
    }

	bool EightPuzzle::endGame()
	{
		for(int i = 0; i < board.size() * board[0].size() - 1; ++i)
            if(board[i/3][i%3] != i + 1) return false;
            	
        return true;
	}

	int EightPuzzle::boardScore()
	{
		int score = board.size() * board[0].size() - 1;

		for(int i = 0; i < board.size() * board[0].size() - 1; ++i)
            if(board[i/3][i%3] == i + 1) --score;

		return score;
	}
}