// Toy exercise 2 - a little game on multiplication.
// 2019-04-17
// Victor Domingos

#include <iostream>
#include <time.h>

using namespace std;

int main()
{
	int tries = 6;
	int score = 0;
	int correct_answers = 0;

	string line1 = "   ,--------------------------------------.\n";
	string line2 = "  |                                        |\n";
	string line3 = "  |   The Amazing NPK Times Tables Game!   |\n";
	string line4 = "  |                                        |\n";
	string line5 = "   `--------------------------------------'\n";

	cout << "\n\n" << line1 << line2 << line3 << line4 << line5 << "\n\n\n";
	cout << "  You must gather 3 points to win.\n";
	cout << "  But beware! If you enter a wrong answer,\n";
	cout << "  you will loose 2 points...\n\n\n";

	srand(time(NULL));

	for (int i = 1; i <= tries; i++)
	{
		int answer;
		int x = rand() % 10;
		int y = rand() % 10;

		cout << "  " << score << ": " << x << " * " << y << " ? ";
		cin >> answer;

		if (x * y == answer)
		{
			correct_answers++;
			score++;
		}
		else
		{
			score = score - 2;
		}
	}

	cout << "\n  Final score: " << score << " points.\n\n";

	if (correct_answers >= 3) {
		cout << "\n  YOU WON! (" << correct_answers << " correct answers in " << tries << " tries)\n\n";
	}
	else {
		if (correct_answers == 0)
		{
			cout << "\n  YOU LOST! (No correct answers in " << tries << " tries)\n\n";
		}
		else if (correct_answers == 1)
		{
			cout << "\n  YOU LOST! (Only one correct answer in " << tries << " tries)\n\n";
		}
		else {
			cout << "\n  YOU LOST! (" << correct_answers << " correct answers in " << tries << " tries)\n\n";
		}
	}
}