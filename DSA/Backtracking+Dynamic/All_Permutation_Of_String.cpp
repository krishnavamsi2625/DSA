

#include <iostream>

using namespace std;
int i=1;
void permute(string a,int left,int right)
{
    if(left==right)
    {
        cout<<i<<") "<<a<<endl;
        i++;
    }
    else
    {
        for(int i=left;i<=right;i++)
        {
            swap(a[left],a[i]);
            permute(a,left+1,right);
            swap(a[left],a[i]);
        }
    }
}
int main()
{
    permute("abcde",0,4);
    return 0;
}
