#include <stdio.h>
#define size 20
void selection_sort(int a[], int n)
{
    int i, j, pivot, temp;
    for (i = 0; i < n - 1; i++)
    {
        pivot = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[pivot])
            {
                pivot = j;
            }
        }
        temp = a[i];
        a[i] = a[pivot];
        a[pivot] = temp;
    }
}
void main()
{
    int a[20], i, n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
        scanf("%4d", &a[i]);
    printf("\nEnter the elements before sorting of the array: ");
    for (i = 0; i < n; i++)
        printf("%4d", a[i]);
    selection_sort(a, n);
    printf("\n Enter the elements after sorting of the array: ");
    for (i = 0; i < n; i++)
        printf("%4d", a[i]);
}
