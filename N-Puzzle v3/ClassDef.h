#ifndef ClassDef_H
#define ClassDef_H

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>

using namespace std;

enum Direction {Up, Down, Left, Right, None};

class NPuzzle{

public:
	NPuzzle();
	bool readFromFile(const string& fileName);
	bool writeToFile(const string& fileName) const;

	inline int getSizeRow() const { return gameBoard.getSizeRow(); };
	inline int getSizeCol() const { return gameBoard.getSizeCol(); };
	inline void print() const { gameBoard.print(); };
	inline void updateMoveCount() { moveCount++; };
	inline bool isSolved() const { return gameBoard.isSolved(); };	
	void printReport() const;
	
	bool setSize(const int& height, const int& width);
	void reset();
	
	bool move(const Direction& dir);
	void moveRandom();
	void shuffle(const int& n);
	
	Direction moveIntelligent(Direction lastIntelligentMove);
	int compareHeuristic(int heuristics[4]); //Chooses the closest one to the final position

	void solvePuzzle();
	
private:
	class Board{
	public:
		Board();
		bool readFromFile(const string& fileName);
		bool writeToFile(const string& fileName) const;

		inline int getSizeRow() const { return sizeRow; };
		inline int getSizeCol() const { return sizeCol; };
		inline int getCell(int row, int col) const { return board[row][col]; };
		void print() const;
		bool isSolved() const;
		
		void setSize(const int& height, const int& width); 
		void reset(); 

		bool moveControl(Direction direc) const;
		void move(const Direction& dir);

		int calcHeuristic(); //calculates how close the board is to the finishing position
		int calcDisstanceToFinalPos(int currRow, int currCol); //Calculates the count of moves that a cell needs to make

	private:
		int board[11][11];
		int sizeRow, sizeCol;
		int emptyRow, emptyCol;
		
		static const int border;
		static const int empty;
	};


	Board gameBoard;
	int moveCount;
};

#endif