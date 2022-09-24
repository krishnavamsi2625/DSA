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