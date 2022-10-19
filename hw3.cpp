#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

enum class CellState {empty, peg, absent};

CellState e = CellState::empty, p = CellState::peg, a = CellState::absent;

// Game menu
int inline menu(); 

class PegSolitaire
{
    public:
        class Cell
        {   
            public:
                /*Sets row and column values of the Cell*/
                void setIndex(int x, char c)
                {row = x; column = c;}

                Cell(CellState x):
                    cellType(x){}

                Cell():
                    cellType(a){}

                /*Prints row and column values of the Cell*/
                void outIndex()
                {cout << row << " " << column << endl;}

                /*Operation overloads*/
                bool operator ==(CellState x)const
                {return (cellType == x);}

                bool operator ==(Cell x)const
                {return (cellType == x.cellType);}

                bool operator !=(CellState x)const
                {return (cellType != x);}

                bool operator !=(Cell x)const
                {return (cellType != x.cellType);}

                Cell operator =(Cell x);
                

            private:

            int row;
            char column;
            CellState cellType;

        };

        PegSolitaire (vector<vector<Cell>> x):
            board(x){}

        PegSolitaire ():
            boardType(0){}

        PegSolitaire (int x):
            boardType(x){}


        // Sets the peg value of the object
        void setPegs();
    
        // Return the size of the vector of the object
        int size();

        // Prints the number of the remeaning pegs 
        void outPegs()
        {cout << endl << currentPegs << " pegs left. \n\n\n";}

        // Computer makes a move
        void play();

        // User makes a move
        void play(char column, int line, char move_d);

        // Sets the board type according to user's selection
        void setboardType();

        /* const vector<vector<Cell>>& operator =(vector<vector<CellState>> x)
        {return x;} */

        // Loads the saved games
        int loadGame();

        // Saves current game
        void saveGame(string boardString); 

        // Shows board types and lets one of them be selected
        void boards(); 

        // Constructs the game board according to selected board
        void board_type();

        // Takes inputs and advances the game
        void game_loop();

        // Implements movements or doesn't let the wrong movements implemented according to input
        void move(int line, int column_i, char move_d, int &move_f);

        // Special move function for the 6th board
        void move_6(int line, int column_i, char move_d, int c_move_6, int &move_f);

        // Prints the board
        void printBoard();

        // Return true if the game has ended
        bool isEnded();

        // Plays the game and prints it until it ends
        void playGame();

        // Takes necessary informations to build a vector and returns that vector 
        vector<vector<Cell>> takeBoard(vector<vector<Cell>> board1, string text, int lineSize, int columnSize);

        /*It returns true is the first game has more pegs, otherwise it returns false.*/
        bool operator ==(const PegSolitaire& x)const;  

        static void allPegsSet(){allPegs++;}

        static void allPegsOut(){cout << "Total number of the pegs of the all created boards is " << allPegs << "\n\n";}

    private:
        
        vector<vector<Cell>> board;

        static int allPegs;
        int boardType;
        int totalPegs = 0;
        int currentPegs;
};

static int allPegs = 0;

int main()
{
    // Makes the game continue until the user want to exit
    while (menu() != 0);

    return 0;    
}

int inline menu()
{
    int gameType, boardType, mainChoice, lResult, flag = 0;

    PegSolitaire sBoard;

    srand(time(0)); 

    // Asks to user to select an option. Keeps asking until gets a valid value
    do
    {
        cout << "1. Start a new game\n\n"
         << "2. Load game\n\n"
         << "3. Exit\n\n"
         << "Select: ";

        cin >> mainChoice;

        cout << endl;

        switch(mainChoice)
        {
            case 1:
                while (1)
                {
                    cout << "1. Game from standart boards\n\n"
                    << "2. Make the computer play the game until the game ends\n\n"
                    << "Select: ";
                    
                    cin >> gameType;
                    if (gameType == 1)
                    {
                        sBoard.boards();

                        sBoard.board_type();          

                        sBoard.game_loop();

                        sBoard.outPegs();
                        
                        return 1;
                    }
                    else if (gameType == 2)
                    {
                        sBoard.boards();

                        sBoard.board_type();

                        sBoard.playGame();

                        sBoard.outPegs();

                        return 1;
                    }
                    else
                    {
                        cerr << "Invalid value! Please enter again\n\n";
                        continue;
                    }
                }
                flag = 0;
                break;
            case 2:
                lResult = sBoard.loadGame ();

                if (lResult == 1)               
                    return 1;
                else
                    return 1;
            case 3:
                return 0;
                break;
            default:
                cerr << "Invalid value! Enter again\n\n";
                flag = 1;
        }
    }
    while (flag == 1);

    return 0;
}

