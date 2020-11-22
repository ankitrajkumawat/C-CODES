/*Que- Write a menu driven program for implementation of Singly Linked List which consist of the following operations:

1. Insert a new element at the end of the list(without having last pointer)

2. Insert at any specific location

3. Delete an element from the beginning

4. Print the contents of the entire list

5. Search any specific element and print the address of the node containing that element*/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node *next;
};

struct Node *head = NULL;
int size = 0;

void insert(int data, int pos)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->key = data;
    newNode->next = NULL;

    struct Node *curNode = head;
    int count = 1;

    if (pos == 1)
    {
        newNode->next = head;
        head = newNode;
    }

    else
    {
        while (count < pos - 1 && curNode != NULL)
        {
            curNode = curNode->next;
            count++;
        }
        newNode->next = curNode->next;
        curNode->next = newNode;
    }

    size++;
}

void delete ()
{
    struct Node *temp = head;
    head = head->next;
    free(temp);
}

void printList()
{
    struct Node *curNode = head;

    printf("List: ");
    while (curNode != NULL)
    {
        printf("%d ", curNode->key);
        curNode = curNode->next;
    }
    printf("\n");
}

void search(int elem)
{
    struct Node *curNode = head;
    while (curNode != NULL)
    {
        if (curNode->key == elem)
        {
            printf("Address of %d: %p\n", elem, curNode);
            return;
        }
        curNode = currentNode->next;
    }
    printf("Sorry! The element does not exists");
}

void main()
{
    int choice, elem, pos;

    while (1)
    {
        printf("\nAvailable Operations:\n1) Insert an element at last\n2) Insert at any position\n3) Delete elements from beginning\n4) Print the list\n5) Search\n6) Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element: ");
            scanf("%d", &elem);
            insert(elem, size + 1);
            break;

        case 2:
            printf("Enter the element and its position(starting from 1): ");
            scanf("%d %d", &elem, &pos);
            insert(elem, pos);
            break;

        case 3:
            delete ();
            break;

        case 4:
            printList();
            break;

        case 5:
            printf("Enter the element: ");
            scanf("%d", &elem);
            search(elem);
            break;

        case 6:
            exit(0);

        default:
            printf("Invalid Choice");
        }
    }
}
