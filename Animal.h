#pragma once
#include <iostream>
#include <stack>
#include <fstream>
#include "binary_tree node.h"


void ask_and_move(binary_tree_node<string>*& current_ptr)
{
    cout << "\n";

    if (toupper(inputChar("\t\t" + current_ptr->getData().substr(1, current_ptr->getData().length() - 2) + " (Y-yes or N-no) ")) == 'Y')
        current_ptr = current_ptr->getLeft();
    else
        current_ptr = current_ptr->getRight();
}

binary_tree_node<string>* beginning_tree()
{
    stack<binary_tree_node<string>*> s;
    binary_tree_node<string>* root_ptr = NULL;
    binary_tree_node<string>* child_ptr;

    ifstream fileInput;
    fileInput.open("animal.txt");

    if (fileInput.fail())
    {
        cout << "\n\t\tERROR: cannot find animal.txt file.\n";
        return NULL;
    }

    string question;
    string left_question;
    string right_question;

    binary_tree_node<string>* temp_ptr = root_ptr;

    while (!fileInput.eof())
    {
        bool bquestion = true;
        getline(fileInput, question);

        if (question[0] == '[')
        {
            child_ptr = new binary_tree_node<string>(question);
            bquestion = true;
        }
        else
        {
            child_ptr = new binary_tree_node<string>(question);
            bquestion = false;
        }

        if (root_ptr == NULL)
        {
            root_ptr = child_ptr;
            s.push(root_ptr);
        }
        else
        {
            if (!s.empty())
            {
                binary_tree_node<string>* parent_ptr = s.top();
                if (child_ptr->getData()[0] != '[')
                {
                    if (parent_ptr->getLeft() == NULL)
                        parent_ptr->setLeft(child_ptr);
                    else
                    {
                        parent_ptr->setRight(child_ptr);
                        s.pop();
                    }
                }
                else
                {
                    if (parent_ptr->getLeft() == NULL)
                        parent_ptr->setLeft(child_ptr);
                    else
                    {
                        parent_ptr->setRight(child_ptr);
                        s.pop();
                    }
                    if (child_ptr->getData()[0] == '[')
                        s.push(child_ptr);
                }
            }
        }
    }
    fileInput.close();

    return root_ptr;
}

void learn(binary_tree_node<string>* leaf_ptr)
{
    string guess_animal = leaf_ptr->getData();
    cout << "\n";
    string correct_animal = inputString("\t\tI give up. What animal is it? \n\t\t", true);

    cout << "\n\t\tPlease specify a yes/no question that will distinguish a " << correct_animal;
    cout << " from a " << guess_animal.substr(1, guess_animal.length() - 2) << ".\n\n";

    string new_question = inputString("\t\tEnter your question that ends with a '?': \n\t\t", true);
    leaf_ptr->setData("[" + new_question + "]");

    cout << '\n';
    if (toupper(inputChar("\t\tAs a " + correct_animal + ", does it " + new_question + " (Y-yes or N-no) ")) == 'Y')
    {
        leaf_ptr->setLeft(new binary_tree_node<string>("(" + correct_animal + ")"));
        leaf_ptr->setRight(new binary_tree_node<string>(guess_animal));
    }
    else
    {
        leaf_ptr->setLeft(new binary_tree_node<string>(guess_animal));
        leaf_ptr->setRight(new binary_tree_node<string>("(" + correct_animal + ")"));
    }
}

void play(binary_tree_node<string>* current_ptr)
{
    cout << "\n\tThink of an animal and press the RETURN/ENTER key to begin...\n\n";
    system("pause");

    while (!current_ptr->isLeaf())
        ask_and_move(current_ptr);

    cout << "\n";
    if (toupper(inputChar("\t\tMy guess is a " + current_ptr->getData().substr(1, current_ptr->getData().length() - 2) + " (Y-yes or N-no)? ")) == 'N')
        learn(current_ptr);
    else
        cout << "\n\t\t" << "Yes, I knew it all along!\n\n";
}

void preorderTraveral(ostream& out, binary_tree_node<string>* node)
{
    if (node == NULL)
        return;

    out << node->getData() << '\n';
    preorderTraveral(out, node->getLeft());
    preorderTraveral(out, node->getRight());
}
