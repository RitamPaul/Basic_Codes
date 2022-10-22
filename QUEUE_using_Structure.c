/*Queue using Structure*/
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 50
struct queue
{
    int queue_arr[MAX];
    int rear;
    int front;
};
typedef struct queue node;
void insert(node *q)
{
    int added_item;
    if (q->rear == MAX - 1)
    {
        printf("\nQueue Overflow\n");
        getch();
    }
    else
    {
        if (q->front == -1)
            q->front = 0;
        printf("\nInput the element for adding in queue:");
        scanf("%d", &added_item);
        q->rear = q->rear + 1;
        q->queue_arr[q->rear] = added_item;
    }
}

void del(node *q)
{
    if (q->front == -1 || q->front > q->rear)
    {
        printf("\nQueue Underflow\n");
    }
    else
    {
        printf("\nElement deleted from queue is : %d\n", q->queue_arr[q->front]);
        q->front = q->front + 1;
    }
}
void display(node *q)
{
    int i;
    if (q->front == -1 || q->front > q->rear)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("\nQueue is :\n");
        for (i = q->front; i <= q->rear; i++)
            printf("%d ", q->queue_arr[i]);
        printf("\n");
    }
}
void main()
{
    int choice;
    struct queue *r;
    r->rear = -1;
    r->front = -1;
    while (1)
    {
        //clrscr();
        printf("\n1.Insert\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Quit\n");
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert(r);
            break;
        case 2:
            del(r);
            getch();
            break;
        case 3:
            display(r);
            getch();
            break;
        case 4:
            exit(0);
        default:
            printf("\n Wrong choice\n");
        }
    }
}