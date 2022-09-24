#include<iostream>
using namespace std;
struct Queue{
    int front,rear,size;
    int *array;
};
typedef struct Queue queue;
queue* create(int x)
{
    queue* temp=(queue*)malloc(sizeof(queue));
    temp->array=(int*)malloc(sizeof(int)*x);
    temp->front=-1;
    temp->rear=-1;
    temp->size=x;
    return temp;
}
void enque(queue *q,int x)
{   if(q->front==-1)
    {
        q->front=0;
    }
    else if(q->rear==q->size-1 && q->front==0)
    {
        cout<<"queue already full"<<endl;
        return;
    }
    else if(q->rear-q->front==-1)
    {
        cout<<"queue already full"<<endl;
        return;
    }
    else if(q->rear==q->size-1 && q->front!=0 )
    {
        q->rear=-1;
    }
    cout<<"Element  "<<x<<" added to queue"<<endl;
    q->rear++;
    q->array[q->rear]=x;
    
}
void deque(queue * q)
{   
    if(q->front==-1)
    {
        cout<<"No elements in queue!!"<<endl;
        return;
    }
    cout<<"dequeed Element :- "<<q->array[q->front]<<endl;
    if(q->front==q->rear)
    {
        q->front=-1;q->rear=-1;
    }
    else if(q->front==q->size-1 && q->rear!=q->size-1)
    {
        q->front=0;
    }
    else
    {
        q->front++;
    }
}
void display(queue *q)
{   if(q->front==-1)
    {
        cout<<"The List is Empty!!";
        return;
    }
    int i=q->front;
    cout<<"The Queue is :-"<<endl;
    while(1)
    {   if(i==q->size)
        {
            i=0;
        }
        cout<<q->array[i]<<" ";
        if(i==q->rear)
        {
            break;
        }
        i++;
    }
    cout<<endl;
}

int  main()
{
    queue* q;
    q=create(5);
    deque(q);
    enque(q,1);
    enque(q,2);
    enque(q,3);
    enque(q,4);
    enque(q,5);
    enque(q,6);
    deque(q);
    enque(q,6);
    deque(q);
    enque(q,7);
    enque(q,8);
    display(q);
}