#include<stdio.h>
#include<stdlib.h>
#define QUEUESIZE 10
#define NEGINF -32768
typedef struct CircularQueue
{
    int items[QUEUESIZE];
    int front,rear,count;

}CQueue;
int isFull(CQueue q)
{
    return q.count==QUEUESIZE?1:0;
}
int isEmpty(CQueue q)
{
    return q.count==0?1:0;
}
int peekFront(CQueue q)
{
    if(isEmpty(q))
        return NEGINF;
        return q.items[q.front];
}
int peekRear(CQueue q)
{
    if(isEmpty(q))
        return NEGINF;
        return q.items[q.rear];
}
void queueinsert(CQueue *pq,int element)
{
    if(isFull(*pq))
    {
        printf("queue overflow!! can't insert");
        return;
    }
    if(pq->rear==QUEUESIZE-1)
        pq->rear=0;
        else
            pq->rear++;
            pq->items[pq->rear]=element;
        pq->count++;
        printf("ELEMENT INSERTED");
}
int queueRemove(CQueue *pq)
{
    int temp;
    if(isEmpty(*pq))
    {
        printf("underflow");
        return NEGINF;
    }
    temp=pq->items[pq->front];
    if(pq->front==QUEUESIZE-1)
        pq->front=0;
        else
            pq->front++;
        pq->count--;
        return temp;
}
void show(CQueue q)
{
    int i;
    if(isEmpty(q))
    {
        printf("nothing to show\n");
        return;
    }
    printf("Queu containns\n");
    if(q.front<=q.rear)
    {
        for(i=q.front;i<=q.rear;i++)
            printf("%d\t",q.items[i]);
    }
    else
    {
        for(i=q.front;i<QUEUESIZE;i++)
            printf("%d\t",q.items[i]);

        for(i=0;i<q.rear;i++)
            printf("%d\t",q.items[i]);
    }
}
void main()
{
    CQueue q;
    int choice,element;
    q.rear=-1;
    q.front=0;
    q.count=0;
    while(1)
    {
        printf("\n MAIN MENU\n");
        printf("1.insert\n2.remove\n3.peek front\n4.peek rear\n5.show\n6.exit\n");
        printf("enter your choice\n");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            printf("enter element to be inserted\n");
            scanf("%d",&element);
            queueinsert(&q,element);
            break;
        case 2:
            element=queueRemove(&q);
            if(element!=NEGINF)
                printf("ELEMENT = %d",element);
                break;
         case 3:
            element=peekFront(q);
            if(element==NEGINF)
                printf("NOTHING TO PEEK\n");
            else
            {
                printf("element peeked = %d\n",element);
            }
                break;
            case 4:
            element=peekRear(q);
            if(element==NEGINF)
                printf("NOTHING TO PEEK\n");
            else
            {
                printf("element peeked = %d\n",element);
            }
                break;
            case 5:
                show(q);
                break;
            case 6:
                exit(1);

        }
    }
}