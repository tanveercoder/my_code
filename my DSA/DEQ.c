#include<stdio.h>
#include<stdlib.h>
struct Queue
{
    int size;
    int f;
    int r;
    int *Q;
};
void ER(struct Queue *q,int x)
{
        q->r++;
        q->Q[q->r]=x;
        printf("%d",q->Q[q->r]);
}
void EF(struct Queue *q,int x)
{
        q->f--;
        q->Q[q->f]==x;
}
int DR(struct Queue *q)
{
    int x;
    if(q->r==q->size-1)
    printf("EMPTY\n");
    else
    {
        x=q->Q[q->r];
        q->r--;
    }
    printf("%d\n",x);
    return 0;
}
int DF(struct Queue *q)
{
    int x;
    if(q->r==q->size-1)
    printf("EMPTY\n");
    else
    {
        x=q->Q[q->f];
        q->f--;
    }
    printf("%d\n",x);
    return 0;
}
void Display(struct Queue *q)
{
    int i;
    if(q->f==-1 && q->r==-1||q->r==q->f)
    printf("Empty");
    else if(q->f==-1&&q->r!=-1)
    {
        for(i=q->f+1;i<=q->r;i++)
        printf("%d",q->Q[i]);
    }
    else
    {
        for(i=q->f;i<=q->r;i++)
        printf("%d",q->Q[i]);
    }
    printf("\n");
}
void main()
{
    int x;
    struct Queue *q;
    q=malloc(sizeof(struct Queue));
    printf("Enter Size\n");
    scanf("%d",&q->size);
    q->Q=(int*)malloc(q->size*sizeof(int));
    q->f=-1;
    q->r=-1;
      while(1)
    {
    printf("Stack using array\n1.Push Rear\n2.push front\n3.pop front\n4.pop rear\n5.Display\n6.exit");
    printf("\nEnter your choice\n");
    int ch;
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        {
            if(q->r==q->size-1)
            printf("Cannot be inserted\n");
            else
            {
            printf("Enter Number\n");
            scanf("%d",&x);
            ER(q,x);
            }
            break;
        }
        case 2:
        {
            if(q->f==-1||q->r==0)
                printf("element cannot be inserted from front\n");
            else
                printf("Enter a number\n");
                scanf("%d",&x);
                EF(q,x);
            break;
        }
        case 3:
        {
            DR(q);
            break;
        }
        case 4:
        {
           DF(q);
           break;
        }
        case 5:
        {
            Display(q);
            break;
        }
        case 6:
        {
            exit(0);
        }
        default:
        printf("Wrong Choice\n");
    }
}
}