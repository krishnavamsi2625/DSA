/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<stack>

using namespace std;

int main()
{
    string ch;
    cin>>ch;
    stack<char> stack;
    int flag=1;
    for(int i=0;ch[i]!='\0';i++)
    {
        if(ch[i]=='[' ||ch[i]=='('||ch[i]=='{')
        {
            stack.push(ch[i]);
        }
        else
        {
            if(ch[i]=='}' and stack.top()=='{')
            {
                stack.pop();
            }
            else if(ch[i]==']' and stack.top()=='[')
            {
                stack.pop();
            }
            else if(ch[i]==')' and stack.top()=='(')
            {
                stack.pop();
            }
            else{
                cout<<ch[i]<<" "<<i;
                flag=0;
                break;
            }
        }
    }
    if(flag)
    cout<<"YES";
    else
    cout<<"NO";
    return 0;
}
