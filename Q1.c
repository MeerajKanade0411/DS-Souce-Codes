//Q1
#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int top=-1;
int stack[MAX];
void push(int item);
int pop();
int peek();
int empty();
int full();
int size();
void display();
int main()
{
    int choice;
    int x,p,item;
    do
    {
        printf("ENTER YOUR CHOICE\n");
        printf(" 1.PUSH\n 2.POP\n 3.PEEK\n 4.DISPLAY\n 5.SIZE\n 6.QUIT\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1://push//
            printf("ENTER ITEM TO BE PUSHED\n");
            scanf("%d",&item);
            push(item);
            break;
        case 2://pop//
            item=pop();
            printf("ITEM POPED IS %d\n",item);
            break;
        case 3://peek//
            x=peek();
            printf("the item present at top is %d\n",x);
            break;
        case 4://display//
            printf("ITEMS PRESENT ARE: \n");
            display();
            break;
        case 5: //size
            size();
            break;
        }
    }while(choice!=6);
    return 0;
}
void push(int item)
{
    if(full())
    {
        printf("Stack Overflow\n");
        return;
    }
    top=top+1;
    stack[top]=item;
}
int pop()
{
    int item;
    if(empty())
    {
        printf("Stack Underflow");
        exit(1);
    }
    item=stack[top];
    top=top-1;
    return item;
}
int peek()
{
    if(empty())
    {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top];
}
void display()
{
    int i;
    if(empty())
    {
        printf("Stack is empty");
        return;
    }
    printf("Stack elements: \n");
    for(i=top;i>=0;i--)
        printf("%d\n",stack[i]);
    printf("\n");
}
int size()
{
    if(empty())
    {
        printf("Stack underflow\n");
        exit(1);
    }
    printf("SIZE OF STACK IS %d",top+1);
}
int empty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
int full()
{
    if(top==MAX-1)
        return 1;
    else
        return 0;
}

