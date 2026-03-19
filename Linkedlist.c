#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

/* Insert at beginning */
void insert()
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter value: ");
    scanf("%d", &newnode->data);

    newnode->next = head;
    head = newnode;

    printf("Element inserted\n");
}

/* Delete from beginning */
void deleteNode()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;

    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

/* Display linked list */
void display()
{
    struct node *temp;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;

    printf("Linked List elements:\n");

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                insert();
                break;

            case 2:
                deleteNode();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
