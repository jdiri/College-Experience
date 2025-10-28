//************************************************************************
// Description: Red black tree implementation. See RedBlackTree.h
//              for the Red Black Tree definition
//************************************************************************

//include the relevant header file
#include "RedBlackTree.h"
#include "sstream"
//----

using namespace std;

//*******************************************************************
//constructor
RedBlackTree::RedBlackTree()
{
	//----
    root = nullptr;
    size = 0;
}

//*******************************************************************
//destructor
RedBlackTree::~RedBlackTree()
{
	//----
    delete root;
	//----
	cout << "The number of deleted nodes: " << size << endl;
}

//Read the assignment description carefully and finish all functions definition here
//----
Node* RedBlackTree::getRoot(){
    return root;
}

void RedBlackTree::treeMinimum(){
    if(root != nullptr){
        Node* temp = root;
        while(temp->leftChild != NULL){
            temp = temp->leftChild;
        }
        cout << "The MINIMUM is: " << endl;
        print(temp);
    }
    else
        cout << "Tree is empty" << endl;
}

void RedBlackTree::treeMaximum(){
    if(root != NULL){
        Node* temp = root;
        while(temp->rightChild != NULL){
            temp = temp->rightChild;
        }
        cout << "The MAXIMUM is: " << endl;
        print(temp);
    }
    else
        cout << "Tree is empty" << endl;
}

Node* RedBlackTree::treeSearch(string airline, int flightNum, string deptDate){
    int key = getKey(airline,flightNum,deptDate);
    Node* temp = getRoot();
    while(temp != nullptr){
        int tempKey = getKey(temp->airLine,temp->flightNum,temp->deptDate);
        if(key < tempKey){
            temp = temp->leftChild;
        }
        else if(key > tempKey){
            temp = temp->rightChild;
        }
        else{
            return temp;
        }
    }
    return nullptr;
}
//----

//hash function i created to get the key
int RedBlackTree::getKey(string airline,int flightNum,string deptDate){
    //----
    string key = airline + to_string(flightNum) + deptDate;
    int numKey = 0;
    
    for (char c : key)//iterates through key string
    {
        numKey += static_cast<int>(c);
    }
    
    return numKey;
   //----
}

Node* RedBlackTree::findMaximumNode(Node* node){
    if (node->rightChild != nullptr)
    {
        return findMaximumNode(node->rightChild);
    }
    return node;
}
Node* RedBlackTree::findMinimumNode(Node* node){
    if (node->leftChild != nullptr)
    {
        return findMinimumNode(node->leftChild);
    }
    return node;
}

//fixUP
void RedBlackTree::fixUp(Node* node){
    while (node->parent != nullptr && node->parent->color == "RED")
    {
        if (node->parent == node->parent->parent->leftChild)
        {
            Node* uncle = node->parent->parent->rightChild;

            // Uncle is red
            if (uncle->color == "RED")
            {
                node->parent->color = "BLACK";
                uncle->color = "BLACK";
                node->parent->parent->color = "RED";
                node = node->parent->parent;
            }
            else
            {
                // Case 2: Uncle is black and node is a right child of a left child
                if (node == node->parent->rightChild)
                {
                    node = node->parent;
                    leftRotate(node);
                }

                // Case 3: Uncle is black and node is a left child
                node->parent->color = "BLACK";
                node->parent->parent->color = "RED";
                rightRotate(node->parent->parent);
            }
        }
        else
        {
            // Symmetric cases for when the parent is a right child
            Node* uncle = node->parent->parent->leftChild;

            // Case 1: Uncle is red
            if (uncle != nullptr && uncle->color == "RED")
            {
                node->parent->color = "BLACK";
                uncle->color = "BLACK";
                node->parent->parent->color = "RED";
                node = node->parent->parent;
            }
            else
            {
                // Case 2: Uncle is black and node is a left child of a right child
                if (node == node->parent->leftChild)
                {
                    node = node->parent;
                    rightRotate(node);
                }

                // Case 3: Uncle is black and node is a right child of a right child
                node->parent->color = "BLACK";
                node->parent->parent->color = "RED";
                leftRotate(node->parent->parent);
            }
        }
    }

    // Ensure that the root is always black
    root->color = "BLACK";
}

