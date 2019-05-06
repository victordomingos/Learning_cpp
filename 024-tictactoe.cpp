// TicTacToe
// 2019-05
// Victor Domingos

#include <iostream>
#include <conio.h>
#include <string>
#include <time.h>

using namespace std;

const string ai_names[9] = { "Elisa", "Sophie", "HAL 2000", "VIKI", "Sonny",
							 "Tardis", "KITT", "R2D2", "3PO" };

// Game type menu (AI or Human opponent?)
int choose_opponent(void)
{
	char k;

	do
	{
		cout << "Please chose the type of your opponent:\n";
		cout << "  A) A.I. (computer)\n";
		cout << "  H) Human\n";

		k = _getch();
		
		switch (toupper(k))
		{
		case 'A':
			return rand() % 9;
			break;
		case 'H':
			return -2;
			break;
		default:
			if (k == 27)
				return -1;
			break;
		}
	} while (k != 27);

	return -1;
}


int check_win_move(char board[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == board[i][1] and board[i][0] == board[i][2])
			return 1; //win!!
		if (board[0][i] == board[1][i] and board[0][i] == board[2][i])
			return 1; //win!!
	}

	if (board[0][0] == board[1][1] and board[1][1] == board[2][2])
		return 1; //win!!
	if (board[2][0] == board[1][1] and board[1][1] == board[0][2])
		return 1; //win!!

	return 0; // not winning yet...
}


void displayBoard(char board[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << board[i][j];
		}
		cout << endl;
	}
}


void displayQuitMessage(void)
{
	cout << "\nSee you soon!\n\n";
}


int main()
{
	char key;
	int current_player;
	int using_AI = 0;
	string player1, player2;

	char board[3][3] = {
		{ ' ', ' ', ' '},
		{ ' ', ' ', ' '},
		{ ' ', ' ', ' '},
	};

	srand(time(NULL));

	// Welcome text
	cout << "Welcome to yet another incredible TicTacToe game!\n\n";


	cout << "Please enter first player's name:\n -> ";
	getline(cin, player1);
	cout << "\nHi, " << player1 << "!\n\n";


	using_AI = choose_opponent();
	if (using_AI == -1)
	{
		displayQuitMessage();
		return 0;
	}
	else if (using_AI == -2)
	{
		cout << "\nPlease enter the second player's name:\n -> ";
		getline(cin, player2);
		cout << "\nHi, " << player2 << "!\n\n";
	}
	else
	{
		player2 = ai_names[using_AI];
		cout << "\nPlaying against " << player2 << ", one of most famous TicTactToe players in the world...\n\n" << endl;
	}

	current_player = rand() % 2 + 1;
	// Determine who plays first
	if (current_player == 1)
		cout << player1 << " plays first.\n";
	else
		cout << player2 << " plays first.\n";


	// Start game loop
	do
	{
		displayBoard(board);
		key = _getch();

		// display board

		// if current player is human, ask for position
		// else generate an inteligent move.

		// after a user makes a movement, check if he/she wins



		// Change turns, now the other player must make a move.

	} while (key != 27);
	
	displayQuitMessage();
	return 0;
}
