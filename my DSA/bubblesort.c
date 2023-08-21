#include<stdio.h>
#include<stdlib.h>
void BubbleSort(int A[])
{
    for(int i=0;i<4;i++)
    {
        int flag=0;
        for(int j=0;j<4-i;j++)
        {
            if(A[j]>A[j+1])
            {
                int temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0)
        break;
    }
}
void main()
{
    int A[]={15,16,6,8,5};
    BubbleSort(A);
    for(int i=0;i<5;i++)
    {
        printf("%d ",A[i]);
    }
}