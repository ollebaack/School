#include "Tic_Tac_Toe.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cctype>
using namespace std;


int Tic_Tac_Toe::checkwin() {
	
	//check if player won

	if (square[0] == square[1] && square[1] == square[2]) {
		return 1;
	}
	else if(square[3] == square[4] && square[4] == square[5]) {
		return 1;
	}
	else if (square[6] == square[7] && square[7] == square[8]) {
		return 1;
	}
	else if (square[0] == square[3] && square[3] == square[6]) {
		return 1;
	}
	else if (square[1] == square[4] && square[4] == square[7]) {
		return 1;
	}
	else if (square[2] == square[5] && square[5] == square[8]) {
		return 1;
	}
	else if (square[0] == square[4] && square[4] == square[8]) {
		return 1;
	}
	else if (square[2] == square[4] && square[4] == square[6]) {
		return 1;
	}
	//draw // full board
	else if (square[0] != '1' && square[1] != '2' && square[2] != '3'  && square[3] != '4' && square[4] != '5' && square[5] != '6' && square[6] != '7' && square[7] != '8' && square[8] != '9' ){
		return 0;
	}
	else {
		return -1; //game over // winner
	}

}

void Tic_Tac_Toe::play()
{
	
	do
	{
			if (playerturn % 2 == 1)
				playerturn = 1;
			else
				playerturn = 2;

			if (playerturn == 1)
			{
				playermarker = 'X';
			}
			else if (playerturn == 2) {
				playermarker = 'O';
			}
			cout << "Player" << playerturn << "'s turn, set move on what number: ";
			cin >> currentmove;
			if (currentmove == '1' && square[0] == '1')
				square[0] = playermarker;
			else if (currentmove == '2' && square[1] == '2')
				square[1] = playermarker;
			else if (currentmove == '3' && square[2] == '3')
				square[2] = playermarker;
			else if (currentmove == '4' && square[3] == '4')
				square[3] = playermarker;
			else if (currentmove == '5' && square[4] == '5')
				square[4] = playermarker;
			else if (currentmove == '6' && square[5] == '6')
				square[5] = playermarker;
			else if (currentmove == '7' && square[6] == '7')
				square[6] = playermarker;
			else if (currentmove == '8' && square[7] == '8')
				square[7] = playermarker;
			else if (currentmove == '9' && square[8] == '9')
				square[8] = playermarker;

			else
			{
				cout << "Invalid move! Please choose another one." << endl;
				playerturn++;
				//cin.ignore();
				//cin.get();
			}
		
		i = checkwin();
		playerturn--; 
		Tic_Tac_Toe::print();
	} while (i == -1); 
	
		if (i == 1) {
			cout << "player " << playerturn << "won" << endl;
		}
		else {
			cout << "game draw" << endl;
		}
		//cin.ignore();
		//cin.get();
	

}

Tic_Tac_Toe::Tic_Tac_Toe()
{
	
}


void Tic_Tac_Toe::print()
{
	cout << "-------" << "\n";

	cout << "|" << square[0] << "|" << square[1] << "|" << square[2] << "|" << endl;
	cout << "|" << square[3] << "|" << square[4] << "|" << square[5] << "|" << endl;
	cout << "|" << square[6] << "|" << square[7] << "|" << square[8] << "|" << endl;
	cout << "-------" << "\n";
}

Tic_Tac_Toe::~Tic_Tac_Toe()
{
}