void PegSolitaire::boards ()
{
    int boardType;

    PegSolitaire board_1
    ({
    {a, a, a, a, a, a, a, a, a},
    {a, a, a, a, p, p, p, a, a},
    {a, a, a, p, p, p, p, p, a},
    {a, a, p, p, p, e, p, p, p},
    {a, a, p, p, p, p, p, p, p},
    {a, a, p, p, p, p, p, p, p},
    {a, a, a, p, p, p, p, p, a},
    {a, a, a, a, p, p, p, a, a}
    });

    cout << "Board 1.\n\n";

    board_1.printBoard();

    PegSolitaire board_2
    ({
    {a, a, a, a, a, a, a, a, a, a, a},
    {a, a, a, a, a, p, p, p, a, a, a},
    {a, a, a, a, a, p, p, p, a, a, a},
    {a, a, a, a, a, p, p, p, a, a, a},
    {a, a, p, p, p, p, p, p, p, p, p},
    {a, a, p, p, p, p, e, p, p, p, p},
    {a, a, p, p, p, p, p, p, p, p, p},
    {a, a, a, a, a, p, p, p, a, a, a},
    {a, a, a, a, a, p, p, p, a, a, a},
    {a, a, a, a, a, p, p, p, a, a, a},
    {a, a, a, a, a, a, a, a, a, a, a}
    });

    cout << "Board 2.\n\n";

    board_2.printBoard();

    PegSolitaire board_3
    ({
        {a, a, a, a, a, a, a, a, a, a},
        {a, a, a ,a, p, p, p, a, a, a},
        {a, a, a ,a, p, p, p, a, a, a},
        {a, a, a ,a, p, p, p, a, a, a},
        {a, a, p ,p, p, p, p, p, p, p},
        {a, a, p ,p, p, e, p, p, p, p},
        {a, a, p ,p, p, p, p, p, p, p},
        {a, a, a ,a, p, p, p, a, a, a},
        {a, a, a ,a, p, p, p, a, a, a},
        {a, a, a ,a, a, a, a, a, a, a}
    });

    cout << "Board 3.\n\n";

    board_3.printBoard();


    PegSolitaire board_4
    ({
        {a, a, a, a, a, a, a, a, a},
        {a, a, a, a, p, p, p, a, a},
        {a, a, a, a, p, p, p, a, a},
        {a, a, p, p, p, p, p, p, p},
        {a, a, p, p, p, e, p, p, p},
        {a, a, p, p, p, p, p, p, p},
        {a, a, a, a, p, p, p, a, a},
        {a, a, a, a, p, p, p, a, a},
        {a, a, a, a, a, a, a, a, a}
    });

    cout << "Board 4.\n\n";

    board_4.printBoard();

    PegSolitaire board_5
    ({
        {a, a, a, a, a, a, a, a, a, a, a},
        {a, a, a, a, a, a, p, a, a, a, a},
        {a, a, a, a, a, p, p, p, a, a, a},
        {a, a, a, a, p, p, p, p, p, a, a},
        {a, a, a, p, p, p, p, p, p, p, a},
        {a, a, p, p, p, p, e, p, p, p, p},
        {a, a, a, p, p, p, p, p, p, p, a},
        {a, a, a, a, p, p, p, p, p, a, a},
        {a, a, a, a, a, p, p, p, a, a, a},
        {a, a, a, a, a, a, p, a, a, a, a},
        {a, a, a, a, a, a, a, a, a, a, a}
    });

    cout << "Board 5.\n\n";

    board_5.printBoard();

    PegSolitaire board_6
    ({
        {a, a, a, a, a, a, a, a, a, a, a, a, a},
        {a, a, a, a, a, a, e, a, a, a, a, a, a},
        {a, a, a, a, a, p, a, p, a, a, a, a, a},
        {a, a, a, a, p, a, p, a, p, a, a, a, a},
        {a, a, a, p, a, p, a, p, a, p, a, a, a}, 
        {a, a, p, a, p, a, p, a, p, a, p, a, a},
        {a, a, a, a, a, a, a, a, a, a, a, a, a}
    });

    cout << "Board 6.\n\n";

    board_6.printBoard();
    

    cout << "Select a number to determine the board type: ";

    setboardType();
}