void RedBlackTree::leftRotate(Node* node){
    Node* rightChild = node->rightChild;
    node->rightChild = rightChild->leftChild;

    if (rightChild->leftChild != nullptr)
    {
        rightChild->leftChild->parent = node;
    }

    rightChild->parent = node->parent;

    if (node->parent == nullptr)
    {
        root = rightChild;
    }
    else if (node == node->parent->leftChild)
    {
        node->parent->leftChild = rightChild;
    }
    else
    {
        node->parent->rightChild = rightChild;
    }

    rightChild->leftChild = node;
    node->parent = rightChild;
}
void RedBlackTree::rightRotate(Node* node){
     Node* leftChild = node->leftChild;
    node->leftChild = leftChild->rightChild;

    if (leftChild->rightChild != nullptr)
    {
        leftChild->rightChild->parent = node;
    }

    leftChild->parent = node->parent;

    if (node->parent == nullptr)
    {
        root = leftChild;
    }
    else if (node == node->parent->leftChild)
    {
        node->parent->leftChild = leftChild;
    }
    else
    {
        node->parent->rightChild = leftChild;
    }

    leftChild->rightChild = node;
    node->parent = leftChild;
}


//****************************************************************
//This is the general BST insertion operation.
//It does not care about the color of the newly added node.
//Note: duplicated node should not be added inside
void RedBlackTree::insertNode(Node* node)
{
    //----
    Node* foundNode = treeSearch(node->airLine,node->flightNum,node->deptDate);
        if (foundNode != NULL)
        {   
            if(foundNode->airLine == node->airLine && foundNode->flightNum == node->flightNum){
                cout << "Duplicated node. NOT added" << endl;
                return;
            }
        }
    node->color = "RED";
    // Perform the insertion
    if (root == nullptr)
    {
        // If the tree is empty, make the new node the root
        root = node;
        size++;
        root->parent = NULL;
        root->leftChild = nullptr;
        root->rightChild = nullptr;
    }
    else
    {
        // find the appropriate position to insert the new node
        Node *current = root;
        Node *parent = nullptr;

        while (current != nullptr)
        {
            parent = current;

            // Compare the data of the new node with the current node
            // to determine the direction
            if (getKey(node->airLine,node->flightNum,node->deptDate) < getKey(current->airLine,current->flightNum,current->deptDate))
            {
                current = current->leftChild;
            }
            else
            {
                current = current->rightChild;
            }
        }

        // Set the parent of the new node based on the comparison result
        node->parent = parent;

        // Insert the new node as a child of the parent node
        if (getKey(node->airLine,node->flightNum,node->deptDate) < getKey(parent->airLine,parent->flightNum,parent->deptDate))
        {
            parent->leftChild = node;
            size++;
        }
        else
        {
            parent->rightChild = node;
            size++;
        }
    }

    // fix RB-tree
    fixUp(node);

}

void RedBlackTree::treeInsert(string airLine, int flightNum, string deptDate){
    Node* node = new Node();
    node->airLine = airLine;
    node->flightNum = flightNum;
    node->deptDate = deptDate;
    node->color = "RED";
    insertNode(node);
}


void RedBlackTree::treeInorder(){
    inorderTraversal(root);
}
void RedBlackTree::treePostorder(){
    postOrderTraversal(root);
}
void RedBlackTree::treePreorder(){
    preOrderTraversal(root);
}

