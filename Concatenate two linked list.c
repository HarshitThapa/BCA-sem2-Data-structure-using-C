#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createList(int n)
{
    struct node *head = NULL, *temp, *newnode;
    int i;

    for(i = 1; i <= n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter value: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if(head == NULL)
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

struct node* concatenate(struct node *head1, struct node *head2)
{
    struct node *temp;

    if(head1 == NULL)
        return head2;

    temp = head1;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = head2;

    return head1;
}

void display(struct node *head)
{
    struct node *temp = head;

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    struct node *head1, *head2, *head3;
    int n1, n2;

    printf("Enter number of elements in first list: ");
    scanf("%d", &n1);

    printf("Create first linked list\n");
    head1 = createList(n1);

    printf("Enter number of elements in second list: ");
    scanf("%d", &n2);

    printf("Create second linked list\n");
    head2 = createList(n2);

    head3 = concatenate(head1, head2);

    printf("Concatenated Linked List:\n");
    display(head3);

    return 0;
}