void PegSolitaire::board_type ()
{
    switch (boardType) // Selects a board type according to sended value
    {
    case 1:
        board =
        {
            {a, a, a, a, a, a, a, a, a},
            {a, a, a, a, p, p, p, a, a},
            {a, a, a, p, p, p, p, p, a},
            {a, a, p, p, p, e, p, p, p},
            {a, a, p, p, p, p, p, p, p},
            {a, a, p, p, p, p, p, p, p},
            {a, a, a, p, p, p, p, p, a},
            {a, a, a, a, p, p, p, a, a},
            {a, a, a, a, a, a, a, a, a}
        };
        break;
    case 2:
        board =
        {
            {a, a, a, a, a, a, a, a, a, a, a},
            {a, a, a, a, a, p, p, p, a, a, a},
            {a, a, a, a, a, p, p, p, a, a, a},
            {a, a, a, a, a, p, p, p, a, a, a},
            {a, a, p, p, p, p, p, p, p, p, p},
            {a, a, p, p, p, p, e, p, p, p, p},
            {a, a, p, p, p, p, p, p, p, p, p},
            {a, a, a, a, a, p, p, p, a, a, a},
            {a, a, a, a, a, p, p, p, a, a, a},
            {a, a, a, a, a, p, p, p, a, a, a},
            {a, a, a, a, a, a, a, a, a, a, a}
        };
        break;
    case 3:
        board =
        {
            {a, a, a, a, a, a, a, a, a, a},
            {a, a, a ,a, p, p, p, a, a, a},
            {a, a, a ,a, p, p, p, a, a, a},
            {a, a, a ,a, p, p, p, a, a, a},
            {a, a, p ,p, p, p, p, p, p, p},
            {a, a, p ,p, p, e, p, p, p, p},
            {a, a, p ,p, p, p, p, p, p, p},
            {a, a, a ,a, p, p, p, a, a, a},
            {a, a, a ,a, p, p, p, a, a, a},
            {a, a, a ,a, a, a, a, a, a, a}
        };
        break;
    case 4:
        board =
        {
            {a, a, a, a, a, a, a, a, a},
            {a, a, a, a, p, p, p, a, a},
            {a, a, a, a, p, p, p, a, a},
            {a, a, p, p, p, p, p, p, p},
            {a, a, p, p, p, e, p, p, p},
            {a, a, p, p, p, p, p, p, p},
            {a, a, a, a, p, p, p, a, a},
            {a, a, a, a, p, p, p, a, a},
            {a, a, a, a, a, a, a, a, a}
        };
        break;
    case 5:
        board =
        {
            {a, a, a, a, a, a, a, a, a, a, a},
            {a, a, a, a, a, a, p, a, a, a, a},
            {a, a, a, a, a, p, p, p, a, a, a},
            {a, a, a, a, p, p, p, p, p, a, a},
            {a, a, a, p, p, p, p, p, p, p, a},
            {a, a, p, p, p, p, e, p, p, p, p},
            {a, a, a, p, p, p, p, p, p, p, a},
            {a, a, a, a, p, p, p, p, p, a, a},
            {a, a, a, a, a, p, p, p, a, a, a},
            {a, a, a, a, a, a, p, a, a, a, a},
            {a, a, a, a, a, a, a, a, a, a, a}
        };
        break;
    case 6:
        board =
        {
            {a, a, a, a, a, a, a, a, a, a, a, a, a},
            {a, a, a, a, a, a, e, a, a, a, a, a, a},
            {a, a, a, a, a, p, a, p, a, a, a, a, a},
            {a, a, a, a, p, a, p, a, p, a, a, a, a},
            {a, a, a, p, a, p, a, p, a, p, a, a, a}, 
            {a, a, p, a, p, a, p, a, p, a, p, a, a},
            {a, a, a, a, a, a, a, a, a, a, a, a, a}
        };
        break;  
    }

    setPegs();

    printBoard();
}


int PegSolitaire::size()
{
    int i = 0, j = 0;

    while (board[i][j] == p || board[i][j] == e  || board[i][j] == a)
    {
        while (board[i][j] == p || board[i][j] == e  || board[i][j] == a)
        {
            j++;
        }
        i++;
    }
    setboardType();

    return i*j;
}

