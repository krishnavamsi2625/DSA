/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partison(int arr[],int low,int high)
{
    int swapindex=low-1;
    int pivot=arr[high];
    int j;
    for(j=low;j<=high-1;j++)
    {
        if(arr[j]<pivot)
        {
            swapindex++;
            swap(&arr[swapindex],&arr[j]);
        }
    }
    swap(&arr[swapindex+1],&arr[high]);
    return (swapindex+1);
}
void quicksort(int arr[],int low,int high)
{   if(low<high)
    {
        int indexpi=partison(arr,low,high);
        quicksort(arr,low,indexpi-1);//left
        quicksort(arr,indexpi+1,high);//right
        
    }
    
        
}
int main()
{
    int a[]={2,4,8,7,6,5,2,25,45,80,20,25,75,60,40,30,70,15,85,50,50};
    int len=sizeof(a)/sizeof(a[0]);
    quicksort(a,0,len-1);
    int i;
    for( i=0;i<len;i++)
    printf("%d ",a[i]);

    return 0;
}
