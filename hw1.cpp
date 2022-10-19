#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

enum class cellState {empty, peg, absent};

/* Shows board types and lets one of them be selected */
int boards();

/* Constructs the game board according to selected board */
vector<vector<cellState>> board_type (int boardType, int& t_pegs);

/* Takes inputs and advances the game */
int game_loop (vector<vector<cellState>> board, int boardType, int t_pegs);

/* Implements movements or doesn't let the wrong movements implemented according to input */
vector<vector<cellState>> move(int line, int column_i, char move_d, vector<vector<cellState>> board, int &move_f);

/* Special move function for the 6th board */
vector<vector<cellState>> move_6(int line, int column_i, char move_d, vector<vector<cellState>> board, int c_move_6, int &move_f);

/* Prints the board*/
void printBoard (vector<vector<cellState>> board);

int main()
{
    int boardType, r_pegs = 0, t_pegs = 0;

    boardType = boards();

    vector<vector<cellState>> board = board_type (boardType, t_pegs);

    srand(time(0));  

    r_pegs = game_loop (board, boardType, t_pegs);
    

    /* Calculates the score according to remaninig pegs (min 0, max 100. If there are more pegs at the beginnig, each remaning pegs decrease the score lesser )*/
    cout << endl << r_pegs << " pegs left. "
         << "Your score is " << 100 - ((100.0 / t_pegs) * r_pegs) << " (out of 100)" << endl;
}

