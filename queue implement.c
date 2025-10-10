#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
struct queue{
int front,rear;
int data[SIZE];

};
typedef struct queue QUEUE;
void enqueue(QUEUE *q,int item){
if(q->rear==SIZE-1)
    printf("\n QUEUE OVERFLOW-Queue is full\n");
else{
    q->rear++;
    q->data[q->rear]=item;
    if(q->front==-1)
       q->front=0;
        printf("\n INSERTED %d into the queue |n",item);

}
   }
void dequeue(QUEUE *q){
if(q->front==-1)
    printf("\n queue is underflow or empty");
else{
    printf("\n deleted element is %d\n",q->data[q->front]);
    if(q->front==q->rear){
        q->front=-1;
        q->rear=-1;}
    else{
        q->front++;
    }

}
}
void display(QUEUE q)
{
    int i;
    if(q.front==-1){
        printf("\n queue is empty\n");}
    else{
        printf("\n queue contents area:\n");
        for(i=q.front;i<=q.rear;i++){
            printf("%d\t",q.data[i]);
            printf("\n");
        }
    }
    }


int main()
{int item,ch;
QUEUE q;
q.front=-1;
q.rear=-1;
while(1){
    printf("\n 1-enqueue\n 2-dequeue\n 3-display\n 4-exit\n");
    printf("\n read the choice:");
    scanf("%d",&ch);
    switch(ch){
case 1:
    printf("\n insert element to insert: ");
    scanf("%d",&item);
    enqueue(&q,item);
    break;
case 2:
    dequeue(&q);
    break;

case 3:
    display(q);
    break;
default: exit(0);
    }
}
    return 0;
}
