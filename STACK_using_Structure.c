/*Stack using Structure*/
#include <stdio.h>
#include <conio.h>
#define max 50
int push();
int pop();
int display();
int initial();
struct stack
{
    int top;
    int st[max];
};
struct stack *ptr;
int main()
{
    int ch;
    char c;
    //clrscr();
    initial();
    do
    {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            getch();
            break;
        case 3:
            display();
            getch();
            break;
        default:
            printf("Wrong choice");
            break;
        }
    } while (ch != 4);
    return 0;
}
int initial()
{
    ptr->top = -1;
    return 0;
}
int push()
{
    int item;
    if (ptr->top >= max - 1)
        printf("Stack is full");
    else
    {
        printf("Enter item:");
        scanf("%d", &item);
        ptr->top += 1;
        ptr->st[ptr->top] = item;
    }
    return 0;
}
int pop()
{
    int item;
    if (ptr->top < 0)
        printf("Stack is empty");
    else
    {
        item = ptr->st[ptr->top];
        printf("Pop item is %d\n", item);
        ptr->top--;
    }
    return 0;
}
int display()
{
    int i;
    for (i = ptr->top; i >= 0; i--)
    {
        printf("%d\n", ptr->st[i]);
    }
    return 0;
}