void PegSolitaire::setPegs()
{
    for(int i = 0; i < board.size(); i++) 
    {
        for(int j = 0; j < board[i].size(); j++)
        {
            if(board[i][j] == p) 
                totalPegs ++;
                /* allPegsSet(); */
        }
    }
}

void PegSolitaire::printBoard ()
{
    char letter;

    int pegs = 0;
    
    // Prints the selected board
    for(int i = 0; i < board.size(); i++) 
    {
        for(int j = 0; j < board[i].size(); j++)
        {
            if (i == 0 && j > 1)
            {
                letter = j + 95;
                cout << letter;
            }    
            else if (i != 0 && j == 0 && i != board.size() - 1)
                cout << i;
            else if (j == 1)
                cout << ' ';
            else
            {
                if (board[i][j] == e)
                cout << '.';
                else if (board[i][j] == p)
                {   
                    cout << "P";
                    pegs ++;
                }
                else if (board[i][j] == a)
                    cout << " ";
            }
            cout << " ";
        }
        cout << endl;
    }

    currentPegs = pegs;
    cout << "___________________________________\n\n";
}

void PegSolitaire::setboardType()
{
    // Checks if the user entered valid value
    while (1)
    {
        cin >> boardType;  
        if (boardType >=1 && boardType <= 6)
            break;
        else 
            cerr << "Invalid board type! Please enter again: ";
    }
}

PegSolitaire::Cell PegSolitaire::Cell::operator =(PegSolitaire::Cell x)
{
    int temp; char cemp; CellState a;
    temp = row; cemp = column;
    row = x.row; column = x.column;
    x.row = temp; x.column = cemp;
    a = cellType; cellType = x.cellType; x.cellType = a;
    return x;
}

void PegSolitaire::game_loop()
{
    int line, column_i, s_c_direction, move_f, r_pegs = 0, c_move_6 = 0, moveType;
    char column, move_d, c;

    bool game = false;
    string boardString;

    printBoard();

    while (game == false)
    {
        game = true;
        move_f = 0;
        
        game = isEnded();

        // If isEnded function couldn't find any valid move then the game ends
        if (game == true)
        {
            cout << "There is no movement left\n\n";
            break;
        }

        cout << "1 - user makes a move\n"
         << "2 - computer makes a move\n"
         << "3 - saves current game and directs main menu\n"
         << "0 - ends the game\n\n"
         << "Enter a move: ";

        cin >> moveType;
        cout << endl;
 
        // Computer move section
        if (moveType == 2)
            play();
            
        // Game saving section
        else if (moveType == 3)
        {
            // Writes the informations of the board into a string
            for(int i = 0; i < board.size(); i++) 
            {
                for(int j = 0; j < board[i].size(); j++)
                {    
                    if (board[i][j] == CellState::peg)
                        c = 'P';
                    else if (board[i][j] == CellState::empty)
                        c = 'e';
                    else
                        c = 'a';
                    boardString += c;        
                }
            }
            // Saves the game and notifies it
            saveGame(boardString);

            cout << "Game saved\n\n";
        }
        // Ends the game if the specific entry is entered
        else if (moveType == 0)
            break;
        else if (moveType == 1)
        {
            cout << "Specify a cell and choose a direction (r, l, u, d) to make a move (for example b2r means make peg from b2 move to right):\n"
                 << "Movement: ";
            cin >> column >> line >> move_d;
            cout << endl;
            
            // If the movement letter is entered wrong the program asks the user again
            if (move_d != 'r' && move_d != 'R' && move_d != 'l' && move_d != 'L' && move_d != 'u' && move_d != 'U' && move_d != 'd' && move_d != 'D')
            {
                cerr << "Invalid move! Type again.\n\n";
                continue;
            }

            play(column, line, move_d);
            
        }
        else
                cerr << "Invalıd value! Type again\n\n";
        
    }
}

void PegSolitaire::playGame()
{
    while(isEnded() == false)
        play();
}

