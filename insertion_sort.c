#include<stdio.h>
void insertion_sort(int a[], int n)
{
    int i,j,pivot;
    for(i=1;i<n;i++)
    {
        pivot=a[i];
        for(j=i-1;j>=0;j--)
        {
            if(a[j]>pivot)
            {
                a[j+1]=a[j];
            }
            else
            {
                break;
            }    
        }
        a[j+1]=pivot;
    }
}
void main()
{
    int a[100],n;
    printf("element of array");
    scanf("%d",&n);
    printf("enter the array elements");
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("before the array");
    for(int i=0;i<n;i++)
    printf("%d ",a[i]);
    insertion_sort(a, n);
    printf("after the array");
    for(int i=0;i<n;i++)
    printf("%d ",a[i]);
}
