#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insertBeginning(struct Node **head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); 

    if (newNode == NULL) 
    {
        printf("Memory allocation failed!\n"); 
        return;
    }

    newNode->data = value;
    newNode->next = *head; 
    *head = newNode; 

    printf("%d inserted at the beginning.\n", value);
}


void insertEnd(struct Node **head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); 
    struct Node *temp;

    if (newNode == NULL) 
    {
        printf("Memory allocation failed!\n"); 
        return; 
    }

    newNode->data = value;
    newNode->next = NULL; 

    if (*head == NULL) 
    {
        *head = newNode; 
    }
    else
    {
        temp = *head; 

        while (temp->next != NULL)
        {
            temp = temp->next; 
        }

        temp->next = newNode; 
    }

    printf("%d inserted at the end.\n", value); 
}


void insertPosition(struct Node **head, int value, int position)
{
    struct Node *newNode; 
    struct Node *temp; 
    int i; 

    if (position < 1) 
    {
        printf("Invalid position!\n"); 
        return; // Exit the function
    }

    if (position == 1) 
    {
        insertBeginning(head, value); 
        return; 
    }

    temp = *head; 

    for (i = 1; i < position - 1 && temp != NULL; i++) 
    {
        temp = temp->next; 
    }

    if (temp == NULL)
    {
        printf("Invalid position!\n"); 
        return; 
    }

    newNode = (struct Node *)malloc(sizeof(struct Node)); 

    if (newNode == NULL) 
    {
        printf("Memory allocation failed!\n"); 
        return; 
    }

    newNode->data = value; 
    newNode->next = temp->next; 
    temp->next = newNode; 

    printf("%d inserted at position %d.\n", value, position); 
}


void deleteBeginning(struct Node **head)
{
    struct Node *temp; 

    if (*head == NULL) 
    {
        printf("Linked list is empty. Deletion not possible.\n"); 
        return; 
    }

    temp = *head; 
    *head = (*head)->next; 

    printf("%d deleted from the beginning.\n", temp->data); 
    free(temp); 
}

void deleteEnd(struct Node **head)
{
    struct Node *temp; 
    struct Node *prev = NULL; 

    if (*head == NULL)
    {
        printf("Linked list is empty. Deletion not possible.\n"); 
        return; 
    }

    temp = *head; 

    if (temp->next == NULL) 
    {
        *head = NULL; 
    }
    else
    {
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next; 
        }

        prev->next = NULL; 
    }

    printf("%d deleted from the end.\n", temp->data); 
    free(temp); 
}


void deletePosition(struct Node **head, int position)
{
    struct Node *temp; 
    struct Node *prev = NULL; 
    int i;

    if (*head == NULL) 
    {
        printf("Linked list is empty. Deletion not possible.\n"); 
        return; 
    }

    if (position < 1)
    {
        printf("Invalid position!\n"); 
        return;
    }

    if (position == 1) 
    {
        deleteBeginning(head); 
        return; 
    }

    temp = *head; 

    for (i = 1; i < position && temp != NULL; i++) 
    {
        prev = temp; 
        temp = temp->next;
    }

    if (temp == NULL) 
    {
        printf("Invalid position!\n"); 
        return; 
    }

    prev->next = temp->next; 

    printf("%d deleted from position %d.\n", temp->data, position); 
    free(temp); 
}


void display(struct Node *head)
{
    struct Node *temp = head; 

    if (head == NULL) 
    {
        printf("Linked list is empty.\n");
        return; 
    }

    printf("Linked List: ");
    while (temp != NULL) 
    {
        printf("%d -> ", temp->data); 
        temp = temp->next; 
    }

    printf("NULL\n"); 
}


int main()
{
    struct Node *head = NULL;
    int choice, value, position;

    do
    {
        printf("\n----- SINGLY LINKED LIST -----\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Specified Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Specified Position\n");
        printf("7. Traverse / Display\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the value: ");
                scanf("%d", &value);
                insertBeginning(&head, value);
                break;

            case 2:
                printf("Enter the value: ");
                scanf("%d", &value);
                insertEnd(&head, value);
                break;

            case 3:
                printf("Enter the value: ");
                scanf("%d", &value);
                printf("Enter the position: ");
                scanf("%d", &position);
                insertPosition(&head, value, position);
                break;

            case 4:
                deleteBeginning(&head);
                break;

            case 5:
                deleteEnd(&head);
                break;

            case 6:
                printf("Enter the position: ");
                scanf("%d", &position);
                deletePosition(&head, position);
                break;

            case 7:
                display(head);
                break;

            case 8:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 9);

    freeList(&head);

    return 0;
}
