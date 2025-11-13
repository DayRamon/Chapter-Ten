
// Anthony Herrera
// CMPR 131
// Prof. Quach
// 11/12/2025
// Assignement 10

#include <iostream> 
#include "input.h"
#include "Animal.h"

using namespace std;
void option3();

int main()
{
	do
	{
		system("cls");
		cout << "\n\t\t CMPR131 Chapter 10: Trees by Anthony Herrera (11/12/25)";
		cout << "\n\t\t" << string(70, char(205));
		cout << "\n\t\t1> Tree of strings";
		cout << "\n\t\t2> Tree container of integers";
		cout << "\n\t\t3> Animal Guessing Game";
		cout << "\n\t\t" << string(70, char(196));
		cout << "\n\t\t0> Exit";
		cout << "\n\t\t" << string(70, char(205)) << '\n';
		switch (inputInteger("\t\t  Option: ", 0, 3))
		{
		case 0: exit(1);
		//case 1: option1(); break;
			//case 2: option2(); break;
		case 3: option3(); break;
		default: cout << "\n\tERROR: invalud option.\n";
		}

		cout << '\n';
		system("pause");

	} while (true);

	return 0;
}

void option3()
{
	system("cls");
	cout << "\n\t3> Animal Guessing Game";
	cout << "\n\t" << string(102, char(205)) << '\n';
	cout << "\n\tA game tree for a simple game of \"animal\" twenty questions would look like:\n\n";

	cout << string(41, char(32)) << "[ Is it a mammal? ]\n";
	cout << string(45, char(32)) << "/         \\\n";
	cout << string(44, char(32)) << "/           \\\n";
	cout << string(24, char(32)) << "[ Does it have stripes? ]     [ Is it a bird? ]\n";
	cout << string(30, char(32)) << "/       \\                  /       \\\n";
	cout << string(29, char(32)) << "/         \\                /         \\\n";
	cout << string(24, char(32)) << "( Zebra )    ( Lion )   [ Does it fly? ]  ( Gila monster )\n";
	cout << string(50, char(32)) << " /       \\\n";
	cout << string(50, char(32)) << "/         \\\n";
	cout << string(44, char(32)) << "( Eagle )     ( Penguin )";

	cout << "\n\n\tA learning version of twenty questions: one that not only plays the game, but learns new \n\tobjects when it loses.\n\n";
	
	binary_tree_node<string>* root = beginning_tree();

	if (root == nullptr)
	{
		cout << "Could not load animal tree.\n";
		return;
	}

	do 
	{
		system("pause");
		system("cls");
		cout << "\n\tWelcome to Animal Guessing Game";
		cout << "\n\t" << string(60, char(205));
		cout << "\n\t\tA> Play the game";
		cout << "\n\t\tB> Save the game file";
		cout << "\n\t" << string(60, char(196));
		cout << "\n\t\t0> return";
		cout << "\n\t" << string(60, char(205));

		switch (toupper(inputChar("\n\t\tOption: ", static_cast<string>("ABC0"))))
		{
		case '0': return;
		case 'A': 
		{
			system("cls");
			play(root); 
		} break;

		case 'B':
		{
			ofstream out("animal.txt");
			preorderTraveral(out, root);
			out.close();
			cout << "\n\t\tGame saved successfully!\n";
		}
		break; 

		}

	} while (true);

}