void PegSolitaire::play()
{
    int line, column_i, c_move_6 = 0, move_f = 0, s_c_direction;
    char move_d;

    while (move_f == 0)
    {
        line = (rand() % (board.size() - 1)) + 1;
        column_i = (rand() % (board[0].size() - 2)) + 2;
        if (board[line][column_i] != CellState::peg)
            continue;          
        s_c_direction = rand() % 4;
        switch (s_c_direction)
        {
            case 0:
                move_d = 'r';
                break;
            case 1:
                move_d = 'l';
                break;
            case 2:
                move_d = 'u';
                break;
            case 3:
                move_d = 'd';
                break;
        }
        // These statements avoid the program being crashed because of segmentation fault
        if ((line == (board.size() - 2)) && (move_d == 'd' || move_d == 'D') || (line == (board.size() - 1)) && (move_d == 'd' || move_d == 'D') ||
        (line == 2) && (move_d == 'u' || move_d == 'U') || (line == 1) && (move_d == 'u' || move_d == 'U') ||
        (column_i == (board[0].size() - 2)) && (move_d == 'r' || move_d == 'R') || (column_i == (board[0].size() - 1)) && (move_d == 'r' || move_d == 'R') ||
        (column_i == 3) && (move_d == 'l' || move_d == 'L') || (column_i == 2) && (move_d == 'l' || move_d == 'L'))
            continue;
        if (boardType == 6)
            {
                c_move_6 = 1;
                move_6(line, column_i, move_d, c_move_6, move_f);
                c_move_6 = 0;
            }
        else
            move(line, column_i, move_d, move_f);
        if (move_f == 1)
            printBoard();
    }
}

void PegSolitaire::play(char column, int line, char move_d)
{
    while(1)
    {
        int column_i, c_move_6 = 0, move_f = 0;

        // Converts the entered movement to int type
        if (column >= 'A' && column <= 'Z')
            column_i = (int)column -63;
        else
            column_i = (int)column -95; 

        // These statements avoid the program being crashed because of segmentation fault 
        if ((line == (board.size() - 2)) && (move_d == 'd' || move_d == 'D') || (line == (board.size() - 1)) && (move_d == 'd' || move_d == 'D') ||
        (line == 2) && (move_d == 'u' || move_d == 'U') || (line == 1) && (move_d == 'u' || move_d == 'U') ||
        (column_i == (board[0].size() - 2)) && (move_d == 'r' || move_d == 'R') || (column_i == (board[0].size() - 1)) && (move_d == 'r' || move_d == 'R') ||
        (column_i == 3) && (move_d == 'l' || move_d == 'L') || (column_i == 2) && (move_d == 'l' || move_d == 'L'))
        {
            cerr << "Invalid move! Type again.\n\n";
            continue;
        }
        
        // If the user enters a not valid cell to move the program asks the user again
        if (line >= board.size() || line < 1 || column_i >= board[0].size() || column_i < 2)
        {
            cerr << "Invalid cell! Type again.\n\n";
            continue;
        }
        // If the user selects a cell without a peg the program asks the user again
        else if (board[line][column_i] != CellState::peg)
        {
            cerr << "Selected cell has no peg! Type again.\n\n";
            continue;
        }     
        if (boardType == 6) // If the board type is 6th one the program calls the special move function
            move_6(line, column_i, move_d, c_move_6, move_f);
        else
            move(line, column_i, move_d, move_f);
        // If the intended movement is valid and implemented the program prints the current board
        if (move_f == 1)
        {
            printBoard(); 
            break;
        }
        else
            cerr << "Invalıd move! Type again\n\n";
    }
}

bool PegSolitaire::isEnded()
{
    // Checks if there is any remaining peg in the board. If there is continues the game
    if (boardType == 6)
    {      
        for(int i = 0; i < board.size(); i++) 
        {
            for(int j = 0; j < board[i].size() - 1; j++)
                if ((board[i][j] == CellState::peg && board[i][j] == board[i][j + 2]) || (board[i][j] == CellState::peg && board[i][j] == board[i + 1][j + 1])
                || (board[i][j] == CellState::peg && board[i][j] == board[i + 1][j - 1]))
                return false;
        }
    }
    else
    {
        for(int i = 0; i < board.size(); i++) 
        {
            for(int j = 0; j < board[i].size() - 1; j++)
                if ((board[i][j] == CellState::peg && board[i][j] == board[i][j + 1]) || (board[i][j] == CellState::peg && board[i][j] == board[i + 1][j]))
                return false;
        }
    }
    return true;
}

