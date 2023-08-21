#include<stdio.h>
int top=-1;
int stack[100];
int N;
void push()
{
    int x;
    if(top==N-1)
    {
        printf("Stack Overflow");
    }
    else
    {
        printf("Enter element \n");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}
void pop()
{
    if(top==-1)
    {
        printf("Stack Underflow");
    }
    else
    {
        int x=stack[top];
        top--;
        printf("Popped element is %d\n",x);
    }
}
void display()
{
    int i;
    if(top!=-1)
    {
    printf("The Elements Are \n");
    for(i=0;i<=top;i++)
    {
        printf("%d \t",stack[i]);
    }
    }
    else
    printf("Stack Underflow \n");
}
int main()
{
    printf("Enter Size of Stack\n");
    scanf("%d",&N);
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
           //exit(0);
            break;
        }
        default:
        printf("Wrong Choice\n");
    }
}
}