int boards()
{
    int boardType;

    cellState e = cellState::empty, p = cellState::peg, a = cellState::absent;

    vector<vector<cellState>> board_1
    {
        {a, a, p, p, p, a, a},
        {a, p, p, p, p, p, a},
        {p, p, p, e, p, p, p},
        {p, p, p, p, p, p, p},
        {p, p, p, p, p, p, p},
        {a, p, p, p, p, p, a},
        {a, a, p, p, p, a, a}
    };

    cout << "Board 1.\n\n";

    for(int i = 0; i < board_1.size(); i++)
    {
        for(int j = 0; j < board_1[i].size(); j++)
            {
                if (board_1[i][j] == e)
                    cout << ".";
                else if (board_1[i][j] == p)
                    cout << "P";
                else if (board_1[i][j] == a)
                    cout << " ";
                    
                cout << " ";
            }
        cout << endl;
    }
    cout << "\n\n";

    vector<vector<cellState>> board_2
    {
        {a, a, a, p, p, p, a, a, a},
        {a, a, a, p, p, p, a, a, a},
        {a, a, a, p, p, p, a, a, a},
        {p, p, p, p, p, p, p, p, p},
        {p, p, p, p, e, p, p, p, p},
        {p, p, p, p, p, p, p, p, p},
        {a, a, a, p, p, p, a, a, a},
        {a, a, a, p, p, p, a, a, a},
        {a, a, a, p, p, p, a, a, a}
    };

    cout << "Board 2.\n\n";

    for(int i = 0; i < board_2.size(); i++)
    {
        for(int j = 0; j < board_2[i].size(); j++)
            {
                if (board_2[i][j] == e)
                    cout << ".";
                else if (board_2[i][j] == p)
                    cout << "P";
                else if (board_2[i][j] == a)
                    cout << " ";
                    
                cout << " ";
            }
            cout << " ";
        cout << endl;
    }
    cout << "\n\n";


    vector<vector<cellState>> board_3
    {
        {a, a, p, p, p, a, a, a},
        {a, a, p, p, p, a, a, a},
        {a, a, p, p, p, a, a, a},
        {p, p, p, p, p, p, p, p},
        {p, p, p, e, p, p, p, p},
        {p, p, p, p, p, p, p, p},
        {a, a, p, p, p, a, a, a},
        {a, a, p, p, p, a, a, a}
    };

    cout << "Board 3.\n\n";

    for(int i = 0; i < board_3.size(); i++)
    {
        for(int j = 0; j < board_3[i].size(); j++)
            {
                if (board_3[i][j] == e)
                    cout << ".";
                else if (board_3[i][j] == p)
                    cout << "P";
                else if (board_3[i][j] == a)
                    cout << " ";
                    
                cout << " ";
            }
            cout << " ";
        cout << endl;
    }
    cout << "\n\n";


    vector<vector<cellState>> board_4
    {
        {a, a, p, p, p, a, a},
        {a, a, p, p, p, a, a},
        {p, p, p, p, p, p, p},
        {p, p, p, e, p, p, p},
        {p, p, p, p, p, p, p},
        {a, a, p, p, p, a, a},
        {a, a, p, p, p, a, a}
    };

    cout << "Board 4.\n\n";

    for(int i = 0; i < board_4.size(); i++)
    {
        for(int j = 0; j < board_4[i].size(); j++)
            {
                if (board_4[i][j] == e)
                    cout << ".";
                else if (board_4[i][j] == p)
                    cout << "P";
                else if (board_4[i][j] == a)
                    cout << " ";
                    
                cout << " ";
            }
            cout << " ";
        cout << endl;
    }
    cout << "\n\n";


    vector<vector<cellState>> board_5
    {
        {a, a, a, a, p, a, a, a, a},
        {a, a, a, p, p, p, a, a, a},
        {a, a, p, p, p, p, p, a, a},
        {a, p, p, p, p, p, p, p, a},
        {p, p, p, p, e, p, p, p, p},
        {a, p, p, p, p, p, p, p, a},
        {a, a, p, p, p, p, p, a, a},
        {a, a, a, p, p, p, a, a, a},
        {a, a, a, a, p, a, a, a, a}
    };

    cout << "Board 5.\n\n";

    for(int i = 0; i < board_5.size(); i++)
    {
        for(int j = 0; j < board_5[i].size(); j++)
            {
                if (board_5[i][j] == e)
                    cout << ".";
                else if (board_5[i][j] == p)
                    cout << "P";
                else if (board_5[i][j] == a)
                    cout << " ";
                    
                cout << " ";
            }
                cout << " ";
            cout << " ";
        cout << endl;
    }
    cout << "\n\n";

    vector<vector<cellState>> board_6
    {
        {a, a, a, a, e, a, a, a, a},
        {a, a, a, p, a, p, a, a, a},
        {a, a, p, a, p, a, p, a, a},
        {a, p, a, p, a, p, a, p, a}, 
        {p, a, p, a, p, a, p, a, p}
    };

    cout << "Board 6.\n\n";

    for(int i = 0; i < board_6.size(); i++)
    {
        for(int j = 0; j < board_6[i].size(); j++)
            {
                if (board_6[i][j] == e)
                    cout << ".";
                else if (board_6[i][j] == p)
                    cout << "P";
                else if (board_6[i][j] == a)
                    cout << " ";
                    
                cout << " ";
            }
            cout << " ";
        cout << endl;
    }
    cout << "\n\n";

    cout << "Select a number to determine the board type: ";
    

    while (1)
    {
        cin >> boardType;  
        if (boardType >=1 && boardType <= 6)
            break;
        else
            cout << "Invalid board type! Please enter again: ";
    }

    
    cout << "\n\n\n";

    return boardType;
}

vector<vector<cellState>> board_type (int boardType, int& t_pegs)
{
    cellState e = cellState::empty, p = cellState::peg, a = cellState::absent;

    vector<vector<cellState>> board;

    switch (boardType) /* Selects a board type according to sended value */
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
            {a, a, a, a, p, p, p, a, a}
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
            {a, a, a, a, a, p, p, p, a, a, a}
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
            {a, a, a ,a, p, p, p, a, a, a}
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
            {a, a, a, a, p, p, p, a, a}
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
            {a, a, a, a, a, a, p, a, a, a, a}
        };
        break;
    case 6:
        board = 
        {
            {a, a, a, a, a, a, a, a, a, a, a},
            {a, a, a, a, a, a, e, a, a, a, a},
            {a, a, a, a, a, p, a, p, a, a, a},
            {a, a, a, a, p, a, p, a, p, a, a},
            {a, a, a, p, a, p, a, p, a, p, a}, 
            {a, a, p, a, p, a, p, a, p, a, p}
        };
        break;  
    }

    printBoard (board);  /* Prints the selected board */

    for(int i = 0; i < board.size(); i++) /* Calculates how many peg are there in the selected board */
    {
        for(int j = 0; j < board[i].size(); j++)
            if (board[i][j] == cellState::peg)
                t_pegs++;
    }

    return board;
}

