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
    if (root == NULL)
        return NULL;

    while (root->right != NULL)
        root = root->right;

    return root;
}

Node *MinimumElement(Node *root)
{
    if (root == NULL)
        return NULL;

    while (root->left != NULL)
        root = root->left;

    return root;
}

Node *RightMostInLeftSubtree(Node *root)
{
    Node *ans;
    while (root != NULL)
    {
        ans = root;
        root = root->right;
    }
    return ans;
}

Node *LeftMostInRightSubtree(Node *root)
{
    Node *ans;
    while (root != NULL)
    {
        ans = root;
        root = root->left;
    }
    return ans;
}
void InorderSuccessorPredecessor(Node *root, int key)
{
    Node *curr = root;
    Node *succ = NULL;
    Node *pred = NULL;
    while (curr != NULL)
    {
        if (key < curr->data)
        {
            succ = curr; // potential successor
            curr = curr->left;
        }
        else if (key > curr->data)
        {
            pred = curr; // potential predecessor
            curr = curr->right;
        }
        else
        {
            if (curr->left != NULL)
            {
                pred = RightMostInLeftSubtree(curr->left);
            }
            if (curr->right != NULL)
            {
                succ = LeftMostInRightSubtree(curr->right);
            }
            break;
        }
    }
    if (pred != NULL)
        cout << "Predecessor = " << pred->data << endl;
    else
        cout << "No predecessor\n";

    if (succ != NULL)
        cout << "Successor = " << succ->data << endl;
    else
        cout << "No successor\n";
}
int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(7);
    InorderSuccessorPredecessor(root,5);
    return 0;
}
