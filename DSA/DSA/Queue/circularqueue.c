#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

// Basic struct for queue
struct Queue 
{ 
    int front, rear, currSize; 
    unsigned maxCapacity; 
    // we are storing string in integer array, this will not give error
    // as values will be stored in ASCII and returned in ASCII thus, returned as string again
    int* array; 
}; 

// Here we initialize queue and init. Current size of queue to 0  
struct Queue* createQueue(unsigned maxCapacity) 
{ 
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue)); 
    queue->maxCapacity = maxCapacity;
    queue->front = queue->currSize = 0;
    queue->rear = maxCapacity - 1;  // This is important, see the enqueue 
    queue->array = (int*) malloc(queue->maxCapacity * sizeof(int)); 
    return queue; 
} 

// Will return true if queue Current size has reached maxCapacity 
int isFull(struct Queue* queue) 
{
    if(queue->currSize == queue->maxCapacity)
        printf("Can't insert as queue is full\n");
        
    return (queue->currSize == queue->maxCapacity);  
} 

// Will return true if queue Current size is 0
int isEmpty(struct Queue* queue) 
{  
    if(queue->currSize == 0)
        printf("Can't deuque as queue is empty\n");
    return (queue->currSize == 0); 
} 

// Here we add new item to queue and change rear and Current size  
void enqueue(struct Queue* queue, int item) 
{ 
    if (isFull(queue)) 
        return; 

    //Bcz, queue->rear is set up to maxCapacity adding + 1 
    //and % maxCapacity will set rear to start of queue
    //enqueue happens at the rear value always so to maintain First in first out 
    queue->rear = (queue->rear + 1)%queue->maxCapacity; 
    queue->array[queue->rear] = item; 
    queue->currSize = queue->currSize + 1; 
    printf("%d added to the queue at array pos:%d\n", item,queue->rear); 
} 

// Here we remove or dequeue from queue and 
//also change the front value and Current size of queue  
void dequeue(struct Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return; 
    int item = queue->array[queue->front]; 
    queue->front = (queue->front + 1)%queue->maxCapacity; 
    queue->currSize = queue->currSize - 1;
    printf("\n%d dequeued from queue, new front is at pos:%d\n", item,queue->front);
}

void display(struct Queue* queue)
{
    if(queue->currSize == 0)
        printf("\nQueue was Empty!!!");
   else{
        int i=queue->front, j;
        printf("\nQueue :\n");
      
        for(j=0; j<queue->currSize; j++)
	        printf("%d ",queue->array[(i+j)%queue->maxCapacity]);
   }
}
// Main function to run queue program
int main() 
{ 
    struct Queue* queue = createQueue(5); 

    enqueue(queue,10);
    enqueue(queue,20);
    enqueue(queue,30);
    enqueue(queue,40);
   
   
    dequeue(queue);
    dequeue(queue);
    
    enqueue(queue,50);
    enqueue(queue,60);

    display(queue);
    return 0; 
}
Overall Course Completion percentage