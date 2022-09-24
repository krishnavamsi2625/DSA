/*
This program is used for finding the max and min in a tree which is not a binary search tree
In a binary search tree the left most element is the smallest and the right most element is the largest element */
#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

struct Node  
{ 
  int data; 
  struct Node *left; 
  struct Node *right; 
  Node(int val){
      data=val;
      left=right=NULL;
  }
};

int calcMAX(Node *node){
    
    if(node == NULL)
        return INT_MIN;
    else
        return max(node->data, max(calcMAX(node->left), calcMAX(node->right)));
}
int calcMin(Node * node)
{
    if(node == NULL)
        return INT_MAX;
    else
        return min(node->data, min(calcMin(node->left), calcMin(node->right)));
}
int main() {
	
	Node *root=new Node(20);
	root->left=new Node(70);
	root->right=new Node(90);
	root->left->left=new Node(30);
	root->left->left=new Node(40);
	root->right->right=new Node(70);
	
    cout << "The Max in Tree is : " << calcMAX(root);
}