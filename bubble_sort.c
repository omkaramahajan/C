#include <stdio.h>
#define size 20
void bubble_sort(int a[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
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
    bubble_sort(a, n);
    printf("\n Enter the elements after sorting of the array: ");
    for (i = 0; i < n; i++)
        printf("%4d", a[i]);
}