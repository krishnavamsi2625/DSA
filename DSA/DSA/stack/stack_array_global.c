/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#define size 10
int arr[size],top=-1;
int main()
{
    while(1)
    {
        printf("\nMENU\n1)ADD\n2)DELETE\n3)PEEK\n4)EXIT\nEnter your choice:- ");
        int ch;
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                if(top==size-1)
                {
                    printf("STACK FULL!!");
                    break;
                    
                }
                printf("Enter the value:- ");
                scanf("%d",&arr[++top]);
                printf("Inserted successfully!!");
                break;
            case 2:
                if(top==-1)
                {
                    printf("\nStack Empty!!");
                    break;
                }
                printf("\nDeleted %d",arr[top--]);
                break;
            case 3:
                if(top==-1)
                {
                    printf("Stack Empty!!");
                    break;
                }
                printf("\n%d at the top of stack",arr[top]);
                break;
            case 4:
                exit(0);
            default:
            printf("\nEnter correct choice");
        }
        
    }

    return 0;
}
/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#define size 10
int arr[size],top=-1;
int main()
{
    while(1)
    {
        printf("\nMENU\n1)ADD\n2)DELETE\n3)PEEK\n4)EXIT\nEnter your choice:- ");
        int ch;
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                if(top==size-1)
                {
                    printf("STACK FULL!!");
                    break;
                    
                }
                printf("Enter the value:- ");
                scanf("%d",&arr[++top]);
                printf("Inserted successfully!!");
                break;
            case 2:
                if(top==-1)
                {
                    printf("\nStack Empty!!");
                    break;
                }
                printf("\nDeleted %d",arr[top--]);
                break;
            case 3:
                if(top==-1)
                {
                    printf("Stack Empty!!");
                    break;
                }
                printf("\n%d at the top of stack",arr[top]);
                break;
            case 4:
                exit(0);
            default:
            printf("\nEnter correct choice");
        }
        
    }

    return 0;
}
