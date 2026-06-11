#include <iostream>
#include <string>
using namespace std;

class Node 
{
public:
    string info;
    Node *leftchild;
    Node *rightchild;

    // Constructor for Node class
    Node (string i, Node *l, Node *r) 
    {
        info = i;
        leftchild = l;
        rightchild = r;
    }

};

class BinaryTree 
{
public:
    Node *root;

    // /Constructor for BinaryTree class
     BinaryTree() 
    {
        root = nullptr; // initialize root to nullptr
    }
};
