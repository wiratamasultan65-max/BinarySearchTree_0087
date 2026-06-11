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
}

//this function searches for the correct position to insert a new node in the binary search tree
void search(string element, Node *&parent, Node *&currentNode)
{
    currentNode = root; // start the search from the root
    parent = NULL; // initialize parent to null

    while ((currentNode != NULL) && (currentNode->info != element)) // continue searching until we reach a null node or find the element
    {
    
        parent = currentNode; // update parent to the current node

        if (element < currentNode->info) // if the element is less than the current node's info, go to the left child
        {
            currentNode = currentNode->leftchild;
        }
        else // if the element is greater than or equal to the current node's info, go to the right child
        {
            currentNode = currentNode->rightchild;
        }
    }


 void inorder (Node* ptr)
    {
        if (ptr != NULL) // if the current node is not null, continue the inorder traversal
        {
            inorder(ptr->leftchild); // traverse the left subtree
            cout << ptr->info << " "; // visit the current node
            inorder(ptr->rightchild); // traverse the right subtree
        }
    }

