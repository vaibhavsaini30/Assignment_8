#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

Node* TreeInsert(Node* root,int key){
    if(root==NULL)
        return new Node(key);
    if(key<root->data) return TreeInsert(root->left,key);
    else return TreeInsert(root->right,key);
    return root;
}

Node* Successor(Node* root){
    Node* ans;
    while(root!=NULL){
        ans=root;
        root=root->left;
    }
    return ans;
}
Node* DeleteNode(Node* root,int key){
    if(root == NULL)
        return NULL;
    else if(key < root->data){
        return DeleteNode(root->left,key);
    }
    else if(key > root->data){
        return DeleteNode(root->right,key);
    }
    else{
        //key == root->data
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        else if(root->left==NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else{
            //2 child
            Node* IS = Successor(root->right);
            root->data = IS->data;
            root->right = DeleteNode(root->right,IS->data);
        }
    }
    return root;
}
int MaxDepth(Node* root)
{
    if (root == NULL)
        return 0;

    int leftDepth = MaxDepth(root->left);
    int rightDepth = MaxDepth(root->right);

    return 1 + max(leftDepth, rightDepth);
}
int MinDepth(Node* root) {
    if (root == NULL)
        return 0;

    // If one child is NULL → go to the other child
    if (root->left == NULL)
        return 1 + MinDepth(root->right);

    if (root->right == NULL)
        return 1 + MinDepth(root->left);

    // Normal case → same as MaxDepth but using min()
    return 1 + min(MinDepth(root->left), MinDepth(root->right));
}


void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    cout<<MinDepth(root);
    return 0;
}