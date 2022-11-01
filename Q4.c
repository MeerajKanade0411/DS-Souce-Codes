//wap to implement queue using arrays
#include<stdio.h>
#include<stdlib.h>
#define max 10
int queue[max];
int front=-1,rear=-1;
void enqueue(void);
int dequeue(void);
int peek(void);
void display(void);
int main()
{
    int option,val;
    do
    {
        printf("--MAIN MENU--\n");
        printf("1.enqueue\n");
        printf("2.dequeue\n");
        printf("3.peek\n");
        printf("4.display\n");
        printf("5.exit\n");
        printf("enter your option\n");
        scanf("%d",&option);
        switch(option)
        {
            case 1:enqueue();
                   break;
            case 2:val=dequeue();
            if(val!=-1)
                printf("the value deleted is : %d\n",val);
                   break;
            case 3:val=peek();
            if(val!=-1)
                printf("the first value in queue is : %d\n",val);
                   break;
            case 4: display();
                    break;
        }
    }
    while(option!=5);
    return 0;
}
void enqueue()
{
    int num;
    printf("enter the value to be inserted\n");
    scanf("%d",&num);
    if(rear==max-1)
    {
        printf("overflow\n");
    }
    else if(front==-1&&rear==-1)
        front=rear=0;
    else
        rear++;
        queue[rear]=num;
}
int dequeue()
{
    int val;
    if (front==-1 || front>rear)
    {
        printf("underflow\n");
        return -1;
    }
    else
    {
        val=queue[front];
        front++;
        if(front>rear)
            front=rear=-1;
        return val;
    }
}
int peek()
{
    if (front==-1 || front>rear)
    {
        printf("queue is empty\n");
        return -1;
    }
    else
    {
        return queue[front];
    }
}
void display()
{
    int i;
    printf("\n");
    if (front==-1 || front>rear)
    {
        printf("queue is empty\n");
    }
    else
    {
        for(i=front;i<=rear;i++)
            printf("%d\t",queue[i]);
    }
}
