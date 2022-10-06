// Online C++ compiler to run C++ program online
#include <iostream>
struct node
{
    int val;
    struct node *left;
    struct node *right;
    node(int x)
    {
        val=x;
        left=NULL;
        right=NULL;
    }
};
typedef struct node node;
using namespace  std;
void left(node *root)
{   
    if(root==NULL)
    {
        return;
    }
    left(root->left);
    cout<<root->val<<" ";
    
}
void right( node *root)
{   if(root==NULL)
    {
        return;
    }
    cout<<root->val<<" ";
    right(root->right);
}
int main() {
    // Write C++ code here
    node *root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(7);
    root->right->right=new node(8);
    left(root);
    right(root->right);
    return 0;
}