void PegSolitaire::move(int line, int column_i, char move_d, int &move_f)
{

    // Checks if the movement is valid then implements the movement according to sended direction
    switch (move_d)
    {
        case 'R':
        case 'r':
            // These if statements checks the movement validity. If the movement is not valid breaks the case and returns a notify to the main function by
            //not changing the value of the flag
            if (board[line][column_i + 1] != CellState::peg || board[line][column_i + 2] != CellState::empty)
                break;
            board[line][column_i + 1] = board[line][column_i + 2];
            board[line][column_i + 2] = board[line][column_i];
            board[line][column_i] = board[line][column_i + 1];
            move_f = 1;
            currentPegs--;
            break;
        case 'L':
        case 'l':
            if (board[line][column_i - 1] != CellState::peg || board[line][column_i - 2] != CellState::empty)
                break;
            board[line][column_i - 1] = board[line][column_i - 2];
            board[line][column_i - 2] = board[line][column_i];
            board[line][column_i] = board[line][column_i - 1];
            move_f = 1;
            currentPegs--;
            break; 
        case 'U':
        case 'u':
            if (board[line - 1][column_i] != CellState::peg || board[line - 2][column_i] != CellState::empty)
                break;
            board[line - 1][column_i] = board[line - 2][column_i];
            board[line - 2][column_i] = board[line][column_i];
            board[line][column_i] = board[line - 1][column_i];
            move_f = 1;
            currentPegs--;
            break;
        case 'D':
        case 'd':
            if (board[line + 1][column_i] != CellState::peg || board[line + 2][column_i] != CellState::empty)
                break;
            board[line + 1][column_i] = board[line + 2][column_i];
            board[line + 2][column_i] = board[line][column_i];
            board[line][column_i] = board[line + 1][column_i];
            move_f = 1;           
            currentPegs--;   
            break;
    }
}

void PegSolitaire::move_6(int line, int column_i, char move_d, int c_move_6, int &move_f)
{
    int rDirection;
    char wDirection;
    // Implements movements for the 6th board
    switch (move_d)
    {
        case 'R':
        case 'r':
            if (board[line][column_i + 2] != CellState::peg || board[line][column_i + 4] != CellState::empty)
                    break;
            board[line][column_i + 2] = board[line][column_i + 4];
            board[line][column_i + 4] = board[line][column_i];
            board[line][column_i] = board[line][column_i + 2];
            move_f = 1;
            currentPegs--;
            break;
        case 'L':
        case 'l':
            if (board[line][column_i - 2] != CellState::peg || board[line][column_i - 4] != CellState::empty)
                break;
            board[line][column_i - 2] = board[line][column_i - 4];
            board[line][column_i - 4] = board[line][column_i];
            board[line][column_i] = board[line][column_i - 2];
            move_f = 1;
            currentPegs--;
            break; 
        case 'U':
        case 'u':
            // If two different moves are available the program asks the user to select a way to move
            if (board[line - 1][column_i - 1] == CellState::peg && board[line - 2][column_i - 2] == CellState::empty && 
            board[line - 1][column_i + 1] ==  CellState::peg && board[line - 2][column_i + 2] == CellState::empty)
            {
                if (c_move_6 == 0)
                {
                    cout << "Select a direction to move (r or l): ";
                    cin >> wDirection;
                }
                else // If the movement is done by computer and if there are two available movement determines the way randomly
                {
                    rDirection = rand() % 2;

                    if (rDirection == 0)
                        wDirection = 'r';
                    else
                        wDirection = 'l';
                }
                
                switch (wDirection)
                {
                case 'R':
                case 'r':
                    board[line - 1][column_i + 1] = board[line - 2][column_i + 2];
                    board[line - 2][column_i + 2] = board[line][column_i];
                    board[line][column_i] = board[line - 1][column_i + 1];
                    move_f = 1;
                    currentPegs--;
                    break;
                case 'L':
                case 'l':
                    board[line - 1][column_i - 1] = board[line - 2][column_i - 2];
                    board[line - 2][column_i - 2] = board[line][column_i];
                    board[line][column_i] = board[line - 1][column_i - 1];
                    move_f = 1;
                    currentPegs--;
                default:
                    break;
                }
                break;
            }
            else if (board[line - 1][column_i - 1] == CellState::peg && board[line - 2][column_i - 2] == CellState::empty)
            {
                board[line - 1][column_i - 1] = board[line - 2][column_i - 2];
                board[line - 2][column_i - 2] = board[line][column_i];
                board[line][column_i] = board[line - 1][column_i - 1];
                move_f = 1;
                currentPegs--;
                break; 
            }
            else if (board[line - 1][column_i + 1] == CellState::peg && board[line - 2][column_i + 2] == CellState::empty)
            {
                board[line - 1][column_i + 1] = board[line - 2][column_i + 2];
                board[line - 2][column_i + 2] = board[line][column_i];
                board[line][column_i] = board[line - 1][column_i + 1];
                move_f = 1;
                currentPegs--;
                break; 
            }
            else
                break;

        case 'D':
        case 'd':
            // If two different moves are available the program asks the user to select a way to move
            if (board[line + 1][column_i - 1] == CellState::peg && board[line + 2][column_i - 2] == CellState::empty && 
            board[line + 1][column_i + 1] == CellState::peg && board[line + 2][column_i + 2] == CellState::empty)
            {
                if (c_move_6 == 0)
                {
                    cout << "Select a direction to move (r or l): ";
                    cin >> wDirection;
                }
                else // If the movement is done by computer and if there are two available movement determines the way randomly
                {
                    rDirection = rand() % 2;

                    if (rDirection == 0)
                        wDirection = 'r';
                    else
                        wDirection = 'l';
                }
                
                switch (wDirection)
                {
                case 'r':
                case 'R':
                    board[line + 1][column_i + 1] = board[line + 2][column_i + 2];
                    board[line + 2][column_i + 2] = board[line][column_i];
                    board[line][column_i] = board[line + 1][column_i + 1];
                    move_f = 1;
                    currentPegs--;
                    break;
                case 'l':
                case 'L':
                    board[line + 1][column_i - 1] = board[line + 2][column_i - 2];
                    board[line + 2][column_i - 2] = board[line][column_i];
                    board[line][column_i] = board[line + 1][column_i - 1];
                    move_f = 1;
                    currentPegs--;
                    break;
                }
                break;
            }
            else if (board[line + 1][column_i - 1] == CellState::peg && board[line + 2][column_i - 2] == CellState::empty)
            {
                board[line + 1][column_i - 1] = board[line + 2][column_i - 2];
                board[line + 2][column_i - 2] = board[line][column_i];
                board[line][column_i] = board[line + 1][column_i - 1];
                move_f = 1;
                currentPegs--;
                break; 
            }
            else if (board[line + 1][column_i + 1] == CellState::peg && board[line + 2][column_i + 2] == CellState::empty)
            {
                board[line + 1][column_i + 1] = board[line + 2][column_i + 2];
                board[line + 2][column_i + 2] = board[line][column_i];
                board[line][column_i] = board[line + 1][column_i + 1];
                move_f = 1;
                currentPegs--;
                break; 
            }
            else
                break;
    }
}

