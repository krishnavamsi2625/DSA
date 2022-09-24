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