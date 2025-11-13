
// Anthony Herrera
// CMPR 131
// Prof. Quach
// 11/12/2025
// Assignement 10

#include <iostream> 
#include "input.h"
#include "Animal.h"
#include "BinaryTree.h"

ostream& operator<<(ostream& os, const BinaryTree& obj) 
{
	obj.inOrderPrint(os, obj.root);
	return os;
}

using namespace std;

void option2();
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
		case 2: option2(); break;
		case 3: option3(); break;
		default: cout << "\n\tERROR: invalud option.\n";
		}

		cout << '\n';
		system("pause");

	} while (true);

	return 0;
}

const char INDENT = '\t';
void option2() 
{
    char choice = 'A';
    int nValue = 0;
    bool running = true;
    BinaryTree newTree;
    do 
    {
        system("cls");
        cout << INDENT << "1 > bTree container\n";
        cout << INDENT << string(85, (char)205) << endl;
        cout << INDENT << INDENT << "A > Insert a node / leaf\n";
        cout << INDENT << INDENT << "B > Count of Nodes / leaves\n";
        cout << INDENT << INDENT << "C > Search a node / leaf\n";
        cout << INDENT << INDENT << "D > Pre - order traversal\n";
        cout << INDENT << INDENT << "E > In - order traversal\n";
        cout << INDENT << INDENT << "F > Post - order traveral\n";
        cout << INDENT << INDENT << "G > Delete the entire tree\n";
        cout << INDENT << string(85, (char)196) << endl;
        cout << INDENT << INDENT << "0 > return\n";
        cout << INDENT << string(85, (char)205) << endl;
        choice = toupper(inputChar("\t\tOption :", "ABCDEFG0"));
        switch (choice) {
        case 'A':
            nValue = inputInteger("\t\tEnter an integer: ");
            newTree.insert(nValue);
            cout << "\n\n";
            break;
        case 'B':

            cout << "\n\n" << INDENT << INDENT << "Count of Nodes: " << newTree.getSize() << " nodes. \n\n";

            break;
        case 'C':
            if (newTree.getSize() == 0) {
                cout << "\n\n\t\t" << "Tree is empty. \n\n";
            }
            else {
                nValue = inputInteger("\t\tEnter an integer: ");
                if (newTree.search(nValue)) {
                    cout << "\t\t" << nValue << " is found. \n\n";
                }
                else {
                    cout << "\t\t" << nValue << " is not found. \n\n";
                }
            }
            break;
        case 'D':
            if (newTree.getSize() == 0) {
                cout << "\n\n\t\t" << "Tree is empty. \n\n";
            }
            else {
                cout << "\n\n\t\t" << "Pre-order traversal of bTree with " << newTree.getSize() << " nodes :\n";
                cout << "\t";
                newTree.preOrder();
                cout << "\n\n";
            }
            break;
        case 'E':
            if (newTree.getSize() == 0) {
                cout << "\n\n\t\t" << "Tree is empty. \n\n";
            }
            else {
                cout << "\n\n\t\t" << "Inorder traversal of bTree with " << newTree.getSize() << " nodes :\n";
                cout << "\t" << newTree << "\n\n";
            }
            break;
        case 'F':
            if (newTree.getSize() == 0) {
                cout << "\n\n\t\t" << "Tree is empty. \n\n";
            }
            else {
                cout << "\n\n\t\t" << "Post-order traversal of bTree with " << newTree.getSize() << ":\n";
                cout << "\t";
                newTree.postOrder();
                cout << "\n\n";
            }
            break;
        case 'G':
            newTree.clear();

            cout << "\n\n\t\t" << "bTree has been cleared. \n\n";

            break;
        case '0':
            running = false;
            break;
        }
        system("pause");
    } while (running);
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

		switch (toupper(inputChar("\n\t\tOption: ", static_cast<string>("AB0"))))
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
		} break; 

		}

	} while (true);

}
