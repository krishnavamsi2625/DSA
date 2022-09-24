/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<stdlib.h>
struct stack
{ 
  int top,max;
  int *array;
};
typedef struct stack stack;
stack* create(int max)
{
    stack *temp=(stack*)malloc(sizeof(stack));
    temp->top=-1;
    temp->max=max;
    temp->array=(int *)malloc(sizeof(int)*10);
    return temp;
}
int isfull(stack * s)
{
    if(s->top==s->max-1)
    return 1;
    return 0;
}
int isempty(stack * s)
{
    if(s->top==-1)
    return 1;
    return 0;
}
stack * peek(stack * s)
{   if(isempty(s))
    {
        printf("Stack is empty\n");
        
    }
    else 
    {
        printf("%d\n",s->array[s->top]);
    }
    return s; 
}
void push(stack *s,int x)
{
    if(isfull(s))
    {
        printf("stack full!!\n");
        return;
    }
    s->top++;
    s->array[s->top]=x;
}
stack   *pop(stack * s)
{   if(isempty(s))
    {
        printf("stack empty!!\n");
    }
    else{
        printf("%d\n",s->array[s->top--]); 
    }
    return s;
     
}
int main()
{   
    stack  *s1;
    s1=create(5);
    while(1)
    {   
        int ch;
        printf("\nMENU\n1)ADD 2)DELETE 3)PEEK 4)EXIT\nENTER YOUR CHOICE:-");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter value to be inserted:-");
                int x;
                scanf("%d",&x);
                push(s1,x);
                printf("Inserted sucessfully");
                break;
            case 2:
                pop(s1);
                break;
            case 3:
                peek(s1);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Input!!");
        }
    }
}
