#pragma once
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <queue>
#include <algorithm>
using std::queue;
using std::ostream;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int nData)
        : data(nData), left(nullptr), right(nullptr) {
    }
};

class BinaryTree
{
private:
    Node* root;
    int size;

    bool recursiveSearch(const Node* current, int value) const {
        if (!current) return false;
        if (current->data == value) return true;
        if (value < current->data)
            return recursiveSearch(current->left, value);
        else
            return recursiveSearch(current->right, value);
    }

    void inOrderPrint(ostream& os, const Node* cur) const {
        if (cur) {
            inOrderPrint(os, cur->left);
            os << cur->data << " ";
            inOrderPrint(os, cur->right);
        }
    }

    void preOrderPrint(const Node* cur) const {
        if (cur) {
            std::cout << cur->data << " ";
            preOrderPrint(cur->left);
            preOrderPrint(cur->right);
        }
    }

    void postOrderPrint(const Node* cur) const {
        if (cur) {
            postOrderPrint(cur->left);
            postOrderPrint(cur->right);
            std::cout << cur->data << " ";
        }
    }


    Node* findMin(Node* node) const {
        while (node && node->left) node = node->left;
        return node;
    }

    Node* deleteRecursive(Node* current, int value) {
        if (!current) return nullptr;

        if (value < current->data)
            current->left = deleteRecursive(current->left, value);

        else if (value > current->data)
            current->right = deleteRecursive(current->right, value);

        else {
      
            if (!current->left && !current->right) {
                delete current;
                return nullptr;
            }


            if (!current->left) {
                Node* temp = current->right;
                delete current;
                return temp;
            }
            if (!current->right) {
                Node* temp = current->left;
                delete current;
                return temp;
            }

            Node* nextNode = findMin(current->right);
            current->data = nextNode->data;
            current->right = deleteRecursive(current->right, nextNode->data);
        }
        return current;
    }

    void clear(Node* cur) {
        if (!cur) return;
        clear(cur->left);
        clear(cur->right);
        delete cur;
    }

    int heightHelper(Node* cur) const {
        if (!cur) return 0;
        return 1 + std::max(heightHelper(cur->left), heightHelper(cur->right));
    }

    int leafHelper(Node* cur) const {
        if (!cur) return 0;
        if (!cur->left && !cur->right) return 1;
        return leafHelper(cur->left) + leafHelper(cur->right);
    }

    struct BalanceResult {
        int height;
        bool balanced;
    };

    BalanceResult isBalancedHelper(Node* cur) const {
        if (!cur) return { 0, true };

        BalanceResult left = isBalancedHelper(cur->left);
        BalanceResult right = isBalancedHelper(cur->right);

        bool balanced = left.balanced &&
            right.balanced &&
            std::abs(left.height - right.height) <= 1;

        return { 1 + std::max(left.height, right.height), balanced };
    }

public:
    BinaryTree() : root(nullptr), size(0) {}

    ~BinaryTree() { clear(root); }

    Node* insertHelper(Node* cur, int value) {
        if (!cur) {
            size++;
            return new Node(value);
        }

        if (value < cur->data)
            cur->left = insertHelper(cur->left, value);
        else
            cur->right = insertHelper(cur->right, value);

        return cur;
    }

    void insert(int value) {
        root = insertHelper(root, value);
    }

    void deletion(int value) {
        bool existed = search(value);
        root = deleteRecursive(root, value);
        if (existed) size--;
    }

    bool search(int value) const {
        return recursiveSearch(root, value);
    }

    void preOrder() const { preOrderPrint(root); }
    void postOrder() const { postOrderPrint(root); }

    void levelOrder() const {
        if (!root) return;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* cur = q.front();
            q.pop();

            std::cout << cur->data << " ";

            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        std::cout << "\n";
    }

    int height() const { return heightHelper(root); }
    int leafCount() const { return leafHelper(root); }
    bool isBalanced() const { return isBalancedHelper(root).balanced; }
    int getSize() const { return size; }

    void clear() {
        clear(root);
        root = nullptr;
        size = 0;
    }

    friend ostream& operator<<(ostream& os, const BinaryTree& obj);
};

#endif
