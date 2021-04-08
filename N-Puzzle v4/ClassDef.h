#ifndef ClassDef_H
#define ClassDef_H

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<vector>

using namespace std;

enum Direction {Up, Down, Left, Right, None};

class NPuzzle{

public:
	NPuzzle();
	NPuzzle(vector< vector<int> > vector, int eRow, int eCol);
	bool readFromFile(const string& fileName);
	bool writeToFile(const string& fileName) const;

	inline int getSizeRow() const { return gameBoard.getSizeRow(); };
	inline int getSizeCol() const { return gameBoard.getSizeCol(); };
	inline void print() const { gameBoard.print(); };
	inline bool isSolved() const { return gameBoard.isSolved(); };	
	void printReport() const;
	
	bool setSize(const int& height, const int& width);
	void reset();
	
	bool move(const Direction& dir);
	void moveRandom();
	void shuffle(const int& n);

	void solvePuzzle();
	friend ostream& operator <<(ostream& out, const NPuzzle& puzzle);
	friend istream& operator >>(istream& in, NPuzzle& puzzle);

private:
	class Board{
	public:
		Board();
		Board(vector< vector<int> > vector, int eRow, int eCol);
		bool readFromFile(const string& fileName);
		bool writeToFile(const string& fileName) const;

		inline int getSizeRow() const { return board.size()-2; };
		inline int getSizeCol() const { return board[1].size()-2; };		
		inline int getMoveCount() const { return moveCount; };
		inline Direction getLastMove() const { return lastMove; };
		inline static int getBoardCount() { return boardCount; };

		void print() const;
		bool isSolved() const;
		
		void setSize(const int& height, const int& width); 
		void reset();
		inline void resetMoveCount() { moveCount=0; };

		bool moveControl(const Direction& direc) const;
		void move(const Direction& dir);

		inline bool operator ==(const Board& other) const { return board == other.board; };
		inline int operator ()(const int& row, const int&col) const { return board[row][col]; };

	private:
		vector< vector<int> > board;
		int emptyRow, emptyCol;
		
		int moveCount;
		Direction lastMove;
		
		static int boardCount;
		static const int border;
		static const int empty;
	};

	Board gameBoard;
	vector<Board> boardVector;
};

#endif