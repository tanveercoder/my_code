#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top=0;
void push()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    int x;
    printf("Enter value");
    scanf("%d",&x);
    newnode->data=x;
    newnode->next=top;
    top=newnode;
}
void pop()
{
    struct node *temp;
    temp=top;
    if(top==0)
    {
        printf("Stact Underflow\n");
    }
    else
    {
        printf("%d",top->data);
        top=top->next;
        free(temp);
    }
}
void display()
{
    struct node *temp;
    temp=top;
    if(top==0)
    {
        printf("Stack Empty");
    }
    else
    {
        while(temp!=0)
        {
            printf("%d",temp->data);
            temp=temp->next;
        }
    }
}
int main()
{
     printf("Stack using array\n1.Push\n2.Pop\n3.Display\n4.exit");
    while(1)
    {
    printf("\nEnter your choice");
    int ch;
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        {
            push();
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
           return 0;
        }
        default:
        printf("Wrong Choice\n");
    }
}
}