int game_loop (vector<vector<cellState>> board, int boardType, int t_pegs)
{
    int line, column_i, s_c_direction, move_f, game = 0, r_pegs = 0, c_move_6 = 0;
    char column, move_d;

    cout << "Specify a cell and choose a direction (r, l, u, d) to make a move (b2r):\n"
         << "If you want to make computer move enter a0a\n"
         << "If you want to quit enter z0z\n-";

    while (game == 0)
    {
        game = 1;
        move_f = 0;

        /* Checks if there is any remaining peg in the board. If there is continues the game */
        if (boardType == 6)
        {      
            for(int i = 0; i < board.size() - 1; i++) 
            {
                for(int j = 0; j < board[i].size() - 1; j++)
                    if ((board[i][j] == cellState::peg && board[i][j] == board[i][j + 2]) || (board[i][j] == cellState::peg && board[i][j] == board[i + 1][j + 1])
                    || (board[i][j] == cellState::peg && board[i][j] == board[i + 1][j - 1]))
                    {
                        game = 0;
                        break;
                    }
                if (game == 0)
                    break;
            }
        }
        else
        {
            for(int i = 0; i < board.size() - 1; i++) 
            {
                for(int j = 0; j < board[i].size() - 1; j++)
                    if ((board[i][j] == cellState::peg && board[i][j] == board[i][j + 1]) || (board[i][j] == cellState::peg && board[i][j] == board[i + 1][j]))
                    {
                        game = 0;
                        break;
                    }
                if (game == 0)
                    break;
            }
        }
        
        /* Else breaks the loop and gives the highest score */
        if (game == 1)
        {
            cout << "There is no movement left\n\n";
            break;
        }

        cout << "Enter a move: ";
        cin >> column >> line >> move_d;

        /* Computer move section */
        if ((column == 'a' || column == 'A') && line == 0 && (move_d == 'a' || move_d == 'A'))
        {
            while (move_f == 0)
            {
                line = (rand() % (board.size() - 1)) + 1;
                column_i = (rand() % (board[0].size() - 2)) + 2;
                if (board[line][column_i] != cellState::peg)
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

                /* These statements avoid the program being crashed because of segmentation fault */
                if ((line == (board.size() - 2)) && (move_d == 'd' || move_d == 'D') || (line == (board.size() - 1)) && (move_d == 'd' || move_d == 'D') ||
                (line == 2) && (move_d == 'u' || move_d == 'U') || (line == 1) && (move_d == 'u' || move_d == 'U') ||
                (column_i == (board[0].size() - 2)) && (move_d == 'r' || move_d == 'R') || (column_i == (board[0].size() - 1)) && (move_d == 'r' || move_d == 'R') ||
                (column_i == 3) && (move_d == 'l' || move_d == 'L') || (column_i == 2) && (move_d == 'l' || move_d == 'L'))
                    continue;

                if (boardType == 6)
                    {
                        c_move_6 = 1;
                        board = move_6(line, column_i, move_d, board, c_move_6, move_f);
                        c_move_6 = 0;
                    }
                else
                    board = move(line, column_i, move_d, board, move_f);

                if (move_f == 1)
                    printBoard (board);
            }
            
        }
        /* Ends the game if the specific entry is entered */
        else if ((column == 'z' || column == 'Z') && line == 0 && (move_d == 'z' || move_d == 'Z'))
            break;
        else
        {
            /* If the movement letter is entered wrong the program asks the user again */
            if (move_d != 'r' && move_d != 'R' && move_d != 'l' && move_d != 'L' && move_d != 'u' && move_d != 'U' && move_d != 'd' && move_d != 'D')
            {
                cout << "Invalid move! Type again.\n";
                continue;
            }

            /* Converts the entered movement to int type */
            if (column >= 'A' && column <= 'Z')
                column_i = (int)column -63;
            else
                column_i = (int)column -95; 

            /* These statements avoid the program being crashed because of segmentation fault */
            if ((line == (board.size() - 2)) && (move_d == 'd' || move_d == 'D') || (line == (board.size() - 1)) && (move_d == 'd' || move_d == 'D') ||
            (line == 2) && (move_d == 'u' || move_d == 'U') || (line == 1) && (move_d == 'u' || move_d == 'U') ||
            (column_i == (board[0].size() - 2)) && (move_d == 'r' || move_d == 'R') || (column_i == (board[0].size() - 1)) && (move_d == 'r' || move_d == 'R') ||
            (column_i == 3) && (move_d == 'l' || move_d == 'L') || (column_i == 2) && (move_d == 'l' || move_d == 'L'))
            {
                cout << "Invalid move! Type again.\n";
                continue;
            }
            
            /* If the user enters a not valid cell to move the program asks the user again */
            if (line >= board.size() || line < 1 || column_i >= board[0].size() || column_i < 2)
            {
                cout << "Invalid cell! Type again.\n";
                continue;
            }
            /* If the user selects a cell without a peg the program asks the user again */
            else if (board[line][column_i] != cellState::peg)
            {
                cout << "Selected cell has no peg! Type again.\n";
                continue;
            }     

            if (boardType == 6) /* If the board type is 6th one the program calls the special move function */
                board = move_6(line, column_i, move_d, board, c_move_6, move_f);
            else
                board = move(line, column_i, move_d, board, move_f);

            /* If the intended movement is valid and implemented the program prints the current board */
            if (move_f == 1)
            {
                printBoard (board); 
            }
            else
                cout << "Invalıd move! Type again\n";
        }
        
    }

    for(int i = 0; i < board.size(); i++) /* Finds the number of the remaining pegs*/
    {
        for(int j = 0; j < board[i].size(); j++)
        {    
            if (board[i][j] == cellState::peg)
                r_pegs++;
        }
    }

    return r_pegs;
}

