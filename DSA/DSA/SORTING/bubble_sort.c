/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
void sort(int arr[],int len)
{
    for(int i=0;i<len-1;i++)
    {
        for(int j=0;j<len-1-i;j++)
        { 
            if(arr[j]>arr[j+1])
            { int tem=arr[j];
              arr[j]=arr[j+1];
              arr[j+1]=tem;
                
            }
        }
        
    }
}
int main()
{
    int a[]={5,4,8,6,2,4,7,-4,-2,-1,0,5,9,7,2,6,4,7,1,3,5};
    int len=sizeof(a)/sizeof(a[0]);
    sort(a,len);
    for(int i=0;i<len;i++)
    printf("%d ",a[i]);

    return 0;
}
