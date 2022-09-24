
#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node node;
int size(node ** head)
{   
    node *temp=*head;
    if(temp==NULL)
    {
        return 0;
    }
    int c=1;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        c++;
    }
    return c;
}
void deletes(node ** Head)
{
    if(size(Head)==0)
    {
        printf("List Empty\n");
        return;
    }
    node * head=*Head;
    int ch;
    printf("1)Delete at start\n2)Delete at end\n3)Delete at pos\nEnter your choice:-");
    scanf("%d",&ch);
    int pos;
    switch(ch)
    {
        case 1:
            pos=0;
            break;
        case 2:
            pos=size(Head);
            pos=pos-1;
            break;
        case 3:
            printf("Enter the postion:-");
            scanf("%d",&pos);
            pos=pos-1;
            break;
        default:
            printf("Enter the correct options");
                 
    }
    int x;
    if(pos>size(Head))
    {
        printf("Postion >size\n");
        return;
    }
    node *temp=*Head;
    int i=1;
    while(i<pos)
    {   
        temp=temp->next;
        i++;
    }
    if(pos==0)
    {   *Head=temp->next;
        printf("%d deleted sucessfully\n",temp->data);
        free(temp);
        return;
        
    }
    struct node * deleted=temp->next;
    temp->next=deleted->next;
    printf("%d deleted sucessfully\n",deleted->data);
    free(deleted);
    
    
    
}
void insert(node ** Head)
{   system("clear"); 
    node * head=*Head;
    int ch;
    printf("1)Insert at start\n2)Insert at end\n3)Insert at pos\nEnter your choice:-");
    scanf("%d",&ch);
    int pos;
    switch(ch)
    {
        case 1:
            pos=0;
            break;
        case 2:
            pos=size(Head);
            
            break;
        case 3:
            printf("Enter the postion:-");
            scanf("%d",&pos);
            pos=pos-1;
            break;
        default:
            printf("Enter the correct options");
                 
    }
    int x;
    if(pos>size(Head)+1)
    {
        printf("Postion >size\n");
        return;
    }
    printf("Enter the data:- ");
    scanf("%d",&x);
    node *temp=*Head;
    node * newnode=(node*)malloc(sizeof(node));
    newnode->data=x;
    int i=1;
    while(i<pos)
    {   
        temp=temp->next;
        i++;
    }
    if(*Head==NULL || pos==0)
    {   
        newnode->next=temp;
        *Head=newnode;
        //printf("\n%d,%d\n",temp->data,temp->next);
        
    }
    else
    {
        newnode->next=temp->next;
        temp->next=newnode;
    }
}
    
 void displays(node * head)
 { 
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
    
     
 }

int main()
{
 node *head=NULL;
 
 while(1)
 {  int ch;
    printf("1)add\n2)display\n3)Delete\nEnter your choice:-");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            insert(&head);
            break;
        case 2:
            displays(head);
            break;
        case 3:
            deletes(&head);
            break;
        case 4:
            exit(0);
        
    }
 }



    return 0;
}