vector<vector<cellState>> move(int line, int column_i, char move_d, vector<vector<cellState>> board, int &move_f)
{

    /* Checks if the movement is valid then implements the movement according to sended direction*/
    switch (move_d)
    {
        case 'R':
        case 'r':
            /* These if statements checks the movement validity. If the movement is not valid breaks the case and returns a notify to the main function by
            not changing the value of the flag */
            if (board[line][column_i + 1] != cellState::peg || board[line][column_i + 2] != cellState::empty)
                break;
            board[line][column_i + 1] = board[line][column_i + 2];
            board[line][column_i + 2] = board[line][column_i];
            board[line][column_i] = board[line][column_i + 1];
            move_f = 1;
            break;
        case 'L':
        case 'l':
            if (board[line][column_i - 1] != cellState::peg || board[line][column_i - 2] != cellState::empty)
                break;
            board[line][column_i - 1] = board[line][column_i - 2];
            board[line][column_i - 2] = board[line][column_i];
            board[line][column_i] = board[line][column_i - 1];
            move_f = 1;
            break; 
        case 'U':
        case 'u':
            if (board[line - 1][column_i] != cellState::peg || board[line - 2][column_i] != cellState::empty)
                break;
            board[line - 1][column_i] = board[line - 2][column_i];
            board[line - 2][column_i] = board[line][column_i];
            board[line][column_i] = board[line - 1][column_i];
            move_f = 1;
            break;
        case 'D':
        case 'd':
            if (board[line + 1][column_i] != cellState::peg || board[line + 2][column_i] != cellState::empty)
                break;
            board[line + 1][column_i] = board[line + 2][column_i];
            board[line + 2][column_i] = board[line][column_i];
            board[line][column_i] = board[line + 1][column_i];
            move_f = 1;              
            break;
    }
    
    return board;
}

