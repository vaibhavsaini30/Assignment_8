#include <iostream>
#include<climits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

bool isBSTUtil(Node* root, int minVal, int maxVal)
{
    if (root == NULL)
        return true;

    if (root->data <= minVal || root->data >= maxVal)
        return false;

    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(Node* root)
{
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main()
{
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    if (isBST(root))
        cout << "The tree is a BST";
    else
        cout << "The tree is NOT a BST";

    return 0;
}
