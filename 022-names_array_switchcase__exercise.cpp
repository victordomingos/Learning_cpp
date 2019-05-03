#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>

using namespace std;

void display_menu()
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

void listData()
{
    clearScreen();
    cout << "listData";
}

void showLongestName()
{
    clearScreen();
    cout << "showLongestName";
}

void isNameInThere()
{
    clearScreen();
    cout << "isNameInThere";
}

void makeNamesUppercase()
{
    clearScreen();
    cout << "makeNamesUppercase";
}

void makeNamesLowercase()
{
    clearScreen();
    cout << "makeNamesLowercase";
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
    string position_str;
    string name;
    char op;

    do
    {
        display_menu();
        op = _getch();

        switch (op)
        {
        case '1':
            cout << endl;
            for (int i = 0; i < 20; i+=3)
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
            for (int i = 0; i < 20; i += 3)
            {
                string name1 = listadenomes[i];
                string name2 = listadenomes[i+1];
                string name3 = listadenomes[i+2];
                string name4 = listadenomes[i+3];

                int w1 = name1.size();
                int w2 = name2.size();
                int w3 = name3.size();
                int w4 = name3.size();

                cout << right << setfill(' ') << setw(2) << i << " " << setfill(' ') << setw(15) << left << name1;
                if (i + 1 < 20)
                    cout << right << setfill(' ') << setw(2) << i + 1 << " " << setfill(' ') << setw(15) << left << name2 << " (" << ;
                if (i + 2 < 20)
                    cout << right << setfill(' ') << setw(2) << i + 2 << " " << setfill(' ') << setw(15) << left << name3;
                if (i + 3 < 20)
                    cout << right << setfill(' ') << setw(2) << i + 3 << " " << setfill(' ') << setw(15) << left << name4 << endl;
            }
            cout << endl;
            break;
        case '4':
            showLongestName();
            break;
        case '5':
            isNameInThere();
            break;
        case '6':
            makeNamesUppercase();
            break;
        case '7':
            makeNamesLowercase();
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
