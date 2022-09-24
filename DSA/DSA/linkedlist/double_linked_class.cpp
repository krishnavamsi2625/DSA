// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class node
{   public:
    int data;
    node * next;
    node * previous;
};
class dlist
{
    node * head;
    int size;
    public:
        dlist()
        {
            size=0;
            head=NULL;
        }
        void display();
        void insert();
        void deletes();
        void search();
        void rdisplay();
};
void dlist::insert()
{   int ch;
    cout<<"1)Insert at start\n2)Insert at end\n3)Insert at pos\nEnter your choice:-";
    cin>>ch;
    int pos;
    switch(ch)
    {
        case 1:
            pos=0;
            break;
        case 2:
            pos=size;
            break;
        case 3:
            cout<<"Enter the postion:-";
            cin>>pos;
            pos=pos-1;
            break;
        default:
            cout<<"Enter the correct options\n";
                 
    }
    int x;
    if(pos>size)
    {
        printf("Postion >size\n");
        return;
    }
    cout<<"Enter the data:- ";
    cin>>x;;
    node *newnode=new node();
    node *temp=head;
    newnode->data=x;
    int i=1;
    while(i<pos)
    {   
        temp=temp->next;
        i++;
    }
    if(head==NULL || pos==0)
    {   newnode->previous=NULL;
        newnode->next=head;
        head=newnode;
        //printf("\n%d,%d\n",temp->data,temp->next);
        
    }
    else
    {   newnode->previous=temp;
        newnode->next=temp->next;
        temp->next=newnode;
    }
    cout<<newnode->data<<" Added Sucessfully"<<endl;
    size++;
}
void dlist::display()
{   
    node *temp=head;
    if(head==NULL)
    {
        cout<<"list empty!!"<<endl;
        return;
    }
    for(int i=0;i<size;i++)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void dlist::rdisplay()
{   
    node *temp=head;
    if(head==NULL)
    {
        cout<<"list empty!!"<<endl;
        return;
    }
    for(int i=0;i<size-1;i++)
    {
        temp=temp->next;
    }
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->previous;
        
    }
}
void dlist::deletes()
{
    if(size==0)
    {
        printf("List Empty\n");
        return;
    }
    int ch;
    cout<<"1)Delete at start\n2)Delete at end\n3)Delete at pos\nEnter your choice:-";
    cin>>ch;
    int pos;
    switch(ch)
    {
        case 1:
            pos=0;
            break;
        case 2:
            pos=size;
            pos=pos-1;
            break;
        case 3:
            printf("Enter the postion:-");
            cin>>pos;
            pos=pos-1;
            break;
        default:
            printf("Enter the correct options");
                 
    }
    int x;
    if(pos>size)
    {
        printf("Postion >size\n");
        return;
    }
    node *temp=head;
    int i=1;
    while(i<pos)
    {   
        temp=temp->next;
        i++;
    }
 
    if(pos==0)
    { 
        head=temp->next;
        if(head!=NULL)
        head->previous=NULL;
        printf("%d deleted sucessfully\n",temp->data);
        free(temp);
        size--;
        return;
    }
    
    struct node * deleted=temp->next;
    temp->next=deleted->next;
    if(deleted->next!=NULL)
    deleted->next->previous=temp;
    printf("%d deleted sucessfully\n",deleted->data);
    size--;
    free(deleted);
    
}
int main() {
    // Write C++ code here
    dlist * list=new dlist();
    int ch;
    while(1)
    {
        cout<<endl<<"1)Insert\n2)Display\n3)Delete\n4)Reverse Display\n5)Exit\nEnter your choice:- ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                list->insert();
                break;
            case 2 :
                list->display();
                break;
            case 3:
                list->deletes();
                break;
            case 4:
                list->rdisplay();
                break;
            case 5:
                exit(0);
            default:
                cout<<"Wrong choice"<<endl;
        }
    }

    return 0;
}