#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Function prototypes
void insertAtBeginning(int data);
void insertAtEnd(int data);
void insertAtMiddle(int data, int pos);
void deleteAtBeginning();
void deleteAtEnd();
void deleteAtMiddle(int pos);
void display();

int main() {
    int choice, data, pos;

    do {
        printf("\nCircular Linked List Operations:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at middle\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete at middle\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtMiddle(data, pos);
                break;
            case 4:
                deleteAtBeginning();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deleteAtMiddle(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 8);

    return 0;
}

void insertAtBeginning(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL) {
        head = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = head;
        struct Node *last = head;
        while (last->next != head) {
            last = last->next;
        }
        last->next = newNode;
        head = newNode;
    }
}

void insertAtEnd(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL) {
        head = newNode;
        newNode->next = newNode;
    } else {
        struct Node *last = head;
        while (last->next != head) {
            last = last->next;
        }
        last->next = newNode;
        newNode->next = head;
    }
}

void insertAtMiddle(int data, int pos) {
    if (pos <= 0) {
        printf("Invalid position.\n");
        return;
    }

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (pos == 1) {
        insertAtBeginning(data);
        return;
    }

    struct Node *temp = head;
    int count = 1;
    while (count < pos - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    if (count != pos - 1) {
        printf("Invalid position.\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        struct Node *last = head;
        while (last->next != head) {
            last = last->next;
        }
        last->next = head->next;
        free(head);
        head = last->next;
    }
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
    } else {
        struct Node *temp = head;
        while (temp->next->next != head) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = head;
    }
}

void deleteAtMiddle(int pos) {
    if (pos <= 0) {
        printf("Invalid position.\n");
        return;
    }

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (pos == 1) {
        deleteAtBeginning();
        return;
    }

    struct Node *temp = head;
    int count = 1;
    while (count < pos - 1 && temp->next != head) {
        temp = temp->next;
        count++;
    }

    if (count != pos - 1) {
        printf("Invalid position.\n");
        return;
    }

    struct Node *to_delete = temp->next;
    temp->next = to_delete->next;
    free(to_delete);
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
