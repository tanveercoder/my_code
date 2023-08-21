#include<stdio.h>
#include<stdlib.h>
int InsertionSort(int A[])
{   
    for(int i=0;i<5;i++)
    {
        int current=A[i];
        int j=i-1;
        while(j>=0 && A[j]>current)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=current;
    }
    return A[5];
}
void main()
{
    int A[]={15,16,6,8,5};
    InsertionSort(A);
    for(int i=0;i<5;i++)
    {
        printf("%d ",A[i]);
    }
}