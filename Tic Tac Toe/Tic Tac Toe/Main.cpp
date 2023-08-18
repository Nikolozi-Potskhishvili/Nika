#include "Main.h"
#include <iostream>
void init();
void drawGame();
int checkResult(int board[3][3]);
void makeMove(int row, int col, int (&board)[3][3],int player, char (&mat)[3][3]);
void redrawMap(int row, int col, int val, char(&mat)[3][3]);



int main() {
	std::cout<< "Hello and welcome to the Tic Tac Toe " << '\n';
	std::cout << "Press X to start game" << '\n';
	char i;
	while (true) {
		std::cin >> i;
		if (i == 'x' || i == 'X') break;
	}
	init();
	return 1;
}


void init() {
	drawGame();
	int emptyCells = 9;
	int board[3][3];
	for (int i = 0; i < 3; i++) {
		for (int k = 0; k < 3; k++) {
			board[i][k] = 0;
		}
	}
	char mat[3][3];
	for (int i = 0; i < 3; i++) {
		for (int k = 0; k < 3; k++) {
			mat[i][k] = ' ';
		}
	}
	while (emptyCells != 0) {
		int player = emptyCells % 2;
		if (player == 0) {
			std::cout << "player 2 move: choose row and column"<<'\n';
		}
		else {
			std::cout << "player 1 move: choose row and column" << '\n';
		}
		int row;
		int col;
		std::cin >> row;
		std::cin >> col;
		makeMove(row - 1,col - 1, board, player, mat);
		emptyCells--;
	}

}

void drawGame() {
	std::cout << "   |   |   " <<'\n';
	std::cout << "___|___|___" << '\n';
	std::cout << "   |   |   " << '\n';
	std::cout << "___|___|___" << '\n';
	std::cout << "   |   |   " << '\n';
	std::cout << "   |   |   " << '\n';

}

void makeMove(int row, int col, int(&board)[3][3], int player, char(&mat)[3][3]) {
	while (board[row][col] != 0) {
		std::cout << "cell already is filled, please re-enter row and column." << '\n';
		std::cin >> row;
		std::cin >> col;
	}
	if (player == 0) {
		board[row][col] = 2;
	}
	else {
		board[row][col] = 1;
	}
	redrawMap(row, col, player, mat);
	int res = checkResult(board);
	if (res == 1) {
		std::cout << "first player won!!!"<<'\n';
	}
	else if (res == 2) {
		std::cout << "second player won!!!" << '\n';
	}
}

int checkResult(int board[3][3]) {
	int winner = 0;
	int xStreak = 0;
	int yStreak = 0;
	for (int i = 0; i < 3; i++) {
		if (board[i][0] == board[i][1] == board[i][2] && board[i][0] != 0) return board[i][0];
	}
	for (int i = 0; i < 3; i++) {
		if (board[0][i] == board[i][1] == board[1][i] && board[2][i] != 0) return board[0][i];
	}
	if (board[0][0] == board[1][1] == board[2][2] && board[2][2] != 0) return board[0][0];
	if (board[0][2] == board[1][1] == board[2][0] && board[0][2] != 0) return board[0][2];

	return 0;
}	

void redrawMap(int row, int col, int val, char(&mat)[3][3]) {
	char move;
	if (val == 0) {
		move = 'O';
	}
	else {
		move = 'X';
	}
	mat[row][col] = move;
	std::cout << "   |   |   " << '\n';
	std::cout << mat[0][0]<<"__|"<<mat[0][1] << "__|"<<mat[0][2] << "__" << '\n';
	std::cout << "   |   |   " << '\n';
	std::cout << mat[1][0] << "__|" << mat[1][1] << "__|" << mat[1][2] << "__" << '\n';
	std::cout << "   |   |   " << '\n';
	std::cout << mat[2][0] << "  |" << mat[2][1] << "  |" << mat[2][2] << "  " << '\n';
}