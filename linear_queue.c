#include<stdio.h>
#include<stdlib.h>
#define MAX 3

int rear = -1;
int front = -1;
int queue[MAX] ;

void enqueue(int ele)
{
    if (rear == MAX-1)
        {
            printf("queue overflow");
            return ;
        }
    else if (front == -1)
    {
        front = 0;
    }

    rear = rear+1;
    queue[rear]= ele;
}
 void dequeue()
 {

    if (front == -1 || front >rear )
    {
        printf("Queue underflow");
        return ;
    }
    else if (front == rear)
    {
        printf("deleated element : %d" , queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("deleated element : %d" , queue[front]);
        front = front+1;
    }
 }

 void display()
 {
     for (int i = front ; i<= rear ; i++)
        printf("%d ",queue[i]);
 }

 int main(){
 int choice,element ;
    while (1)
    {
        printf("\n===MENU===");
        printf("\n1.ENQUEUE");
        printf("\n2.DEQUEUE");
        printf("\n3.PRINT");
        printf("\n4.EXIT");
        printf("\nENTER YOUR CHOICE :");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
                printf("Enter the element to be pushed :");
                scanf("%d",&element);
                enqueue(element);
            break;

            case 2 : dequeue();
            break;

            case 3 :display();
            break;

            case 4 : exit(0);

            default : printf("Invalid input");
        }
    }
    return 0;
}
