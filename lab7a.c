
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* createList()
{
    struct node *head = NULL, *temp = NULL, *newnode;
    int n, i;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        if (head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

void display(struct node *head)
{
    struct node *temp = head;
    if (head == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void sortList(struct node *head)
{
    struct node *temp, *curr;
    int swap;
    if (head == NULL)
    {
        printf("Linked list empty\n");
        return;
    }
    for (temp = head; temp != NULL; temp = temp->next)
    {
        for (curr = temp->next; curr != NULL; curr = curr->next)
        {
            if (temp->data > curr->data)
            {
                swap = temp->data;
                temp->data = curr->data;
                curr->data = swap;
            }
        }
    }
}

void concat(struct node *head1, struct node *head2)
{
    struct node *temp = head1;
    if (head1 == NULL)
    {
        printf("List1 is empty\n");
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head2;
}

struct node* reverse(struct node *head)
{
    struct node *prev = NULL;
    struct node *curr = head;
    struct node *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}


int main()
{
    struct node *head1 = NULL, *head2 = NULL;
    int choice;
    do
    {
        printf("\n\n----- LINKED LIST MENU -----\n");
        printf("1. Create First Linked List\n");
        printf("2. Create Second Linked List\n");
        printf("3. Display Linked Lists\n");
        printf("4. Sort First Linked List\n");
        printf("5. Concatenate Two Linked Lists\n");
        printf("6. Reverse First Linked List\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                head1 = createList();
                printf("First list created successfully\n");
                break;
            case 2:
                head2 = createList();
                printf("Second list created successfully\n");
                break;
            case 3:
                printf("\nFirst Linked List:\n");
                display(head1);
                printf("\nSecond Linked List:\n");
                display(head2);
                break;
            case 4:
                sortList(head1);
                printf("First list sorted successfully\n");
                display(head1);
                break;
            case 5:
                concat(head1, head2);
                printf("Lists concatenated successfully\n");
                display(head1);
                head2 = NULL;
                break;
            case 6:
                head1 = reverse(head1);
                printf("First list reversed successfully\n");
                display(head1);
                break;
            case 7:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 7);

    return 0;
}
