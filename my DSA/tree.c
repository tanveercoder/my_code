#include<stdio.h>
#include<stdlib.h>
struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root=NULL;
struct Queue
{
    int size;
    int front;
    int rear;
    struct Node **Q;
};
void create(struct Queue *q,int size)
{
    q->size=size;
    q->front=q->rear=0;
    q->Q=(struct node **)malloc(q->size*sizeof(struct Node *));
}
void enque(struct Queue *q,struct Node *x)
{
    if((q->rear+1)%q->size==q->front)
    printf("Queue is Full\n");
    q->rear=(q->rear+1)%q->size;
    q->Q[q->rear]=x;
}
struct Node * dequeue(struct Queue *q)
{
    struct Node *x=NULL;
    if(q->front==q->rear)
    printf("Queue is Empty\n");
    {
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}
int isEmpty(struct Queue *q)
{
    return q->front=q->rear;
}
void Treecreate()
{
    struct Node *p,*t;
    int x;
    struct Queue *q;
    create(q,100);
    printf("Enter root value\n");
    scanf("%d",&x);
    root=malloc(sizeof(struct Node));
    root->data=x;
    root->lchild=root->rchild=NULL;
    enque(q,root);
    while(isEmpty(q))
    {
        p=dequeue(q);
        printf("Enter left child of %d\n",p->data);
        scanf("%d",&x);
        if(x!=1)
        {
            t=malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enque(q,t);
        }
        printf("Enter right child of %d\n",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enque(q,t);
        }
    }
}
void preorder(struct Node *p)
{
    if(p)
    {
        printf("%d",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
int main()
{
    Treecreate();
    preorder(root);

    return 0;
}