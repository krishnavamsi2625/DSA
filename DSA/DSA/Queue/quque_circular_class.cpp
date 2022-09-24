/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
class quque
{   public:
    int front,rear,maxCapacity,cursize;
    int *array;
        quque(int x)
        {
            front=0;
            maxCapacity=x;
            cursize=0;
            array=new int[x];
            rear=maxCapacity-1;
            
        }
        void enque(int x);
        void deque();
        void display();
        int isFull();
        int isEmpty();
        
        
};void 
quque::enque(int x)
{
    if(isFull())
    {
        return;
    }
    cout<<x<<" element added to queue"<<endl;
    rear=(rear+1)%maxCapacity;
    cursize++;
    array[rear]=x;
}
void quque::deque()
{
    if(isEmpty())
    {
        return;
    }
    int temp=array[front];
    cout<<temp<<" element dequed from the queue"<<endl;
    front=(front+1)%maxCapacity;
    cursize--;
}
void quque::display()
{
    if(isEmpty())
    {
        return;
    }
    int i=front,j;
    cout<<"Queue:-"<<endl;
    for(int j=0;j<cursize;j++)
    {
        cout<<array[(i+j)%maxCapacity]<<" ";
    }
    cout<<endl;
    
}
int quque::isEmpty()
{
    if(cursize==0)
    {
        cout<<"Queue Empty!!"<<endl;
    }
    return(cursize==0);
}
int quque::isFull()
{
    if(cursize==maxCapacity)
    {
        cout<<"Queue Full!!"<<endl;
    }
    return(cursize==maxCapacity);
}
int main()
{
    quque q=quque(5);
    q.deque();
    q.display();
    q.enque(1);
    q.enque(2);
    q.enque(3);
    q.enque(4);
    q.enque(5);
    q.deque();
    q.deque();
    q.enque(6);
    q.enque(7);
    q.display();

    return 0;
}
