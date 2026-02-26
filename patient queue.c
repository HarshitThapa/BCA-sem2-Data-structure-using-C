#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100


struct Patient {
    int id;
    char name[50];
    int age;
};


struct Queue {
    struct Patient data[MAX];
    int front;
    int rear;
};

void initQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct Queue *q) {
    return (q->front == -1 || q->front > q->rear);
}

int isFull(struct Queue *q) {
    return (q->rear == MAX - 1);
}

void addPatient(struct Queue *q) {
    if (isFull(q)) {
        printf("\nQueue is full! Cannot add more patients.\n");
        return;
    }

    struct Patient p;

    printf("\nEnter Patient ID: ");
    scanf("%d", &p.id);

    printf("Enter Patient Name: ");
    scanf(" %[^\n]", p.name);

    printf("Enter Patient Age: ");
    scanf("%d", &p.age);

    if (q->front == -1)
        q->front = 0;

    q->rear++;
    q->data[q->rear] = p;

    printf("Patient added successfully!\n");
}

void viewNext(struct Queue *q) {
    if (isEmpty(q)) {
        printf("\nNo patients in queue.\n");
        return;
    }

    struct Patient p = q->data[q->front];

    printf("\nNext Patient:\n");
    printf("ID: %d\n", p.id);
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
}

void servePatient(struct Queue *q) {
    if (isEmpty(q)) {
        printf("\nNo patients to serve.\n");
        return;
    }

    struct Patient p = q->data[q->front];

    printf("\nServing Patient:\n");
    printf("ID: %d\n", p.id);
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);

    q->front++;

    if (q->front > q->rear) {
        q->front = -1;
        q->rear = -1;
    }
}

void displayPatients(struct Queue *q) {
    if (isEmpty(q)) {
        printf("\nNo patients waiting.\n");
        return;
    }

    printf("\nWaiting Patients:\n");

    for (int i = q->front; i <= q->rear; i++) {
        printf("\nID: %d\n", q->data[i].id);
        printf("Name: %s\n", q->data[i].name);
        printf("Age: %d\n", q->data[i].age);
    }
}

int main() {
    struct Queue q;
    int choice;

    initQueue(&q);

    while (1) {
        printf("\n===== Clinic Appointment System (FCFS) =====\n");
        printf("1. Add Patient\n");
        printf("2. View Next Patient\n");
        printf("3. Serve Patient\n");
        printf("4. Display All Patients\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPatient(&q);
                break;
            case 2:
                viewNext(&q);
                break;
            case 3:
                servePatient(&q);
                break;
            case 4:
                displayPatients(&q);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
