#include<stdio.h>
#include<stdlib.h>
int fact(int n)
{
    if(n==0)
    return 1;
    else 
    return fact(n-1)*n;
}
int fib(int n)
{
    if(n==1||n==0)
    return 1;
    else 
    return fib(n-2)+fib(n-1);
}
void binarySearch(int arr[],int n,int ub,int lb)
{
    if(ub>lb)
    {
        printf("Number not found\n");
    }
    else
    {
    int mid=(ub+lb)/2;
    if(arr[mid]==n)
    {
        printf("Number found at index %d\n",mid);
        exit(0);
    }
    else if(arr[mid]>n)
    {
        binarySearch(arr,n,ub,mid-1);
    }
    else 
    {
        binarySearch(arr,n,mid+1,lb);
    }
    }
}
void TOH(int n,int A,int B,int C)
{
    if(n>0)
    {
        TOH(n-1,A,C,B);
        printf("from %d to %d\n",A,C);
        TOH(n-1,B,A,C);
    }

}
void main()
{
    int ch,n;
    printf("Programs using recursion\n1.Factorial\2.Fibonnacci\3.Tower of Hanoi\4.Binary search\nEnter Choice\n");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
    {
        printf("Enter a number\n");
        scanf("%d",&n);
        printf("The factorial of %d is %d\n",n,fact(n));
        break;
    }
    case 2:
    {
        printf("Enter number\n");
        scanf("%d",&n);
        printf("Fibonacci Series is\n");
        for(int i=0;i<n;i++)
        {
            printf("%d\t",fib(i));
        }
        break;
    }
    case 3:
    {
        printf("Enter no. of disks\n");
        scanf("%d",&n);
        printf("The sequence of moves involve are\n");
        TOH(n,1,2,3);
        //return 0;

    }
    case 4:
    {
        int arr[]={4,5,6,7,8,9,69,113,54};
        printf("Enter a number to search");
        scanf("%d",&n);
        int ub=0;
        int lb=n-1;
        binarySearch(arr,n,ub,lb);
        break;
    }
    
    default:
        break;
    }
}