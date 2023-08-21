#include<stdio.h>
#include<stdlib.h>
struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};
void enque(struct Queue *q,int x)
{
    if(q->rear==q->size-1)
    {
        printf("Queue is Full\n");
    }
    else
    {
        q->rear++;
        q->Q[q->rear]=x;
    }
}
int deque(struct Queue *q)
{

    int x=-0;
    if(q->rear==q->front)
    {
        printf("Queue is empty\n");
    }
    else
    {
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}
void display(struct Queue *q)
{
    int i;
    if(q->front==q->rear)
    printf("Queue is Empty\n");
    else
    {
        for(i=q->front+1;i<=q->rear;i++)
        {
            printf("%d ",q->Q[i]);
        }
        
    }
}
int main()
{
    struct Queue *q;
    q=malloc(sizeof(struct Queue));
    printf("Enter size of queue\n");
    scanf("%d",&q->size);
    q->Q=(int*)malloc(q->size*sizeof(int));
    q->rear=-1;
    q->front=-1;
    while(1)
    {
    printf("Stack using array\n1.Push\n2.Pop\n3.Display\n4.exit");
    printf("\nEnter your choice");
    int ch;
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        {
            int x;
            printf("Enter Number\n");
            scanf("%d",&x);
            enque(q,x);
            break;
        }
        case 2:
        {
            deque(q);
            break;
        }
        case 3:
        {
            display(q);
            break;
        }
        case 4:
        {
           exit(0);
        }
        default:
        printf("Wrong Choice\n");
    }
}
}