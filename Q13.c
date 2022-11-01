//Q13
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct stack
{
    int data;
    struct stack *next;
};
struct stack *top=NULL;
struct stack *push(struct stack *,int);
struct stack *display(struct stack *);
struct stack *pop(struct stack *);
int peek(struct stack *);
int main(int argc,char *argv[])
{
    int val,option;
    do
    {
        printf("MAIN MENU\n");
        printf("1.PUSH\n");
        printf("2.POP\n");
        printf("3.PEEK\n");
        printf("4.DISPLAY\n");
        printf("5.EXIT\n");
        printf("ENTER YOUR OPTION\n");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            printf("enter number to be pushed on stack  ");
            scanf("%d",&val);
            top=push(top,val);
            break;
        case 2:
            top=pop(top);
            break;
        case 3:
            val=peek(top);
            if(val!=-1)
                printf("the value at top of stack is : %d\n",val);
            else
                printf("STACK IS EMPTY\n");
            break;
        case 4:
            top=display(top);
            break;
            case 5: exit(0);
        default:
            printf("INVALID CHOICE\n");
        }
    }
    while(option!=5);
    return 0;
}
struct stack *push(struct stack *top,int val)
{
 struct stack *ptr;
 ptr = (struct stack*)malloc(sizeof(struct stack));
 ptr->data=val;
 if(top==NULL)
 {
     ptr->next=NULL;
     top=ptr;
 }
 else
 {
     ptr->next=top;
     top=ptr;
 }
 return top;
}
struct stack *display(struct stack *top)
{
 struct stack *ptr;
 ptr=top;
    if(top==NULL)
        printf("\n STACK IS EMPTY\n");
    else
        {
            printf("Elements are :");
            while(ptr!=NULL)
            {
                printf("%d\t",ptr->data);
                ptr=ptr->next;
            }
            printf("\n");
        }
            return top;
}
struct stack *pop(struct stack *top)
{
 struct stack *ptr;
 ptr=top;
    if(top==NULL)
        printf("\nSTACK UNDERFLOW\n");
    else
    {
        top=top->next;
        printf("THE value being deleted is :%d\n",ptr->data);
        free(ptr);
    }
    return top;
}
int peek(struct stack *top)
{
    if(top==NULL)
        return -1;
    else
        return top->data;
}