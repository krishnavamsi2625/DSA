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