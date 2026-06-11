#include <iostream>
#include <string>
using namespace std;

class Node 
{
public:
    string info;
    Node *leftchild;
    Node *rightchild;

    // Constructor untuk Node class
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

    // Constructor untuk BinaryTree class
    BinaryTree() 
    {
        root = NULL; 
    }

    // Fungsi mencari posisi node
    void search(string element, Node *&parent, Node *&currentNode)
    {
        currentNode = root; 
        parent = NULL; 

        while ((currentNode != NULL) && (currentNode->info != element)) 
        {
            parent = currentNode; 

            if (element < currentNode->info) 
            {
                currentNode = currentNode->leftchild;
            }
            else 
            {
                currentNode = currentNode->rightchild;
            }
        }
    }

    // Fungsi menyisipkan node baru ke dalam pohon
    void insert(string element)
    {
        Node *newnode = new Node(element, NULL, NULL); 

        Node *parent = NULL; 
        Node *currentNode = NULL; 

        search(element, parent, currentNode); 
        
        if (parent == NULL) 
        {
            root = newnode;
            return;
        }
        else if (element < parent->info) 
        {
            parent->leftchild = newnode;
        }
        else 
        {
            parent->rightchild = newnode;
        }
    }

    void inorder(Node* ptr)
    {
        if (ptr != NULL) 
        {
            inorder(ptr->leftchild); 
            cout << ptr->info << " "; 
            inorder(ptr->rightchild); 
        }
    }

    void preorder(Node* ptr) 
    {
        if (root == NULL) 
        {
            cout << "Tree is empty" << endl;
            return;
        }

        if (ptr != NULL) 
        {
            cout << ptr->info << " "; 
            preorder(ptr->leftchild); 
            preorder(ptr->rightchild); 
        }
    }

    void postorder(Node* ptr) 
    {
        if (root == NULL) 
        {
            cout << "Tree is empty" << endl;
            return;
        }

        if (ptr != NULL) 
        {
            postorder(ptr->leftchild); 
            postorder(ptr->rightchild); 
            cout << ptr->info << " "; 
        }
    }    
}; 

int main()
{
    BinaryTree obj;

    while(true)
    {
        cout << "\n1. Implement insert operation" << endl;
        cout << "2. Perform inorder traversal" << endl;
        cout << "3. Perform preorder traversal" << endl;
        cout << "4. Perform postorder traversal" << endl;
        cout << "5. Exit" << endl;
        cout << "\nEnter your choice (1-5): ";

        char ch;
        cin >> ch;
        cout << endl;

        switch (ch)
        {
            case '1':
            {
                cout << "Enter a word: ";
                string word;
                cin >> word;
                obj.insert(word);
                break;
            }

            case '2':
            {
                obj.inorder(obj.root);
                cout << endl;
                break;
            }

            case '3':
            {
                obj.preorder(obj.root);
                cout << endl;
                break;
            }

            case '4':
            {
                obj.postorder(obj.root);
                cout << endl;
                break; 
            }

            case '5':
                return 0;

            default:
            {
                cout << "Invalid option" << endl;
                break;
            }
        }
    }

    return 0;
}