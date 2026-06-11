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
        root = NULL ; // initialize root to nullptr
    }

    //insert a node in the binary search tree
    void insert(string element)
    {
        Node *newnode = new Node(element, NULL, NULL); // create a new node with the given element

        newnode->info = element; // set the info of the new node to the given element
        newnode->leftchild = NULL; // set the left child of the new node to null
        newnode->rightchild = NULL; // set the right child of the new node to null

        Node *parent = NULL; // initialize parent pointer to null
        Node *currentNode = NULL; // initialize currentNode pointer to null

        search(element, parent, currentNode); // search for the correct position to insert the new node
        if (parent == NULL) // if the tree is empty, set the new node as the root
        {
            root = newnode;
            return;
        }
        else if (element < parent->info) // if the element is less than the parent's info, insert it as the left child
        {
            parent->leftchild = newnode;
        }


};
