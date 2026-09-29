#include<stdio.h>
#include<stdlib.h>
#define MAX 9
int stack[MAX];
int top = -1;
void push(int data);
int pop();
void print();

int main()
{
    int choice;
    while(1)
    {
        printf("\n1.Push\n2.Pop\n3.Print\n4.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                int data;
                printf("Enter data to push: ");
                scanf("%d",&data);
                push(data);
                break;
            case 2:
                int value = pop();
                printf("Popped value: %d",value);
                break;
            case 3:
                print();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice");
        }
    }
}


void push(int data)
{
    if (top == MAX-1)
    {
        printf("Stack Full");
    }
    else
    {
        top++;
        stack[top] = data ;
    }
}

int pop()
{
    int value;
    if (top == -1)
    {
        printf("Stack is empty");
    }
    else
    {
        value = stack[top];
        top--;
        return value;
    }
}

void print()
{
    int i;
    for (i=top;i>=0;i--)
    {
        printf("%d ",stack[i]);
    }
}