vector<vector<cellState>> move_6(int line, int column_i, char move_d, vector<vector<cellState>> board, int c_move_6, int &move_f)
{
    int rDirection;
    char wDirection;
    /* Implements movements for the 6th board */
    switch (move_d)
    {
        case 'R':
        case 'r':
            if (board[line][column_i + 2] != cellState::peg || board[line][column_i + 4] != cellState::empty)
                break;
            board[line][column_i + 2] = board[line][column_i + 4];
            board[line][column_i + 4] = board[line][column_i];
            board[line][column_i] = board[line][column_i + 2];
            move_f = 1;
            break;
        case 'L':
        case 'l':
            if (board[line][column_i - 2] != cellState::peg || board[line][column_i - 4] != cellState::empty)
                break;
            board[line][column_i - 2] = board[line][column_i - 4];
            board[line][column_i - 4] = board[line][column_i];
            board[line][column_i] = board[line][column_i - 2];
            move_f = 1;
            break; 
        case 'U':
        case 'u':
            /* If two different moves are available the program asks the user to select a way to move */
            if (board[line - 1][column_i - 1] == cellState::peg && board[line - 2][column_i - 2] == cellState::empty && 
            board[line - 1][column_i + 1] ==  cellState::peg && board[line - 2][column_i + 2] == cellState::empty)
            {
                if (c_move_6 == 0)
                {
                    cout << "Select a direction to move (r or l): ";
                    cin >> wDirection;
                }
                else /* If the movement is done by computer and if there are two available movement determines the way randomly */
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
                    break;
                case 'L':
                case 'l':
                    board[line - 1][column_i - 1] = board[line - 2][column_i - 2];
                    board[line - 2][column_i - 2] = board[line][column_i];
                    board[line][column_i] = board[line - 1][column_i - 1];
                    move_f = 1;
                default:
                    break;
                }
                break;
            }
            else if (board[line - 1][column_i - 1] == cellState::peg && board[line - 2][column_i - 2] == cellState::empty)
            {
                board[line - 1][column_i - 1] = board[line - 2][column_i - 2];
                board[line - 2][column_i - 2] = board[line][column_i];
                board[line][column_i] = board[line - 1][column_i - 1];
                move_f = 1;
                break; 
            }
            else if (board[line - 1][column_i + 1] == cellState::peg && board[line - 2][column_i + 2] == cellState::empty)
            {
                board[line - 1][column_i + 1] = board[line - 2][column_i + 2];
                board[line - 2][column_i + 2] = board[line][column_i];
                board[line][column_i] = board[line - 1][column_i + 1];
                move_f = 1;
                break; 
            }
            else
                break;

        case 'D':
        case 'd':
            /* If two different moves are available the program asks the user to select a way to move */
            if (board[line + 1][column_i - 1] == cellState::peg && board[line + 2][column_i - 2] == cellState::empty && 
            board[line + 1][column_i + 1] == cellState::peg && board[line + 2][column_i + 2] == cellState::empty)
            {
                if (c_move_6 == 0)
                {
                    cout << "Select a direction to move (r or l): ";
                    cin >> wDirection;
                }
                else /* If the movement is done by computer and if there are two available movement determines the way randomly */
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
                    break;
                case 'l':
                case 'L':
                    board[line + 1][column_i - 1] = board[line + 2][column_i - 2];
                    board[line + 2][column_i - 2] = board[line][column_i];
                    board[line][column_i] = board[line + 1][column_i - 1];
                    move_f = 1;
                    break;
                }
                break;
            }
            else if (board[line + 1][column_i - 1] == cellState::peg && board[line + 2][column_i - 2] == cellState::empty)
            {
                board[line + 1][column_i - 1] = board[line + 2][column_i - 2];
                board[line + 2][column_i - 2] = board[line][column_i];
                board[line][column_i] = board[line + 1][column_i - 1];
                move_f = 1;
                break; 
            }
            else if (board[line + 1][column_i + 1] == cellState::peg && board[line + 2][column_i + 2] == cellState::empty)
            {
                board[line + 1][column_i + 1] = board[line + 2][column_i + 2];
                board[line + 2][column_i + 2] = board[line][column_i];
                board[line][column_i] = board[line + 1][column_i + 1];
                move_f = 1;
                break; 
            }
            else
                break;
    }
    return board;
}

void printBoard (vector<vector<cellState>> board) /* This function prints the board */
{
    cellState e = cellState::empty, p = cellState::peg, a = cellState::absent;
    
    for(int i = 0; i < board.size(); i++) /* Prints the selected board */
    {
        for(int j = 0; j < board[i].size(); j++)
        {
            if (i == 0)
                switch (j)
                {
                    case 0:
                        cout << ' ';
                            break;
                    case 1:
                        cout << ' ';
                        break;
                    case 2:
                        cout << 'a';
                        break;
                    case 3:
                        cout << 'b';
                        break;
                    case 4:
                        cout << 'c';
                        break;
                    case 5:
                        cout << 'd';
                        break;
                    case 6:
                        cout << 'e';
                        break;
                    case 7:
                        cout << 'f';
                        break;
                    case 8:
                        cout << 'g';
                        break;
                    case 9:
                        cout << 'h';
                        break;
                    case 10:
                        cout << 'i';
                        break;
            }
            else if (j == 0)
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