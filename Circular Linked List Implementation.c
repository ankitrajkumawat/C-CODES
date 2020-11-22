#include <stdio.h>
#include <stdlib.h>
struct Node;
typedef struct Node *PtrtoNode;
typedef PtrtoNode List;
typedef PtrtoNode Position;

struct Node
{
    int e;
    Position next;
};

void Insert(int x, List l, Position p)
{
    Position TmpCell;
    TmpCell = (struct Node *)malloc(sizeof(struct Node));
    if (TmpCell == NULL)
    {
        printf("Memory out of space");
    }
    else
    {
        TmpCell->e = x;
        TmpCell->next = p->next;
        p->next = TmpCell;
    }
}

int isLast(Position p, List l)
{
    return (p->next == l);
}

Position FindPrevious(int x, List l)
{
    Position p = l;
    while (p->next != l && p->next->e != x)
    {
        p = p->next;
    }
    return p;
}

void Delete(int x, List l)
{
    Position p, TmpCell;
    p = FindPrevious(x, l);
    if (!isLast(p, l))
    {
        TmpCell = p->next;
        p->next = TmpCell->next;
        free(TmpCell);
    }
    else
    {
        printf("Element Not Found");
    }
}

void Display(List l)
{
    printf("List Elements are ::");
    Position p = l->next;
    while (p != l)
    {
        printf("%d->", p->e);
        p = p->next;
    }
}

void main()
{
    int x, pos, ch, i;
    List l, l1;
    l = (struct Node *)malloc(sizeof(struct Node));
    l->next = l;
    List p = l;
    printf("Graded Lab 3 Circular Linked List Menu Driven Code");
    do
    {
        printf("\n\n1.Insert\t2.Delete\t3.Display\t4.Quit\n\nEnter The Choice ::");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            p = l;
            printf("Enter the Element to be Inserted");
            scanf("%d", &x);
            printf("Enter the Position of the Element");
            scanf("%d", &pos);
            for (i = 1; i < pos; i++)
            {
                p = p->next;
            }
            Insert(x, l, p);
            break;
        case 2:
            p = l;
            printf("Enter element to be deleted :: ");
            scanf("%d", &x);
            Delete(x, p);
            break;

        case 3:
            Display(l);
            break;
        }
    } while (ch < 4);
    return 0;
}