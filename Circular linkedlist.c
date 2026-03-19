#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *last = NULL;

/* Insert node */
void insert()
{
    struct node *newnode, *temp;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter value: ");
    scanf("%d", &newnode->data);

    if(last == NULL)
    {
        last = newnode;
        last->next = last;
    }
    else
    {
        newnode->next = last->next;
        last->next = newnode;
        last = newnode;
    }

    printf("Element inserted\n");
}

/* Delete node */
void deleteNode()
{
    struct node *temp;

    if(last == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = last->next;

    if(last->next == last)
    {
        printf("Deleted element: %d\n", temp->data);
        free(temp);
        last = NULL;
    }
    else
    {
        printf("Deleted element: %d\n", temp->data);
        last->next = temp->next;
        free(temp);
    }
}

/* Display circular linked list */
void display()
{
    struct node *temp;

    if(last == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = last->next;

    printf("Elements in Circular Linked List:\n");

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    while(temp != last->next);

    printf("(Back to Start)\n");
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
