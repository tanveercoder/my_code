#include<stdio.h>
#include<stdlib.h>
void SelectionSort(int b[])
{
    int low=b[0];
    for(int i=0;i<6;i++)
    {
        for(int j=i+1;j<6;j++)
        {
            if(b[j]<low)
            {
                int temp=low;
                low=b[i];
                b[i]=low;
            }
        }
    }
}
void main()
{
    int a[]={7,4,10,8,3,1};
    SelectionSort(a);
    for(int k=0;k<6;k++)
    {
        printf("%d "a[k]);
    }
}