Code in C++:
#include <bits/stdc++.h>
using namespace std;

struct Node  
{ 
  int data; 
  struct Node *left; 
  struct Node *right;
  
  Node(int val)
  {
      data = val;
      left = right = NULL;
  }
};


bool search(Node *node, int value){
    
    while(node!=NULL){
        
        // data is present at node
        if(node->data==value)
            return true;
            
        // value is greater than node's data
        else if(node->data<value)
            node=node->right;
            
        // value is smaller than node's data
        else
            node=node->left;
    }
    return false;
} 

int main() {
	
	Node *root=new Node(70);
	root->left=new Node(50);
	root->right=new Node(90);
	root->left->left=new Node(30);
	root->left->right=new Node(60);
	root->right->left=new Node(80);
	root->right->right=new Node(110);
	
	int x=80;
	
	if(search(root,x))
	    cout<<"Present in the Tree";
	else
	    cout<<"Not Present in the Tree";
}
Code in Python:
class Node:
    def __init__(self, val):
        self.left = None
        self.right = None
        self.data = val


def searchItem(node, val):
    while node is not None:

        if node.data == val:
            return True

        elif node.data < val:
            node = node.right

        else:
            node = node.left
    return False


# Driver code
root = Node(70)
root.left = Node(50)
root.right = Node(90)
root.left.left = Node(30)
root.left.right = Node(60)
root.right.left = Node(80)
root.right.right = Node(110)

if searchItem(root, 80):
    print("Present in the Tree")
else:
    print("Not Present in the Tree")