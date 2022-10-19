#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<chrono>
#include<thread>
#include"hw5_lib.h"

using namespace std;

namespace games{
	
	void PegSolitaire::initialize()
	{
		vector<vector<cell>> temp = {
			{a, a, a, a, a, a, a, a, a, a, a, a, a},
            {a, a, a, a, a, p, p, p, a, a, a, a, a},
            {a, a, a, a, a, p, p, p, a, a, a, a, a},
            {a, a, a, a, a, p, p, p, a, a, a, a, a},
            {a, a, p, p, p, p, p, p, p, p, p, a, a},
            {a, a, p, p, p, p, e, p, p, p, p, a, a},
            {a, a, p, p, p, p, p, p, p, p, p, a, a},
            {a, a, a, a, a, p, p, p, a, a, a, a, a},
            {a, a, a, a, a, p, p, p, a, a, a, a, a},
            {a, a, a, a, a, p, p, p, a, a, a, a, a},
            {a, a, a, a, a, a, a, a, a, a, a, a, a}
		};

		board = temp;
	}

	void PegSolitaire::print()
	{
	    char letter;   
	    // Prints the board
		cout << "\033[H\033[J";
	    for(int i = 0; i < board.size() - 1; ++i) 
	    {
	        for(int j = 0; j < board[i].size() - 2; ++j)
	        {
	            if (i == 0 && j > 1)
	            {
	                letter = j + 95;
	                cout << letter;
	            }    
	            else if (i != 0 && j == 0)
	                cout << i;
	            else if (j == 1)
	                cout << ' ';
	            else
	            {
	                if (board[i][j] == e)
	                cout << '.';
	                else if (board[i][j] == p)
	                    cout << "P";
	                else if (board[i][j] == a)
	                    cout << " ";
	            }
	            cout << " ";
	        }
	        cout << endl;
	    }
	    cout << "\n\n";
	}

	bool PegSolitaire::isStringValid(string &input) const
	{

		if((input[0] - '0') < 1 || (input[0] - '0') > board.size() - 2)
			return false;

		if(input[1] >= 'A' && input[1] <= 'Z')
			input[1] += 32;
		else if(input[1] >= 'a' && input[1] <= 'z');
		else
			return false;

		if(((int)input[1] -96) > board[input[0] - '0'].size() - 2)
			return false;

		if(input[2] != 'u' && input[2] != 'd' && input[2] != 'l' && input[2] != 'r' && 
			input[2] != 'U' && input[2] != 'D' && input[2] != 'L' && input[2] != 'R')
			return false;

		return true;
	}

	int PegSolitaire::playUser(string input)
	{
		int lineI, columnI;
		if(isStringValid(input))
		{
			columnI = (int)input[1] -95;
			lineI = (input[0] - '0');

			if(move(lineI, columnI, input[2]))
				return 1;

			return - 1;
		}
		return 0;
	}

	bool PegSolitaire::move(int lineI, int columnI, char moveD)
    {
    	// Checks if the movement is valid then implements the movement according to sended direction
	    switch (moveD)
	    {
	    case 'R':
        case 'r':
            // These if statements checks the movement validity. If the movement is not valid breaks the case and 
        	// returns a notify to the main function
            if (board[lineI][columnI + 1] != cell::peg || board[lineI][columnI + 2] != cell::empty)
                return false;
            board[lineI][columnI + 1] = board[lineI][columnI + 2];
            board[lineI][columnI + 2] = board[lineI][columnI];
            board[lineI][columnI] = board[lineI][columnI + 1];
            return true;
        case 'L':
        case 'l':
            if (board[lineI][columnI - 1] != cell::peg || board[lineI][columnI - 2] != cell::empty)
                return false;
            board[lineI][columnI - 1] = board[lineI][columnI - 2];
            board[lineI][columnI - 2] = board[lineI][columnI];
            board[lineI][columnI] = board[lineI][columnI - 1];
            return true;
        case 'U':
        case 'u':
            if (board[lineI - 1][columnI] != cell::peg || board[lineI - 2][columnI] != cell::empty)
                return false;
            board[lineI - 1][columnI] = board[lineI - 2][columnI];
            board[lineI - 2][columnI] = board[lineI][columnI];
            board[lineI][columnI] = board[lineI - 1][columnI];
            return true;
        case 'D':
        case 'd':
            if (board[lineI + 1][columnI] != cell::peg || board[lineI + 2][columnI] != cell::empty)
                return false;
            board[lineI + 1][columnI] = board[lineI + 2][columnI];
            board[lineI + 2][columnI] = board[lineI][columnI];
            board[lineI][columnI] = board[lineI + 1][columnI];  
            return true;           
	    }
	    return false;
    }

	void PegSolitaire::playAuto()
	{
		int lineI, columnI, c_move_6 = 0, s_c_direction;
	    char moveD;
	    bool validMove = false;

	    srand(time(0));

	    while (!validMove)
	    {
	        lineI = (rand() % (board.size() - 1)) + 1;
	        columnI = (rand() % (board[0].size() - 2)) + 2;
	        if (board[lineI][columnI] != cell::peg)
	            continue;          
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
	        // These statements avoid the program being crashed because of segmentation fault
	        if ((lineI == (board.size() - 2)) && (moveD == 'd' || moveD == 'D') || (lineI == (board.size() - 1)) && (moveD == 'd' || moveD == 'D') ||
	        (lineI == 2) && (moveD == 'u' || moveD == 'U') || (lineI == 1) && (moveD == 'u' || moveD == 'U') ||
	        (columnI == (board[0].size() - 2)) && (moveD == 'r' || moveD == 'R') || (columnI == (board[0].size() - 1)) && (moveD == 'r' || moveD == 'R') ||
	        (columnI == 3) && (moveD == 'l' || moveD == 'L') || (columnI == 2) && (moveD == 'l' || moveD == 'L'))
	            continue;

	        validMove = move(lineI, columnI, moveD);
	        
	        if (validMove)
	            print();
    	}
    }

	bool PegSolitaire::endGame()
	{
		for(int i = 0; i < board.size(); ++i) 
        {
            for(int j = 0; j < board[i].size() - 1; ++j)
            {
                if (board[i][j] == cell::peg && board[i][j + 1] == cell::peg && board[i][j + 2] == cell::empty || 
                	board[i][j] == cell::peg && board[i + 1][j] == cell::peg && board[i + 2][j] == cell::empty)
                return false;
             	if (board[i][j] == cell::empty && board[i][j + 1] == cell::peg && board[i][j + 2] == cell::peg || 
                	board[i][j] == cell::empty && board[i + 1][j] == cell::peg && board[i + 2][j] == cell::peg)
                return false;
            }
        }
        return true;
	}

	int PegSolitaire::boardScore()
	{
		int tPeg = 0;

			for (int i = 0; i < board.size(); ++i)
				for (int j = 0; j < board[i].size(); ++j)
					if(board[i][j] == p)
						tPeg++;
		return tPeg - 1;
	}
}

