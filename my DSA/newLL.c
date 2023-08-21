#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*first=NULL,*last=NULL,*second=NULL,*third=NULL;
struct node *q=NULL;
void create(int a[],int n)
{
    struct node *t;
    t=malloc(sizeof(struct node));
    t->data=a[0];
    t->next=NULL;
    first=last=t;
    for(int i=1;i<n;i++)
    {
        t=malloc(sizeof(struct node));
        last->next=t;
        t->data=a[i];
        t->next=NULL;
        last=t;
    }
}
void create1(int a[],int n)
{
    struct node *t;
    second=malloc(sizeof(struct node));
    second->data=a[0];
    second->next=NULL;
    second=last=t;
    for(int i=1;i<n;i++)
    {
        t=malloc(sizeof(struct node));
        last->next=t;
        t->data=a[i];
        t->next=NULL;
        last=t;
    }
}
void display(struct node *p)
{
    // p=first;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
// void display1(struct node *p)
// {
//     p=second;
//     while(p)
//     {
//         printf("%d ",p->data);
//         p=p->next;
//     }
//     printf("\n");
// }
void revNUM(struct node *p)
{
    int a[100];
    int i=0;
    p=first;
    while(p!=NULL)
    {
        a[i]=p->data;
        p=p->next;
        i++;
    }
    p=first;
    while(p)
    {
        p->data=a[--i];
        p=p->next;
    }
}
void revLINK(struct node *p)
{
    struct node *q,*r;
    p=first;
    r=q=NULL;
    while(p)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}
int rev(struct node *q,struct node *p)
{
    if(p)
    {
        rev(p,p->next);
        p->next=q;
    }
    else
    first=q;
}
int count(struct node *p)
{
    p=first;
    int count=0;
    while(p)
    {
        count++;
        p=p->next;
    }
    return count;
}
void sort(struct node *p,int count)
{
    struct node *q;
    int temp;
    p=first;
    q=p->next;
    while(p!=last)
    {
        while(q)
        {
            if(p->data>q->data)
            {
                temp=p->data;
                p->data=q->data;
                q->data=temp;
            }
            q=q->next;
        }
        p=p->next;
        q=p->next;
        
    }
}
// void sort1(struct node *p,int count)
// {
//     struct node *q;
//     int temp;
//     p=second;
//     q=p->next;
//     while(p!=last)
//     {
//         while(q)
//         {
//             if(p->data>q->data)
//             {
//                 temp=p->data;
//                 p->data=q->data;
//                 q->data=temp;
//             }
//             q=q->next;
//         }
//         p=p->next;
//         q=p->next;
        
//     }
// }
void merge(struct node *p,struct node *q)
{
    p=first;
    q=second;
    if(p->data<q->data)
    {
        third=last=p;
        p=p->next;
        last->next=NULL; 
    }
    else
    {
        third=last=q;
        q=q->next;
        last->next=NULL; 
    }
    while(p&&q)
    {
        if(p->data<q->data)
        {
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else
        {
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p)
    {
        last->next=p;
    }
    else
     {
        last->next=q;
    }
    
}
void main()
{
    int a[]={2,3,4,5,6,77,4,2,4,6,9};
    int b[]={99,32,56,75,42,69};
    create(a,6);
    display(first);
    revNUM(first);
    display(first);
    revLINK(first);
    display(first);
    rev(q,first);
    display(first);
    int c=count(first);
    sort(first,c);
    display(first);
    create1(b,6);
    display(second);
    // sort(b,6);
    // display(second);
    // display(first);
    // merge(first,second);
    // display(third);
    
}