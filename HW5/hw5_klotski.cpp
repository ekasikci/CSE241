#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<chrono>
#include<thread>
#include"hw5_lib.h"

using namespace std;

namespace games{
	
	void Klotski::initialize()
	{
		vector<vector<char>> temp = {
			{'|', 'O', 'O', '|'},
			{'|', 'O', 'O', '|'},
			{'|', '-', '-', '|'},
			{'|', '*', '*', '|'},
			{'*', ' ', ' ', '*'}
		};

		board = temp;
	}

	bool Klotski::isStringValid(string &input) const
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

	int Klotski::playUser(string input)
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

    bool Klotski::move(int lineI, int columnI, char moveD)
    {
    	char object = board[lineI][columnI];
    	int loc4, loc2;

    	switch(object)
    	{
    	case 'O':
    		if(lineI == 0)
    		{
    			if((columnI != board[0].size() - 1) && (board[lineI][columnI + 1] == 'O'))
    				loc4 = 1;
    			else
    				loc4 = 2;
    		}
    			
    		else if(lineI == board.size() - 1)
    		{
    			if((columnI != board[0].size() - 1) && (board[lineI][columnI + 1] == 'O'))
    				loc4 = 3;
    			else
    				loc4 = 4;
    		}
    			
    		else if(columnI == 0)
    		{
    			if(board[lineI - 1][columnI] == 'O')
    				loc4 = 3;
    			else
    				loc4 = 1;
    		}
    			
    		else if(columnI == board[0].size() - 1)
    		{
    			if(board[lineI - 1][columnI] == 'O')
    				loc4 = 2;
    			else
    				loc4 = 4;
    		}	
    		else
    		{
    			if(board[lineI][columnI + 1] == 'O' && board[lineI + 1][columnI] == 'O')
    				loc4 = 1;
    			else if(board[lineI][columnI - 1] == 'O' && board[lineI + 1][columnI] == 'O')
    				loc4 = 2;
    			else if(board[lineI][columnI + 1] == 'O' && board[lineI - 1][columnI] == 'O')
    				loc4 = 3;
    			else loc4 = 4;
    		}
 
    		switch (moveD)
		    {
		    case 'R':
	        case 'r':	
	            switch(loc4)
	            {
	            case 1:
	            	if(board[lineI][columnI + 2] != ' ' || board[lineI + 1][columnI + 2] != ' ') 
	            		return false;
	            	board[lineI][columnI + 2] = 'O';
	            	board[lineI + 1][columnI + 2] = 'O';
	            	board[lineI][columnI] = ' ';
	            	board[lineI + 1][columnI] = ' ';
	            	return true;
	            case 2:
	            	if(board[lineI][columnI + 1] != ' ' || board[lineI + 1][columnI + 1] != ' ') 
	            		return false;
	            	board[lineI][columnI + 1] = 'O';
	            	board[lineI + 1][columnI + 1] = 'O';
	            	board[lineI][columnI - 1] = ' ';
	            	board[lineI + 1][columnI - 1] = ' ';
	            	return true;
	            case 3:
	            	if(board[lineI][columnI + 2] != ' ' || board[lineI - 1][columnI + 2] != ' ') 
	            		return false;
	            	board[lineI][columnI + 2] = 'O';
	            	board[lineI - 1][columnI + 2] = 'O';
	            	board[lineI][columnI] = ' ';
	            	board[lineI - 1][columnI] = ' ';
	            	return true;
	            case 4:
	            	if(board[lineI][columnI + 1] != ' ' || board[lineI + 1][columnI + 1] != ' ') 
	            		return false;
	            	board[lineI][columnI + 1] = 'O';
	            	board[lineI - 1][columnI + 1] = 'O';
	            	board[lineI][columnI - 1] = ' ';
	            	board[lineI - 1][columnI] = ' ';
	            	return true;
	            }        
	            return false;

	        case 'L':
	        case 'l':
	            switch(loc4)
	            {
	            case 1:
	            	if(board[lineI][columnI - 1] != ' ' || board[lineI + 1][columnI - 1] != ' ') 
	            		return false;
	            	board[lineI][columnI - 1] = 'O';
	            	board[lineI + 1][columnI - 1] = 'O';
	            	board[lineI][columnI + 1] = ' ';
	            	board[lineI + 1][columnI + 1] = ' ';
	            	return true;
	            case 2:
	            	if(board[lineI][columnI - 2] != ' ' || board[lineI + 1][columnI - 2] != ' ') 
	            		return false;
	            	board[lineI][columnI - 2] = 'O';
	            	board[lineI + 1][columnI - 2] = 'O';
	            	board[lineI][columnI] = ' ';
	            	board[lineI + 1][columnI] = ' ';
	            	return true;
	            case 3:
	            	if(board[lineI][columnI - 1] != ' ' || board[lineI - 1][columnI - 1] != ' ') 
	            		return false;
	            	board[lineI][columnI - 1] = 'O';
	            	board[lineI - 1][columnI - 1] = 'O';
	            	board[lineI][columnI + 1] = ' ';
	            	board[lineI - 1][columnI + 1] = ' ';
	            	return true;
	            case 4:
	            	if(board[lineI][columnI - 2] != ' ' || board[lineI - 1][columnI - 2] != ' ') 
	            		return false;
	            	board[lineI][columnI - 2] = 'O';
	            	board[lineI - 1][columnI - 2] = 'O';
	            	board[lineI][columnI] = ' ';
	            	board[lineI - 1][columnI] = ' ';
	            	return true;
	            }        
	            return false;
	        case 'U':
	        case 'u':
	            switch(loc4)
	            {
	            case 1:
	            	if(board[lineI - 1][columnI] != ' ' || board[lineI - 1][columnI + 1] != ' ') 
	            		return false;
	            	board[lineI - 1][columnI] = 'O';
	            	board[lineI - 1][columnI + 1] = 'O';
	            	board[lineI + 1][columnI] = ' ';
	            	board[lineI + 1][columnI + 1] = ' ';
	            	return true;
	            case 2:
	            	if(board[lineI - 1][columnI] != ' ' || board[lineI - 1][columnI - 1] != ' ') 
	            		return false;
	            	board[lineI - 1][columnI] = 'O';
	            	board[lineI - 1][columnI - 1] = 'O';
	            	board[lineI + 1][columnI] = ' ';
	            	board[lineI + 1][columnI - 1] = ' ';
	            	return true;
	            case 3:
	            	if(board[lineI - 2][columnI] != ' ' || board[lineI - 2][columnI + 1] != ' ') 
	            		return false;
	            	board[lineI - 2][columnI] = 'O';
	            	board[lineI - 2][columnI + 1] = 'O';
	            	board[lineI][columnI] = ' ';
	            	board[lineI][columnI + 1] = ' ';
	            	return true;
	            case 4:
	            	if(board[lineI - 2][columnI] != ' ' || board[lineI - 2][columnI - 1] != ' ') 
	            		return false;
	            	board[lineI - 2][columnI] = 'O';
	            	board[lineI - 2][columnI - 1] = 'O';
	            	board[lineI][columnI] = ' ';
	            	board[lineI][columnI - 1] = ' ';
	            	return true;
	            }        
	            return false;
	        case 'D':
	        case 'd':
	            switch(loc4)
	            {
	            case 1:
	            	if(board[lineI + 2][columnI] != ' ' || board[lineI + 2][columnI + 1] != ' ') 
	            		return false;
	            	board[lineI + 2][columnI] = 'O';
	            	board[lineI + 2][columnI + 1] = 'O';
	            	board[lineI][columnI] = ' ';
	            	board[lineI][columnI + 1] = ' ';
	            	return true;
	            case 2:
	            	if(board[lineI + 2][columnI] != ' ' || board[lineI + 2][columnI - 1] != ' ') 
	            		return false;
	            	board[lineI + 2][columnI] = 'O';
	            	board[lineI + 2][columnI - 1] = 'O';
	            	board[lineI][columnI] = ' ';
	            	board[lineI][columnI - 1] = ' ';
	            	return true;
	            case 3:
	            	if(board[lineI + 1][columnI] != ' ' || board[lineI + 1][columnI + 1] != ' ') 
	            		return false;
	            	board[lineI + 1][columnI] = 'O';
	            	board[lineI + 1][columnI + 1] = 'O';
	            	board[lineI - 1][columnI] = ' ';
	            	board[lineI - 1][columnI + 1] = ' ';
	            	return true;
	            case 4:
	            	if(board[lineI + 1][columnI] != ' ' || board[lineI + 1][columnI - 1] != ' ') 
	            		return false;
	            	board[lineI + 1][columnI] = 'O';
	            	board[lineI + 1][columnI - 1] = 'O';
	            	board[lineI - 1][columnI] = ' ';
	            	board[lineI - 1][columnI - 1] = ' ';
	            	return true;
	            }        
	            return false;
		    }
		    return false;
    	case '|':
    		switch(lineI)
    		{
    		case 0:
    			if(moveD == 'U' || moveD == 'u')
    				return false;
    			loc2 = 1; // top
    			break;
    		case 1:
    			if(board[lineI - 1][columnI] == '|')
    			{
    				if(moveD == 'U' || moveD == 'u')
    				return false;
    				loc2 = 2;
    			}
    			else
    				loc2 = 1;
    			break;
    		case 2:
    			if(board[lineI + 1][columnI] == '|' && board[lineI + 1][columnI] == '|')
    				loc2 = 1;
    			else if(board[lineI + 1][columnI] != '|')
    				loc2 = 1;
    			else
    				loc2 = 2;
    		case 3:
    			if(board[lineI + 1][columnI] == '|')
    			{
    				if(moveD == 'D' || moveD == 'd')
    				return false;
    				loc2 = 1;
    			}
    			else
    				loc2 = 2;
    			break;
    		case 4:
    			if(moveD == 'D' || moveD == 'd')
    				return false;
    			loc2 = 2;
    			break;
    		}
    		
    		if(lineI == 0)
    			loc2 = 1;
    		else if(lineI == 1 && board[lineI - 1][columnI] == '|')
    			loc2 = 1;
    		switch (moveD)
		    {
		    case 'R':
	        case 'r':
	            switch(loc2)
	            {
	            case 1:
	            	if(board[lineI][columnI + 1] != ' ' || board[lineI + 1][columnI + 1] != ' ') 
	            		return false;
	            	board[lineI][columnI + 1] = '|';
	            	board[lineI + 1][columnI + 1] = '|';
	            	board[lineI][columnI] = ' ';
	            	board[lineI + 1][columnI] = ' ';
	            	return true;
	            case 2:
	            	if(board[lineI][columnI + 1] != ' ' || board[lineI - 1][columnI + 1] != ' ') 
	            		return false;
	            	board[lineI][columnI + 1] = '|';
	            	board[lineI - 1][columnI + 1] = '|';
	            	board[lineI][columnI] = ' ';
	            	board[lineI - 1][columnI] = ' ';
	            	return true;
	            }
	            return true;
	        case 'L':
	        case 'l':
	            switch(loc2)
	            {
	            case 1:
	            	if(board[lineI][columnI - 1] != ' ' || board[lineI + 1][columnI - 1] != ' ') 
	            		return false;
	            	board[lineI][columnI - 1] = '|';
	            	board[lineI + 1][columnI - 1] = '|';
	            	board[lineI][columnI] = ' ';
	            	board[lineI + 1][columnI] = ' ';
	            	return true;
	            case 2:
	            	if(board[lineI][columnI - 1] != ' ' || board[lineI - 1][columnI - 1] != ' ') 
	            		return false;
	            	board[lineI][columnI - 1] = '|';
	            	board[lineI - 1][columnI - 1] = '|';
	            	board[lineI][columnI] = ' ';
	            	board[lineI - 1][columnI] = ' ';
	            	return true;
	            }
	            return true;
	        case 'U':
	        case 'u':
	            switch(loc2)
	            {
	            case 1:
	            	if(board[lineI - 1][columnI] != ' ') 
	            		return false;
	            	board[lineI - 1][columnI] = '|';
	            	board[lineI + 1][columnI] = ' ';
	            	return true;
	            case 2:
	            	if(board[lineI - 2][columnI] != ' ') 
	            		return false;
	            	board[lineI - 2][columnI] = '|';
	            	board[lineI][columnI] = ' ';
	            	return true;
	            }
	            return true;
	        case 'D':
	        case 'd':
	            switch(loc2)
	            {
	            case 1:
	            	if(board[lineI + 2][columnI] != ' ') 
	            		return false;
	            	board[lineI + 2][columnI] = '|';
	            	board[lineI][columnI] = ' ';
	            	return true;
	            case 2:
	            	if(board[lineI + 1][columnI] != ' ') 
	            		return false;
	            	board[lineI + 1][columnI] = '|';
	            	board[lineI - 1][columnI] = ' ';
	            	return true;
	            }
	            return true;
		    }
    		break;
    	case '-':
    		switch(columnI)
    		{
    		case 0:
    			if(moveD == 'L' || moveD == 'l')
    				return false;
    			loc2 = 1;
    			break;
    		case 1:
    			if(board[lineI][columnI - 1] == '-')
    			{
    				if(moveD == 'L' || moveD == 'l')
    					return false;
    				loc2 = 2;
    			}
    			else
    				loc2 = 1;
    			break;
    		case 2:
    			if(board[lineI][columnI + 1] == '-')
    			{
    				if(moveD == 'R' || moveD == 'r')
    					return false;
    				loc2 = 1;
    			}
    			else
    				loc2 = 2;
    			break;
    		case 3:
    			if(moveD == 'R' || moveD == 'r')
    				return false;
    			loc2 = 2;
    			break;
    		}
    		switch (moveD)
		    {
		    case 'R':
	        case 'r':
	            switch(loc2)
	            {
	            case 1:
	            	if(board[lineI][columnI + 2] != ' ') 
	            		return false;
	            	board[lineI][columnI + 2] = '-';
	            	board[lineI][columnI] = ' ';
	            	return true;
	            case 2:
	            	if(board[lineI][columnI + 1] != ' ') 
	            		return false;
	            	board[lineI][columnI + 1] = '-';
	            	board[lineI][columnI - 1] = ' ';
	            	return true;
	            }
	            return true;
	        case 'L':
	        case 'l':
	            switch(loc2)
	            {
	            case 1:
	            	if(board[lineI][columnI - 1] != ' ') 
	            		return false;
	            	board[lineI][columnI - 1] = '-';
	            	board[lineI][columnI + 1] = ' ';
	            	return true;
	            case 2:
	            	if(board[lineI][columnI - 2] != ' ') 
	            		return false;
	            	board[lineI][columnI - 2] = '-';
	            	board[lineI][columnI] = ' ';
	            	return true;
	            }
	            return true;
	        case 'U':
	        case 'u':
	            switch(loc2)
	            {
	            case 1:
	            	if(board[lineI - 1][columnI] != ' ' || board[lineI - 1][columnI + 1] != ' ' ) 
	            		return false;
	            	board[lineI - 1][columnI] = '-';
	            	board[lineI - 1][columnI + 1] = '-';
	            	board[lineI][columnI] = ' ';
	            	board[lineI][columnI + 1] = ' ';
	            	return true;
	            case 2:
	            	if(board[lineI - 1][columnI] != ' ' || board[lineI - 1][columnI - 1] != ' ' ) 
	            		return false;
	            	board[lineI - 1][columnI] = '-';
	            	board[lineI - 1][columnI - 1] = '-';
	            	board[lineI][columnI] = ' ';
	            	board[lineI][columnI - 1] = ' ';
	            	return true;
	            }
	            return true;
	        case 'D':
	        case 'd':
	            switch(loc2)
	            {
	            case 1:
	            	if(board[lineI + 1][columnI] != ' ' || board[lineI + 1][columnI + 1] != ' ' ) 
	            		return false;
	            	board[lineI + 1][columnI] = '-';
	            	board[lineI + 1][columnI + 1] = '-';
	            	board[lineI][columnI] = ' ';
	            	board[lineI][columnI + 1] = ' ';
	            	return true;
	            case 2:
	            	if(board[lineI + 1][columnI] != ' ' || board[lineI + 1][columnI - 1] != ' ' ) 
	            		return false;
	            	board[lineI + 1][columnI] = '-';
	            	board[lineI + 1][columnI - 1] = '-';
	            	board[lineI][columnI] = ' ';
	            	board[lineI][columnI - 1] = ' ';
	            	return true;
	            }
	            return true;
		    }
    		break;
    	case '*':
    		switch (moveD)
		    {
		    case 'R':
	        case 'r':
	        	if (board[lineI][columnI + 1] != ' ')
	        		return false;
	            board[lineI][columnI + 1] = board[lineI][columnI];
	            board[lineI][columnI] = ' ';
	            return true;
	        case 'L':
	        case 'l':
	        	if (board[lineI][columnI - 1] != ' ')
	        		return false;
	            board[lineI][columnI - 1] = board[lineI][columnI];
	            board[lineI][columnI] = ' ';
	            return true;
	        case 'U':
	        case 'u':
	        	if (board[lineI - 1][columnI] != ' ')
	        		return false;
	            board[lineI - 1][columnI] = board[lineI][columnI];
	            board[lineI][columnI] = ' ';
	            return true;
	        case 'D':
	        case 'd':
	        	if (board[lineI + 1][columnI] != ' ')
	        		return false;
	            board[lineI + 1][columnI] = board[lineI][columnI];
	            board[lineI][columnI] = ' ';
	            return true;
		    }
    		break;
    	}
    	return false;
    }

    void Klotski::print()
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
	                cout << board[i - 1][j - 2];

	            cout << " ";
	        }
	        cout << endl;
	    }
	    cout << "\n\n";
	}

	void Klotski::playAuto()
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

	bool Klotski::endGame()
	{
		if((board[3][1] == 'O' ) && (board[3][2] == 'O' ) &&(board[4][1] == 'O' ) &&(board[4][2] == 'O' ))
                	return true;
        return false;
	}

	int Klotski::boardScore()
	{
		int score = 4;

		if(board[3][1] == 'O') --score;
		if(board[3][2] == 'O') --score;
		if(board[4][1] == 'O') --score;
		if(board[4][2] == 'O') --score;

		return score;
	}
}