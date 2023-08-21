#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
}*root=NULL;
struct node* Rsearch(struct node *t,int key)
{
    if(t==NULL)
    return NULL;
    if(t->data==key)
    return t;
    else if(key<t->data)
    return Rsearch(t->lchild,key);
    else
    return Rsearch(t->rchild,key);
}
struct node* search(struct node *t,int key)
{
    while(t!=NULL)
    {
        if(key==t->data)
        return t;
        else if (key<t->data)
        t=t->lchild;
        else
        t=t->rchild;
    }
    return NULL;
}
void Insert(struct node *t,int key)
{
    struct node *r=NULL,*p;
    while(t!=NULL)
    {
        r=t;
        if(key==t->data)
        return;
        else if(key<t->data)
        t=t->lchild;
        else
        t=t->rchild;
    }
    p=malloc(sizeof(struct node));
    p->data=key;
    p->lchild=p->rchild=NULL;
    if(key<r->data)
    r->lchild=p;
    else
    r->rchild=p;
}
struct node* RInsert(struct node *p,int key)
{
    struct node *t;
    if(p==NULL)
    {
        t=malloc(sizeof(struct node));
        t->data=key;
        t->lchild=t->rchild=NULL;
    }
    if(key<p->data)
    p->lchild=RInsert(p->lchild,key);
    else if(key>p->data)
    p->rchild=RInsert(p->rchild,key);

    return t;
}
int main()
{
    
}