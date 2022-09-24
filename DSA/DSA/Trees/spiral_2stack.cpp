#include <bits/stdc++.h>
using namespace std;

struct Node  
{ 
  int data; 
  struct Node *left; 
  struct Node *right; 
  Node(int val){
      data = val;
      left = right = NULL;
  }
};
void spiralorder(Node *root)
{   
    struct Node temp=*root;
    stack<Node> s1;
    stack<Node>s2;
    s1.push(*root);
    while(s1.size()!=0 || s2.size()!=0)
    {
        while(s1.size()!=0)
        {   temp=s1.top();
            cout<<s1.top().data<<" ";
            if(temp.left!=NULL)
            {
                s2.push(*temp.left);
            }
            if(temp.right!=NULL)
            {
                s2.push(*temp.right);
            }
            s1.pop();
        }
        while(s2.size()!=0)
        {   temp=s2.top();
            cout<<s2.top().data<<" ";
            if(temp.right!=NULL)
            {
                s1.push(*temp.right);
            }
            if(temp.left!=NULL)
            {
                s1.push(*temp.left);
            }
            s2.pop();
        }
        
    }
}
int main() {
	
	Node *root=new Node(20);
	root->left=new Node(70);
	root->right=new Node(90);
	root->left->left=new Node(30);
	root->left->right=new Node(40);
	root->right->right=new Node(70);
	root->right->left=new Node(60);
	//cout<<"Left_view"<<endl;

    cout<<"Spiral:-\n";spiralorder(root);
}
