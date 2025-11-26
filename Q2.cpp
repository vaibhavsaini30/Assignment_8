#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

Node *TreeSearchRecursive(Node *root, int k)
{
    if (root == NULL || root->data == k)
        return root;

    if (k < root->data)
        return TreeSearchRecursive(root->left, k);
    else
        return TreeSearchRecursive(root->right, k);
}

Node *TreeSearchIterative(Node *root, int k)
{
    while (root != NULL && root->data != k)
    {
        if (k < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}

Node *MaximumElement(Node *root)
{
    if (root == NULL) return NULL;

    while (root->right != NULL)
        root = root->right;

    return root;
}

Node *MinimumElement(Node *root)
{
    if (root == NULL) return NULL;

    while (root->left != NULL)
        root = root->left;

    return root;
}

Node *TreeSuccessor(Node *root, Node *x)
{
    if (x->right != NULL)
        return MinimumElement(x->right);

    Node *succ = NULL;
    Node *y = root;

    while (y != NULL)
    {
        if (x->data < y->data)
        {
            succ = y;
            y = y->left;
        }
        else if (x->data > y->data)
        {
            y = y->right;
        }
        else
            break;
    }
    return succ;
}

Node *TreePredecessor(Node *root, Node *x)
{
    if (x->left != NULL)
        return MaximumElement(x->left);

    Node *pred = NULL;
    Node *y = root;

    while (y != NULL)
    {
        if (x->data > y->data)
        {
            pred = y;
            y = y->right;
        }
        else if (x->data < y->data)
        {
            y = y->left;
        }
        else
            break;
    }
    return pred;
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(7);
    return 0;
}
