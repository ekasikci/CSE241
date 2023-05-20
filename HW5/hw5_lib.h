#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<chrono>
#include<thread>

using namespace std;

namespace games{
	class BoardGame2D
	{
	public:
		virtual void getInput() final; // Game menu
		static void playVector(vector<BoardGame2D*> toPlay); // Takes BoardGame2D pointer vector and plays tha games
	private:
		virtual int playUser(string input) = 0 ; // Takes string from the user and plays accorgind this string
		virtual int boardScore() = 0; // Calculates the game score
		virtual void playUser() final; // Takes string from the user until the game ends
		virtual void playAuto() = 0; // Computer makes one valid move in the game
		virtual void playAutoAll() final; // Computer plays the game until it ends
		virtual void print() = 0; // Prints the game board
		virtual bool isStringValid(string &input) const = 0; // Checks if the string is valid
		virtual bool endGame() = 0; // Returns true if the game has ended
		virtual void initialize() = 0; // Initializes the game board
		friend ostream& operator <<(ostream& outputStream, BoardGame2D* x){x->initialize(); x->print(); return outputStream;}
	};

	class PegSolitaire : public BoardGame2D
	{
	public:
	private:
		enum class cell {empty, peg, absent};
		cell e = cell::empty, p = cell::peg, a = cell::absent;
		virtual int playUser(string input); // 
		virtual void playAuto();
		int boardScore();
		void print(); 
		void initialize();  
		bool move(int lineI, int columnI, char move_d);
		bool isStringValid(string &input) const;
		bool endGame();

		vector<vector<cell>> board;
	};

	class EightPuzzle : public BoardGame2D
	{
	public:
	private:
		virtual int playUser(string input);
		virtual void playAuto();
		int boardScore();
		void shuffle(); // Shuffles the board to get random boards
		void print();
		void initialize();
		bool move(int lineI, int columnI, char move_d);
		bool isStringValid(string &input) const;
		bool endGame();

		vector<vector<int>> board;
	};

	class Klotski : public BoardGame2D
	{
	public:
	private:
		virtual int playUser(string input);
		virtual void playAuto();
		int boardScore();
		void initialize();
		void print();
		bool move(int lineI, int columnI, char move_d);
		bool isStringValid(string &input) const;
		bool endGame();

		vector<vector<char>> board;
	};
}