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
void newGame(char board[3][3]);
void displayBoard(char board[3][3]);
void displayBoard(char board[3][3], string player1, string player2, int player1_score, int player2_score);
bool makeAImove(char board[3][3], char symbol);
bool makeMove(char board[3][3], int position, char symbol);
int check_win_move(char board[3][3]);
void displayWinMessage(string player_name);
void displayQuitMessage(void);


int main()
{
	char key = '-';
	int position;
	int current_player;
	char current_player_symbol;
	int using_AI = 0;
	string player1, player2;
	int player1score = 0;
	int player2score = 0;
	bool change_turn = false;

	char board[3][3] = { { ' ', ' ', ' '}, { ' ', ' ', ' '}, { ' ', ' ', ' '}, };

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


	// Determine which player should use X or O
	if (rand() % 2 == 0)
		current_player_symbol = 'X';
	else
		current_player_symbol = 'O';

	// Determine who plays first
	current_player = rand() % 2 + 1;
	if (current_player == 1)
		cout << player1 << " plays first (" << current_player_symbol << ").\n";
	else
		cout << player2 << " plays first (" << current_player_symbol << ").\n";
	


	// Start game loop
	do
	{
		displayHeader();
		displayBoard(board, player1, player2, player1score, player2score);

		// if current player is human, ask for position
		// if not, generate an inteligent move.
		if (current_player == 1)
			cout << "\n " << player1 << " (1-9)? ";
		else
			cout << "\n " << player2 << " (1-9)? ";
		

		if (using_AI and (current_player == 2))
		{
			//sleep here
			if (makeAImove(board, current_player_symbol))
			{
				change_turn = true;
				if (check_win_move(board))
				{
					if (current_player == 1)
					{
						player1score++;
						displayWinMessage(player1);
					}
					else
					{
						player2score++;
						displayWinMessage(player2);
					}
					// TODO pause here

					change_turn = false;
					newGame(board);
				}
				change_turn = true;
			}
			// if board is full we should not be here in the first place:
			else
				cout << "\n\n\"Something wrong is not right\" (J.A.)\n"; 
		}
		else
		{
			key = _getch();
			clearScreen();

			switch (key)
			{
			case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
				position = key - '0';  // convert a numeric character to int using its 'face value'
				if (makeMove(board, position, current_player_symbol))
				{
					if (check_win_move(board))
					{
						if (current_player == 1)
							player1score++;
						else
							player2score++;
						
						// TODO pause here

						change_turn = false;
						newGame(board);
					}
					change_turn = true;
				}
				else
					change_turn = false;
				
				break;

			default:
				if (key == 27)
					return -1;

				change_turn = false;
				cout << "\n Please choose an empty position, between 1 and 9.";
				break;
			}
		}

		if (change_turn)
		{
			if (current_player == 1)
				current_player = 2;
			else
				current_player = 1;

			if (current_player_symbol == 'X')
				current_player_symbol = 'O';
			else
				current_player_symbol = 'X';
		}

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

void newGame(char board[3][3])
{
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
			board[i][j] = ' ';
	}
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
		else if (i == 2)
		{
			cout << "      " << setfill('0') << setw(3) << player2_score << " - " << player2 << endl;
		}
	}
	cout << endl;
}

bool makeAImove(char board[3][3], char symbol)
{
	int position;
	bool is_full = true;

	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			if (board[i][j] == ' ')
				is_full = false;
		}
	}
	
	if (is_full)
	{
		cout << "The board is full, no more moves available.";
		return false;
	}

	do
	{
		position = rand() % 9 + 1;
	} while (not makeMove(board, position, symbol));
	
	return true;
}

bool makeMove(char board[3][3], int position, char symbol)
{
	int line, col;

	line = (position-1) / 3;
	col = (position-1) % 3;

	//cout << "L/C:" << line << "/" << col << endl;

	if (board[line][col] == ' ')
	{
		board[line][col] = symbol;
		return true;
	}
	else
	{
		cout << "\nThat position is already taken. Please play again.\n";
		return false;
	}		
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

	// TODO - if not winning but board is full, we have a draw (-1).

	return 0; // not winning yet...
}

void displayWinMessage(string player_name)
{
	cout << "\n\nCongratulation! You won this round!\n";
}


void displayQuitMessage(void)
{
	cout << "\n\nSee you soon!\n\n\n";
}