int PegSolitaire::loadGame ()
{
    int boardType, lineSize, columnSize, lResult;
    
    char c;

    fstream savedGames;

    string text;

    savedGames.open("saved_games.txt");
    
    // Takes saved game information from a text file. If there is no data in it, notifies and ends the program
    if (savedGames >> boardType)
    {
        savedGames >> lineSize;
        savedGames >> columnSize;

        vector<vector<Cell>> board1(lineSize);

        // Constructs a vector according to size datas
        for (int i = 0; i < lineSize; i++)
            board1[i].resize(columnSize);

        // Reads information in the text
        while (savedGames >> c)
            text += c;

        board1 = takeBoard (board1, text, lineSize, columnSize);

        // Constructs a new object and the objects takes the saved board
        PegSolitaire sBoard(board1);

        sBoard.boardType = boardType;

        sBoard.currentPegs = 0;

        sBoard.setPegs();

        sBoard.game_loop();

        sBoard.outPegs();

        lResult = 1; 
    }
    else
    {
        cout << "There is no saved game!\n\n";
        lResult = 0;
    }
    
    savedGames.close();

    return lResult;
}

vector<vector<PegSolitaire::Cell>> PegSolitaire::takeBoard(vector<vector<Cell>> board1, string text, int lineSize, int columnSize)
{
    int k = 0;

    // Builds the selected saved game board
    for(int i = 0; i < lineSize; i++) 
    {
        for(int j = 0; j < columnSize; j++)
        {
            if (text[k] == 'P')
                   board1[i][j] = p;
            else if (text[k] == 'e')
                board1[i][j] = e;
            else if (text[k] == 'a')
                board1[i][j] = a;
            else
                j--;
            k++;
        }
    }
    return board1;
}

void PegSolitaire::saveGame (string boardString)
{
    string text;
    char cBlank = ' ';

    fstream savedGames;

    savedGames.open("saved_games.txt");

    savedGames << boardType << cBlank << board.size() << cBlank << board[0].size() << cBlank << boardString;

    savedGames.close();
}