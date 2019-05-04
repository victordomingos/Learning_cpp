#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>

using namespace std;

void display_menu(void)
{
	cout << endl;
	cout << "MENU\n\n";
	cout << "  1 - List all names\n";
	cout << "  2 - Read 1 name into a certain position\n";
	cout << "  3 - List number, name and name's width\n";
	cout << "  4 - What is the longest name?\n";
	cout << "  5 - Check if a name exists in the list.\n";
	cout << "  6 - Convert all names to uppercase\n";
	cout << "  7 - Convert all names to lowercase\n";
	cout << "ESC - Quit this application.";
	cout << endl;
}

void clearScreen()
{
	//TODO: Improve this...
	for (int i = 0; i < 5; i++)
	{
		cout << "\n\n\n\n\n\n\n\n\n\n";
	}
}


int main()
{
	string listadenomes[20]{
		"Ana", "Rui", "Pedro", "Abel", "Rita",
		"Seara", "Isabel", "Paulo", "Daniel", "Teresa",
		"Joaquim", "Tone", "Maria", "Manuel", "Beatriz",
		"Carol", "Alex", "Tiago", "Anabela", "Sandra",
	};
	int position;
	int result;
	string position_str;
	string name;
	string longestName;
	char op;

	do
	{
		display_menu();
		op = _getch();

		switch (op)
		{
		case '1':
			cout << endl;
			for (int i = 0; i < 20; i += 3)
			{
				cout << setfill(' ') << setw(15) << left << listadenomes[i];
				if (i + 1 < 20)
					cout << setfill(' ') << setw(15) << left << listadenomes[i + 1];
				if (i + 2 < 20)
					cout << setfill(' ') << setw(15) << left << listadenomes[i + 2];
				if (i + 3 < 20)
					cout << setfill(' ') << setw(15) << left << listadenomes[i + 3] << endl;
			}
			cout << endl;
			break;
		case '2':
			cout << "Position (0-19)? ";
			getline(cin, position_str);
			position = stoi(position_str);
			if (position < 0 or position >= 20)
			{
				cout << "Invalid position value!";
				break;
			}

			cout << "Name? ";
			getline(cin, name);
			listadenomes[position] = name;
			break;
		case '3':
			cout << endl;
			for (int i = 0; i < 20; i += 4)
			{
				string name1 = listadenomes[i];
				string name2 = listadenomes[i + 1];
				string name3 = listadenomes[i + 2];
				string name4 = listadenomes[i + 3];

				int w1 = name1.size();
				int w2 = name2.size();
				int w3 = name3.size();
				int w4 = name4.size();

				cout << right << setfill(' ') << setw(2) << i << " (" << w1 << ") ";
				cout << setfill(' ') << setw(13) << left << name1;
				if (i + 1 < 20)
				{
					cout << right << setfill(' ') << setw(2) << i + 1 << " (" << w2 << ") ";
					cout << setfill(' ') << setw(13) << left << name2 ;
				}
				if (i + 2 < 20)
				{
					cout << right << setfill(' ') << setw(2) << i + 2 << " (" << w3 << ") ";
					cout << setfill(' ') << setw(13) << left << name3;
				}
				if (i + 3 < 20)
				{
					cout << right << setfill(' ') << setw(2) << i + 3 << " (" << w4 << ") ";
					cout << setfill(' ') << setw(13) << left << name4;
				}
			}
			cout << endl;
			break;
		case '4':
			longestName = listadenomes[0];
			for (int i = 1; i < 20; i++)
			{
				if (longestName.size() < listadenomes[i].size())
					longestName = listadenomes[i];
			}
			cout << "\nThe longest name is " << longestName << ".\n";
			break;
		case '5':
			cout << "\nFinding out if a name is in the list. Enter the name to search for: ";
			getline(cin, name);
			result = -1;
			for (int i = 0; i < 20; i++)
			{
				if (name == listadenomes[i])
				{
					result = i;
					break;
				}
			}
			if (result != -1)
				cout << "Yes, that name is in the list, at position " << result << "." << endl;
			else
				cout << "No, that name is not in this list." << endl;
			break;
		case '6':
			for (int i = 0; i < 20; i++)
			{
				for (int j = 0; j < listadenomes[i].size(); j++)
					listadenomes[i][j] = toupper(listadenomes[i][j]);
			}
			break;
		case '7':
			for (int i = 0; i < 20; i++)
			{
				for (int j = 0; j < listadenomes[i].size(); j++)
					listadenomes[i][j] = tolower(listadenomes[i][j]);
			}
			break;
		default:
			if (op != 27)
			{
				clearScreen();
				cout << "\nOpcao desconhecida!\n" << op;
			}
			break;
		}
		cout << endl;

	} while (op != 27);

}
