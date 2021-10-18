/*
 *Justin Iness
 *Jason Galbraith
 *Tic Tac Toe
 *10/18/2021
 * */


#include <iostream>
#include <cstring>
using namespace std;

void printBoard(char tttboard[3][3]);
int checkWin(char board[3][3]);
bool checkTie(char board[3][3]);
void clearBoard(char board[3][3]);

int main() {
	char board[3][3];
	char input[3];
	int turn = 0;
// initilize variables
	int xWins = 0;
	int oWins = 0;
	int ties = 0;
	bool pa = true;
	while (pa) { //while play again
		clearBoard(board); // clear the bord from last round and fill with spaces
		while (checkWin(board) == 4 && checkTie(board) == false) { // while nobody has won or tied
			printBoard(board); //print board
			cout << endl << "Enter a letter followed by a number" << endl;
			cin >> (input);
			if (input[0] != 'a' && input[0] != 'b' && input[0] != 'c') {//check column is right
				cout << "Column must be an a, b, or c." << endl;
			}
			else if (input[1] != '1' && input[1] != '2' && input[1] != '3'){ // check row is right
				cout << endl << "Row must be an 1, 2, or 3." << endl;
			}
			else {
				int column = input[0] - 97; // convert char to int (asciii)
				int row = input[1] - 49;
				if (board[row][column] == ' ') { // if spot empty
					if (turn == 0) { //if x turn
						board[row][column] = 'x';
						turn++;
					}
					else { // if o turn
						board[row][column] = 'o';
						turn--;
					}
				}
				else { //not empty
					cout << endl << "There is a piece there!" << endl;
				}
			}
		} 
		printBoard(board);
		if (checkWin(board) == 0) { //x win
			cout << "X WINS!" << endl;
			xWins++;
		}
		else if (checkWin(board) == 1) { //o win
			cout << "O WINS!" << endl;
			oWins++;
       		}
		else if (checkTie(board)) { // tie
       	        	cout << "TIE!" << endl;
       	        	ties++;
		}
		cout << "X: " << xWins << " O: " << oWins << " Ties: " << ties << endl;
		cout << "Play Again?  (Y/N)" << endl; //play agian?
		cin.clear();
		cin >> input;
		if (tolower(input[0]) == 'n') { //lowercase (for safety)
			pa = false;
		}
	}
}
void printBoard(char tttboard[3][3]) { // print the board
	cout << " abc" << endl;
	for (int row = 0; row < 3; row++) {
		cout << 1 + row;
		for (int column = 0; column < 3; column++) {
		cout << tttboard[row][column];
		}
		cout << endl;
	}
}
int checkWin(char board[3][3]) { // check if anyone has won return 0 for x, 1 for o, and 4 for no wins
	//check x wins
	if (board[0][0] == 'x' && board[0][1] == 'x' && board[0][2] == 'x') {
		return 0;
	}
	if (board[1][0] == 'x' && board[1][1] == 'x' && board[1][2] == 'x') {
		return 0;
	}
	if (board[2][0] == 'x' && board[2][1] == 'x' && board[2][2] == 'x') {
		return 0;
	}
	if (board[0][0] == 'x' && board[1][0] == 'x' && board[2][0] == 'x') {
		return 0;
	}
	if (board[0][1] == 'x' && board[1][1] == 'x' && board[2][1] == 'x') {
		return 0;
	}
	if (board[0][2] == 'x' && board[1][2] == 'x' && board[2][2] == 'x') {
		return 0;
	}
	if (board[0][0] == 'x' && board[1][1] == 'x' && board[2][2] == 'x') {
		return 0;
	}
	if (board[0][2] == 'x' && board[1][1] == 'x' && board[2][0] == 'x') {
		return 0;
	}
	//o wins
	if (board[0][0] == 'o' && board[0][1] == 'o' && board[0][2] == 'o') {
		return 1;
	}
	if (board[1][0] == 'o' && board[1][1] == 'o' && board[1][2] == 'o') {
		return 1;
	}
	if (board[2][0] == 'o' && board[2][1] == 'o' && board[2][2] == 'o') {
		return 1;
	}
	if (board[0][0] == 'o' && board[1][0] == 'o' && board[2][0] == 'o') {
		return 1;
	}
	if (board[0][1] == 'o' && board[1][1] == 'o' && board[2][1] == 'o') {
		return 1;
	}
	if (board[0][2] == 'o' && board[1][2] == 'o' && board[2][2] == 'o') {
		return 1;
	}
	if (board[0][0] == 'o' && board[1][1] == 'o' && board[2][2] == 'o') {
		return 1;
	}
	if (board[0][2] == 'o' && board[1][1] == 'o' && board[2][0] == 'o') {
		return 1;
	}
	return 4;
}
bool checkTie(char board[3][3]) { // check if board is full (tie)
	for (int row = 0; row < 3; row++) {
		for (int column = 0; column < 3; column++) {
			if (board[row][column] == ' ') {
				return false;
			}
		}
	}
	return true;
}
void clearBoard(char board[3][3]) { // clear the board (fill with spaces)
	for (int row = 0; row < 3; row++) {
                for (int column = 0; column < 3; column++) {
                        board[row][column] = ' ';
                }
        }
}
