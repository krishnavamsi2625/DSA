// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
struct node 
{ 
  int data; 
  struct node *left; 
  struct node *right; 
  node(int val){
      data = val;
      left = right = NULL;
  }
};
typedef struct node node;
int max(int a,int b)
{
    return (a>b)?a:b;
}
int height(node * root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        return (max(height(root->left),height(root->right))+1);
    }
}
int diameter(node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int pdia=height(root->left)+height(root->right)+1;
    int rdia=diameter(root->right);
    int ldia=diameter(root->left);
    return(max(pdia,max(rdia,ldia)));
}
int main() {
    // Write C++ code here
  	node *root=new node(20);
	root->left=new node(70);
	root->right=new node(90);
	root->left->left=new node(30);
	root->left->right=new node(40);
	root->right->right=new node(70);
	root->right->left=new node(60);
	cout<<"The diameter of the tree is:- "<<diameter(root);
    return 0;
}