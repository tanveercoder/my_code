#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char name[100];
    char book[100];
    int year; 
    struct node *next;
}*first=NULL,*last=NULL;

void add(struct node *p) 
{
    p = (struct node*) malloc(sizeof(struct node));

    if(first==NULL)
    {
        first=p; 
        last=p;
    }
    else
    {
        last->next=p;
        last=p;
    }
    
    printf("Enter First name of author:\n");
    scanf("%s", p->name);
    printf("Enter Title of the book:\n");
    scanf("%s", p->book);
    printf("Enter year of publication:\n");
    scanf("%d", &p->year);
    p->next=NULL;
}

void display(struct node *p)
{
    p=first;
    if(p==NULL)
    {
        printf("\n\nEMPTY\n\n");
    }
    else
    {
    while(p)
    {
        printf("\nNAME:%s\n",p->name);
        printf("BOOK TITLE:%s\n",p->book);
        printf("YEAR OF PUBLICATION:%d\n",p->year);
        printf("\n");
        p=p->next;
    }
    }
}
void delete(struct node *p,int pos)
{
    struct node *q;
    p=first;
    if(pos==1)
    {
        printf("\ndeleted data are:\n");
        printf("Author name is: %s\n",p->name);
        printf("Book name is: %s\n",p->book);
        printf("year of publication is: %d\n\n",p->year);
        first=p->next;
        free(p);
    }
    else
    {
        q=NULL;
        int i;
        for(i=0;i<pos-1&&p;i++)
        {
            q=p;
            p=p->next;
        }
        if(p)
        {
        printf("\ndeleted data are:\n");
        printf("Author name is: %s\n",p->name);
        printf("Book name is: %s\n",p->book);
        printf("year of publication is: %d\n\n",p->year);
        if(q==NULL)
        {
            q->next=p->next;
            last=p;
            free(p);
        }
        else
        {
            q->next=p->next;
            free(p);
        }
        }
    }
}
int main()
{
    int i,ch;
    while(1)
    {
        printf("Enter 1 to add information\n");
        printf("Enter 2 to delete information\n");
        printf("Enter 3 to display information\n");
        printf("Enter 4 to exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                add(first);
                break;
            }
            case 2:
            {
                int pos;
                printf("Enter position to delete\n");
                scanf("%d",&pos);
                delete(first,pos);
                break;
            }
            case 3:
            {
                display(first);
                break;
            }
            case 4:
            {
                exit(0);
            }
            default:
            printf("WRONG CHOICE\n");
        }
    }
}
