#include<stdio.h>
#include<stdlib.h>
//+#include<stdbool>
int MIN_INT;
int action=0;
struct node
{
    int data;
    struct node *next;
}*first=NULL,*last=NULL;
void create(int A[],int n)
{
    int i;
    struct node *t;
    for(i=0;i<n;i++)
    {
        t=malloc(sizeof(struct node));
        if(first==NULL)
        {
            first=t;
            t->data=A[i];
            t->next=NULL;
            last=t; 
            //printf("%d ",t->data);
        }
        else{
            t->data=A[i];
            t->next=NULL;
            last->next=t;
            last=t;
            //printf("%d ",t->data);
        }
    }
}
void display(struct node *p)
{
    //printf("%d ",p->data);
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
int count(struct node *p)
{
    int c=0;
    while(p)
    {
        c++;
        p=p->next;
    }
    return c;
}
int rcount(struct node *p)
{
    int c=0;
    if(p==0)
    return 0;
    return rcount(p->next)+1;
    
}
int add(struct node *p)
{
    int sum=0;
    while(p)
    {
    sum=sum+p->data;
    p=p->next;
    }
    return sum;
}
int radd(struct node *p)
{
    if(p==0)
    {
        return 0;
    }
    else
    {
        return p->data+radd(p->next);
    }
}
int max(struct node *p)
{
    int m=first->data;
    while(p)
    {
        if(m<p->data)
        m=p->data;
        p=p->next;
    }
    return m;
}
int rmax(struct node *p)
{
    int x;
    if(p==0)
    return MIN_INT;
    else
    {
    x=rmax(p->next);
    if(x>p->data)
    {
    return x;
    }
    return p->data;
    }
}
void search(struct node *p,int key)
{
    int k=0;
    while(p)
    {
        if(p->data==key)
        {
        printf("Key found\n%d\n",p->data);
        k+=1;
        }
        p=p->next;
    }
    if(k==0)
    printf("key not found\n");
}
int rsearch(struct node *p,int key)
{
    if(p==NULL)
    {
        action=1;
        return 0;
    }
    if(key==p->data)
    return 1;
    else
    return rsearch(p->next,key);
}
void sort(int A[])
{
    int i;
    for (i=0; i<12; i++){
   for (int j=i+1; j<13; j++){
      if (A[i] > A[j]){
        int temp=A[i];
         A[i] = A[j];
         A[j] = temp;
      }
   }
}
 
     for(i=0;i<13;i++)
    {
         printf("%d ",A[i]);
    }
     printf("\n");
}
void insert(struct node *p,int pos,int x)
{
    struct node *t;
    int i;
    t=malloc(sizeof(struct node));
    if(pos==0)
    {
        t->data=x;
        t->next=first;
        first=t;
    }
    else
    {
        p=first;
        for(i=0;i<pos-1;i++)
        {
            p=p->next;
        }
        t->data=x;
        t->next=p->next;
        p->next=t;
    }
}
void sortedinsert(struct node *p,int x)
{
    struct node *t,*q=NULL;
    p=first;
    t=malloc(sizeof(struct node));
    while(p&&p->data<x)
    {
        q=p;
        p=p->next;
    }
    t->data=x;
    t->next=q->next;
    q->next=t;
}
void del(struct node *p,int pos)
{
    struct node *q=NULL;
    p=first;
    if(pos==1)
    {
        q=first;
        first=first->next;
        free(q);
    }
    else
    {
    for(int i=0;i<pos-1;i++)
    {
        q=p;
        p=p->next;
    }
    q->next=p->next;
    free(p);;
    }
}
int checksort(struct node *p)
{
    int x=first->data;
    while(p)
    {
        if(p->data<x)
        return 0;
        x=p->data;
        p=p->next;
    }
    return 1;
}
void DEldup(struct node *p)
{
    struct node *q;
    q=first;
    p=first->next;
    while(p)
    {
        if(p->data!=q->data)
        {
            q=p;
            p=p->next;
        }
        else
        {
            q->next=p->next;
            free(p);
            p=q->next;
        }
    }
}
int main()
{ 
   // int i,j,temp=0;
    int A[]={2,4,6,7,78,4,2,5,7,9,6,3,6};
    sort(A);
    create(A,5);
    display(first);
    printf("\n%d \n",count(first));
    printf("\n%d \n",rcount(first));
    printf("\n%d \n",add(first));
    printf("\n%d \n",radd(first));
    printf("\n%d \n",max(first));
    printf("\n%d \n",rmax(first));
    search(first,2);
    printf("\n\n");
    int x=rsearch(first,4);
    printf("%d",x);
    if(x==0&&action==1)
    {
    printf("not found");
    }
    else
   {
    printf("key found\n");
   }
    insert(first,3,87);
    sortedinsert(first,10);
    display(first);
    del(first,3);
    display(first);
    printf("%d ", checksort(first));
    DEldup(first);
    display(first);
   
}