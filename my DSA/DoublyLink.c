#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *first=NULL,*last=NULL;
void insert(struct node *p)
{
    struct node *t;
    t=malloc(sizeof(struct node));
    int x;
    printf("Enter a number\n");
    scanf("%d",&x);
    t->prev=last;
    t->data=x;
    t->next=NULL;
    if(first==NULL)
    {
        first=t;
        last=t;
    }
    else
    { 
        last->next=t;
        last=t;
    }
    printf("%d\n",last->next);
    printf("%d\n",t->prev);
    printf("%d\n",t->data);
}


int main()
{
    struct node *p;
    p=malloc(sizeof(struct node));
    while(1)
    {
    printf("Doubly Linked List\n1.Push\n2.Pop\n3.Display\n4.exit");
    printf("\nEnter your choice\n");
    int ch;
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        {
            insert(p);
            break;
        }
        case 2:
        {
          //  pop();
            break;
        }
        case 3:
        {
          //  display();
            break;
        }
        case 4:
        {
           //exit(0);
            break;
        }
        default:
        printf("Wrong Choice\n");
    }
}
}