void RedBlackTree::inorderTraversal(Node* node){
    if (node == nullptr) {
        return;
    }
    inorderTraversal(node->leftChild); // Traverse the left subtree
    print(node);
    cout << " "; // Print the current node
    inorderTraversal(node->rightChild); // Traverse the right subtree
}
void RedBlackTree::postOrderTraversal(Node* node){
    if (node == nullptr) {
        return;
    }

    postOrderTraversal(node->leftChild); // Traverse the left subtree
    postOrderTraversal(node->rightChild); // Traverse the right subtree
    print(node);
    cout << " "; // Print the current node
}
void RedBlackTree::preOrderTraversal(Node* node) {
    if (node == nullptr) {
        return;
    }
    print(node);
    cout << " "; // Print the current node
    preOrderTraversal(node->leftChild); // Traverse the left subtree
    preOrderTraversal(node->rightChild); // Traverse the right subtree
}

Node* RedBlackTree::findPredecessorNode(Node* node){
    // If the left child exists, find the rightmost node in the left subtree
    if (node->leftChild != nullptr) {
        Node* predecessor = node->leftChild;
        while (predecessor->rightChild != nullptr) {
            predecessor = predecessor->rightChild;
        }
        return predecessor;
    }

    // If the left child doesn't exist, find the nearest ancestor whose right child is also an ancestor of the given node
    Node* current = node;
    Node* ancestor = node->parent;
    while (ancestor != nullptr && current == ancestor->leftChild) {
        current = ancestor;
        ancestor = ancestor->parent;
    }

    return ancestor;
}
Node* RedBlackTree::findSuccessorNode(Node* node){
    // If the right child exists, find the leftmost node in the right subtree
    if (node->rightChild != nullptr) {
        Node* successor = node->rightChild;
        while (successor->leftChild != nullptr) {
            successor = successor->leftChild;
        }
        return successor;
    }

    // If the right child doesn't exist, find the nearest ancestor whose left child is also an ancestor of the given node
    Node* current = node;
    Node* ancestor = node->parent;
    while (ancestor != nullptr && current == ancestor->rightChild) {
        current = ancestor;
        ancestor = ancestor->parent;
    }

    return ancestor;
}
void RedBlackTree::treePredecessor(string airline,int flightNum,string deptDate){
    Node* node = treeSearch(airline, flightNum, deptDate);
    if(node == nullptr){
        cout << airline << " " << flightNum << " on " << deptDate << "is NOT found.\n Its Predecessor does NOT exist" << endl;
    }
    else{
        cout << airline << " " << flightNum << " on " << deptDate << "is found.\n"<< endl;
        node = findPredecessorNode(node);
        if(node == nullptr){
            cout << "Its Predecessor does NOT exist" << endl;
        }
        else 
            cout << "Its Predecessor is:\n" << node->airLine << " " << node->flightNum << " " << node->deptDate << " " << node->color << endl;
    }
}
void RedBlackTree::treeSucessor(string airline,int flightNum,string deptDate){
    Node* node = treeSearch(airline, flightNum, deptDate);
    if(node == nullptr){
        cout << airline << " " << flightNum << " on " << deptDate << "is NOT found.\n Its Predecessor does NOT exist" << endl;
    }
    else{
        cout << airline << " " << flightNum << " on " << deptDate << "is found.\n"<< endl;
        node = findSuccessorNode(node);
        if(node == nullptr){
            cout << "Its Succesor does NOT exist" << endl;
        }
        else 
            cout << "Its Successor is:\n" << node->airLine << " " << node->flightNum << " " << node->deptDate << " " << node->color << endl;
    }
}

int deleteNode(Node* node) {
    // Base case: If the node is NULL, return 0
    if (node == NULL) {
        return 0;
    }
    
    // Recursively delete the left and right subtrees
    int leftCount = deleteNode(node->leftChild);
    int rightCount = deleteNode(node->rightChild);
    
    // Delete the current node
    delete node;
    
    // Return the total number of nodes deleted (including the current node)
    return 1 + leftCount + rightCount;
}


//******************************************************************
//Given a 'node', this function prints the node information on screen
void RedBlackTree::print(Node *node)
{
      cout << left;
      cout << setw(5)  << node->airLine
           << setw(10) << node->flightNum
           << setw(12) << node->deptDate;
      cout << right << setw(7) << node->color << endl;
}