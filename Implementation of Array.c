/*Que- Write a menu driven program for implementation of array which consist of the following operations:

1. Insert a new element at any specific location provided by user

2. Insert in the middle location (Suppose you are having 𝑛 elements in the array, if 𝑛 is odd insert at index location (𝑛−1)/2 otherwise insert at index location (𝑛/2).

3. Delete an element at index location=2. (Deletion is possible only when there are more than or equal to 3 elements in the array, you must perform left shifting for all the elements from index number 3 to the last element

4. Sort the elements in the decreasing order. (You may use any sorting algorithm- Insertion/ Selection/ Bubble)

5. Display the Contents of Array. (Must be implemented with the help of a function)*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void disp(int *m)
{
    printf("%d\t", *m);
}

int main()
{
    int arr[50], i, n, si, newElement, loc, j, a;
    printf("Enter the size of array\n");
    scanf("%d", &n);
    printf("\nEnter the elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Menu Operations\n1. Insertion Specific Location\n2. Insertion Middle Location\n3.Deletion Index 2\n4. Descending Sorting\n5.Display of Array\n6.Exit");
    printf("\nOperation index to be performed\n");
    scanf("%d", &si);

    switch (si)
    {
    case 1:
        printf("Enter the Input Data to be Inserted\n");
        scanf("%d", &newElement);
        printf("Enter the location\n");
        scanf("%d", &loc);
        for (i = n - 1; i >= loc - 1; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[loc - 1] = newElement;
        n++;
        printf("Elements of the array are:\n");
        for (i = 0; i < n; i++)
        {
            printf("%d\n", arr[i]);
        }
        break;
    case 2:
        printf("Enter the Input Data to be Inserted\n");
        scanf("%d", &newElement);
        if (n % 2 == 0)
        {
            loc = n / 2;
            for (i = n - 1; i > loc - 1; i--)
            {
                arr[i + 1] = arr[i];
            }
            arr[loc] = newElement;
            n++;
            printf("Elements of the array are:\n");
            for (i = 0; i < n; i++)
            {
                printf("%d\n", arr[i]);
            }
        }
        else
        {
            loc = (n + 1) / 2;
            for (i = n - 1; i > loc - 1; i--)
            {
                arr[i + 1] = arr[i];
            }
            arr[loc] = newElement;
            n++;
            printf("Elements of the array are:\n");
            for (i = 0; i < n; i++)
            {
                printf("%d\n", arr[i]);
            }
        }
        break;
    case 3:
        loc = 3;
        if (loc < 3 || loc > n)
        {
            printf("Operation not possible\n");
        }
        else
        {
            for (i = loc - 1; i < n - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            n--;
            printf("Array Updated and is as followed:\n");
            for (i = 0; i < n; i++)
            {
                printf("%d\n", arr[i]);
            }
        }
        break;
    case 4:
        for (i = 0; i < n; ++i)
        {
            for (j = i + 1; j < n; ++j)
            {
                if (arr[i] < arr[j])
                {
                    a = arr[i];
                    arr[i] = arr[j];
                    arr[j] = a;
                }
            }
        }
        printf("The numbers arranged in descending order are given below\n");

        for (i = 0; i < n; ++i)
        {
            printf("%d\n", arr[i]);
        }
        break;
    case 5:
        printf("\nElements in an array is: ");
        for (i = 0; i < n; i++)
        {
            disp(&arr[i]);
        }
        break;
    case 6:
        exit(0);
    }
}