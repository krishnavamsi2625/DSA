#include<iostream>
# define size 5
using namespace std;
int queue[size],front=-1,rear=-1;
void display()
{   if(front==-1)
    {
        cout<<"The List is Empty!!";
        return;
    }
    int i=front;
    cout<<"The Queue is :-"<<endl;
    while(1)
    {   if(i==size)
        {
            i=0;
        }
        cout<<queue[i]<<" ";
        if(i==rear)
        {
            break;
        }
        i++;
    }
    cout<<endl;
}
void enque(int x)
{   if(front==-1)
    {
        front=0;
    }
    else if(rear==size-1 && front==0)
    {
        cout<<"queue already full"<<endl;
        return;
    }
    else if(rear-front==-1)
    {
    	cout<<"queue already full"<<endl;
        return;
    	
	}
    else if(rear==size-1 && front!=0 )
    {
        rear=-1;
    }
    cout<<"Element  "<<x<<" added to queue"<<endl;
    queue[++rear]=x;
    
}
void deque()
{   
    if(front==-1)
    {
        cout<<"No elements in queue!!"<<endl;
        return;
    }
    cout<<"dequeed Element :- "<<queue[front]<<endl;
    if(front==rear)
    {
        front=-1;rear=-1;
    }
    else if(front==size-1 && rear!=size-1)
    {
        front=0;
    }
    else
    {
        front++;
    }
}
int  main()
{   deque();
    enque(1);
    enque(2);
    enque(3);
    enque(4);
    enque(5);
    deque();
    enque(6);
    deque();
    deque();
    deque();
    deque();
    deque();
    enque(1);
    display();
}
