#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int day, month, year;
    int tithi;
    struct Node* next;
};

// Create node
struct Node* createNode(int d, int m, int y, int t) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->day = d;
    newNode->month = m;
    newNode->year = y;
    newNode->tithi = t;
    newNode->next = NULL;

    return newNode;
}

// Insert at end
struct Node* insert(struct Node* head, struct Node* newNode) {
    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Simple conversion (basic logic)
int getTithi(int day) {
    return (day % 30) + 1;   // simple pattern
}

// Display list
void display(struct Node* head) {
    struct Node* temp = head;

    while (temp != NULL) {
        printf("Date: %02d-%02d-%04d  |  Tithi: %d\n",
               temp->day, temp->month, temp->year, temp->tithi);
        temp = temp->next;
    }
}

// Main function
int main() {
    struct Node* head = NULL;

    int month = 4, year = 2026;

    // Create list for 30 days
    for (int d = 1; d <= 30; d++) {
        int tithi = getTithi(d);

        struct Node* newNode = createNode(d, month, year, tithi);

        head = insert(head, newNode);
    }

    // Display
    printf("\nSimple Hindu Calendar (Linked List)\n\n");
    display(head);

    return 0;
}
