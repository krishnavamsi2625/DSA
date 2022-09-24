#include <iostream>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<climits>
using namespace std;
struct node{
    int data;
    struct node* left;
    struct node* right;
    node(int x)
    {
        data=x;
        left=NULL;
        right=NULL;
    }
};
typedef struct node node;
class tree
{   public:
    node *root;
    tree()
    {
        root=NULL;
    }
    void insert();
    void preorder(node* root);
    void postorder(node * root);
    void inorder(node * root);
    int maxheight(node * root);
    void klevelnodes(node * root,int k);
    void levelorder(node *root);
    int size(node *root);
    void spiralorder(node *root);
    int search(node * root,int n);
};
void tree::insert()
{   int data;
    cout<<"Enter the data to be added:-";
    cin>>data;
    if(root==NULL)
    {
        root=new node(data);
        return;
    }
    node *newnode=new node(data);
    node *temp=root;
    node * previous;
    while(temp!=NULL)
    {
        previous=temp;
        if(temp->data<=data)
        {
            temp=temp->right;
        }
        else
        {
            temp=temp->left;
        }
    }
    if(previous->data<=data)
    {
        previous->right=newnode;
    }
    else{
        previous->left=newnode;
    }
    
}
void tree::postorder(node *  root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}
void tree::preorder(node * root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void tree::inorder(node * root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
int tree::maxheight(node *root)
{
    if(root==NULL)
    {
        return 0;//height starts from 1, if height starts from 0 then return -1
    }
    int lheight=maxheight(root->left);
    int rheight=maxheight(root->right);
    if(lheight>rheight)  //max(maxheight(root->left),maxheight(root->right))
    {
        return lheight+1;
    }
    else 
    {
        return rheight+1;
    }
    
}
void tree::klevelnodes(node *root,int k)
{
    if(root ==0)
    {
        return;
    }
    else if(k==0)
    {
        cout<<root->data<<" ";
    }
    else
    {
        klevelnodes(root->left,k-1);
        klevelnodes(root->right,k-1);
    }
    
}
void tree::levelorder(node *root)
{ 
    queue<node> q; 
    q.push(*root);
    while(q.size()!=0)
    {
        node temp=q.front();
        cout<<q.front().data<<" ";
        q.pop();
        if(temp.left!=NULL)
        {
            q.push(*temp.left);
        }
        if(temp.right!=NULL)
        {
            q.push(*temp.right);
        }
    }
    
}
int tree::size(node*root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1+size(root->left)+size(root->right);
}
void tree::spiralorder(node *root)
{
    queue<node> q;
    stack<node> s;
    q.push(*root);
    int left_right=1,n;
    while(q.size()!=0)
    {
         n=q.size();
        for(int i=0;i<n;i++)
        {   node temp=q.front();
            q.pop();
            if(left_right)
            {
                cout<<temp.data<<" ";
            }
            else
            {
                s.push(temp);
            }
            if(temp.left!=NULL)
            {
                q.push(*temp.left);
            }
            if(temp.right!=NULL)
            {
                q.push(*temp.right);
            }
        }
        if(!left_right)
        {
            while(!s.empty())
            {
                cout<<s.top().data<<" ";
                s.pop();
            }
        }
        left_right=!left_right;
    }
}
int tree::search(node * root,int n)
{
    if(root==NULL)
    {
        return INT_MIN;
    }
    if(root->data==n)
    {
        return n;
    }
    if(root->data<=n)
    {
        search(root->right,n);
    }
    else
    {
        search(root->left,n);
    }
}
int main() {
    int ch;
    tree t;
    while(true)
    {   cout<<"1)Enter\n2)Delete\n3)Postorder\n4)Preorder\n5)Inorder\n6)Height\n7)Node at level\n8)Level order Traversing \n9)Size\n10)Spiral order\n11)Search\n12)Exit\nEnter your choice:-";
        cin>>ch;
        switch(ch)
        {
            case 1:
                t.insert();
                break;
            case 2:
                break;
            case 3:
                if(t.size(t.root)==0)
                {
                    cout<<"Tree empyt!!"<<endl;
                    break;
                }
                cout<<"\tPost order:"<<endl<<"\t";
                t.postorder(t.root);
                cout<<endl;
                break;
            case 4:
                if(t.size(t.root)==0)
                {
                    cout<<"Tree empyt!!"<<endl;
                    break;
                }
                cout<<"\tPre order:"<<endl<<"\t";
                t.preorder(t.root);
                cout<<endl;
                break;
            case 5:
                if(t.size(t.root)==0)
                {
                    cout<<"Tree empyt!!"<<endl;
                    break;
                }
                cout<<"\tIn order:"<<endl<<"\t";
                t.inorder(t.root);
                cout<<endl;
                break;
            case 6:
                if(t.root==NULL)
                {
                    cout<<"Tree is empty"<<endl;
                    break;
                }
                cout<<"Height of tree is "<<t.maxheight(t.root)<<endl;
                break;
            case 7:
                int k;
                cout<<"Enter the level to be printed:-";
                cin>>k;
                if(t.size(t.root)<k)
                {
                    cout<<"Level "<<k<<" not found!!"<<endl;
                    break;
                }
                cout<<"\tThe elements at level k"<<endl<<"\t";
                t.klevelnodes(t.root,k);
                cout<<endl;
                break;
            case 8:
                if(t.size(t.root)==0)
                {
                    cout<<"Tree empyt!!"<<endl;
                    break;
                }
                cout<<"\tLevel order traversing:-"<<endl<<"\t";
                t.levelorder(t.root);
                cout<<endl;
                break;
            case 9:
                {
                    int size=t.size(t.root);
                if(size==0)
                {
                    cout<<"Tree empyt!!"<<endl;
                }
                else
                {
                    cout<<"The size of the Tree is : "<<size<<endl;
                }
                break;
                }
            case 10:
                if(t.size(t.root)==0)
                {
                    cout<<"Tree empyt!!"<<endl;
                    break;
                }
                cout<<"\t Spiral order:-"<<endl<<"\t";
                t.spiralorder(t.root);
                cout<<endl;
                break;
            case 11:
                int x,y;
                cout<<"Enter the number to be searched:-";
                cin>>x;
                y=t.search(t.root,x);
                if(y==INT_MIN)
                {
                    cout<<"Element not found"<<endl;
                }
                else
                {
                    cout<<y<<" found in the tree"<<endl;
                }
                break;
            case 12:
                exit(0);
                
        }
    }

    return 0;
}