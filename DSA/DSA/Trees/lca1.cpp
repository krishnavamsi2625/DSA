/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<vector>
using namespace std;
struct node 
{
    int data;
    struct node *left;
    struct node *right;
    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};
typedef struct node node;
void print(vector<node> v)
{
    for(auto i=v.begin();i!=v.end();i++)
    {
        cout<<i->data<<"->";
    }
}
bool path(node * root,vector<node> &v,int target)
{
    if(root==NULL)
    {
        return false;
    }
    v.push_back(*root);
    if(root->data==target)
    {   
        return true;
    }
    else if(path(root->left,v,target)||path(root->right,v,target))
    {
        return true;
    }
    v.pop_back();
    return false;
}
void lca(node *root,int x,int y)
{   
    if(root==NULL)
    {
        cout<<"No LCA Found!!";
        return;
        
    }
    vector<node> v1;
    vector<node> v2;
    int xc=path(root,v1,x);
    int yc=path(root,v2,y);
    cout<<"Path of "<<x<<" is:- ";
    print(v1);
    cout<<endl;
    cout<<"Path of "<<y<<" is:- ";
    print(v2);
    cout<<endl;
    if(xc==0 ||yc==0)
    {
     cout<<"No LCA Found!!";   
     return;
    }
    for(int i=0;i<v1.size()&&i<v2.size();i++)
    {
        if(v1[i].data!=v2[i].data )
        {
            cout<<"Lowest common anchestor lca of "<<x<<" and "<<y<<" is "<<v1[i-1].data;
            return;
        }
    }
    
    
}
int main()
{
    node *root=new node(70);
	root->left=new node(20);
	root->right=new node(30);
	root->left->left=new node(50);
	root->left->right=new node(10);
	root->left->left->left=new node(60);
	root->left->left->right=new node(40);
	root->left->left->left->left=new node(90);
	root->left->left->right->right=new node(110);
	root->left->right->right=new node(80);
	root->left->right->right->right=new node(100);
	lca(root,90,110);

    return 0;
}
