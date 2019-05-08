// TicTacToe
// 2019-05
// Victor Domingos

#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>
#include <time.h>


using namespace std;

const string ai_names[9] = { "Elisa", "Sophie", "HAL 2000", "VIKI", "Sonny",
							 "Tardis", "KITT", "R2D2", "3PO" };


void clearScreen(void);
void displayWelcome(void);
int choose_opponent(void);
void displayHeader(void);
void displayBoard(char board[3][3]);
void displayBoard(char board[3][3], string player1, string player2, int player1_score, int player2_score);
int check_win_move(char board[3][3]);
void displayQuitMessage(void);



int main()
{
	char key;
	int current_player;
	int using_AI = 0;
	string player1, player2;
	int player1score = 0;
	int player2score = 0;
	bool change_turn = false;

	char board[3][3] = {{ ' ', ' ', ' '}, { ' ', ' ', ' '}, { ' ', ' ', ' '},};
	
	/*
	char board[3][3] = { { 'X', ' ', 'O'}, 
						 { '4', ' ', 'X'}, 
						 { 'O', 'O', 'O'}, };
	*/
	srand(time(NULL));


	displayWelcome();

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
		displayHeader();
		displayBoard(board, player1, player2, player1score, player2score);
		
		if (current_player == 1)
			cout << "\n " << player1 << " (1-9)? ";
		else
			cout << "\n " << player2 << " (1-9)? ";

		key = _getch();

		clearScreen();

		switch (key)
		{
		case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
			// if current player is human, ask for position
			// else generate an inteligent move.
			check_win_move(board);
			change_turn = true;
			break;
		
		default:
			if (key == 27)
				return -1;
			change_turn = false;
			cout << "\n Please choose an empty position, between 1 and 9.";
			break;
		}

		if (change_turn and current_player == 1)
			current_player = 2;
		else if (change_turn)
			current_player = 1;
			
	} while (key != 27);

	displayQuitMessage();
	return 0;
}


void clearScreen(void)
{
	for (size_t i = 0; i < 5; i++)
		cout << "\n\n\n\n\n\n\n\n\n\n";
}

void displayWelcome(void)
{
	char example_board[3][3] = { { '1', '2', '3'},
								 { '4', '5', '6'},
								 { '7', '8', '9'}, };
	// Welcome text
	cout << "\n\nWelcome to yet another incredible TicTacToe game!\n\n\n\n";

	cout << "Here's how it works:\n\n\n";
	cout << "  - Each player either gets a bag full of O's, or a bag full of X's.\n\n";
	cout << "  - At each turn, the player chooses an empty board position for the\n    next move.\n\n";
	cout << "  - The first player who manages to get 3 aligned positions wins.\n\n";
	cout << "  - Those 3 positions can be aligned in vertical, horizontal or diagonal\n    directions.\n\n";
	cout << "\nPress any key to continue...";
	
	_getch();
	
	clearScreen();
	cout << "\n\nJust one more thing:\n\n\n";
	cout << " - Each board postion has its own number. So, in order to make a move,\n   you just need to press the corresponding key.\n\n";
	cout << "Now, let's see which number corresponds to each position i the board:";

	displayBoard(example_board);
}


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


void displayHeader()
{
	// Welcome text
	cout << "\n_ _ _ The amazing NPK TicTacToe game! _ _ _\n\n\n\n";
}


// Display board without score
void displayBoard(char board[3][3])
{
	for (size_t i = 0; i < 5; i++)
		cout << "\n\n";

	for (size_t i = 0; i < 3; i++)
	{
		cout << "   " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << endl;
		if (i < 2)
			cout << "  -----------\n";
	}
	cout << endl;
}


// Display board with score
void displayBoard(char board[3][3], string player1, string player2, int player1_score, int player2_score)
{
	for (size_t i = 0; i < 5; i++)
		cout << "\n\n";

	for (size_t i = 0; i < 3; i++)
	{
		cout << "   " << board[i][0] << " | " << board[i][1] << " | " << board[i][2];
		
		if (i == 0)
		{
			cout << "\n  ----------- ";
			cout << "    " << "SCORE:\n";
		}

		else if (i == 1)
		{
			cout << "\n  -----------";
			cout << "     " << setfill('0') << setw(3) << player1_score << " - " << player1 << endl;
		}
		else if (i==2)
		{ 
			cout << "      " << setfill('0') << setw(3) << player2_score << " - " << player2  << endl;
		}
	}
	cout << endl;
}


int check_win_move(char board[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		// Check all horizontal lines
		if (board[i][0] != ' ' and board[i][0] == board[i][1] and board[i][0] == board[i][2])
			return 1; //win!!
		
		// Check all vertical lines
		if (board[i][0] != ' ' and board[0][i] == board[1][i] and board[0][i] == board[2][i])
			return 1; //win!!
	}

	// Check both diagonal lines
	if (board[0][0] != ' ' and board[0][0] == board[1][1] and board[1][1] == board[2][2])
		return 1; //win!!
	if (board[2][0] != ' ' and board[2][0] == board[1][1] and board[1][1] == board[0][2])
		return 1; //win!!

	return 0; // not winning yet...
}


void displayQuitMessage(void)
{
	cout << "\n\nSee you soon!\n\n\n";
}
