#include <stdio.h>
#include <stdlib.h>

// Define the structure for a singly circular linked list node
struct Node {
    int data;
    struct Node* next;
};

// Initialize the head of the circular linked list
struct Node* head = NULL;

// Function to insert a node at the beginning
void insertAtFirst(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL) {
        newNode->next = newNode; // Circular reference for the first node
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

// Function to insert a node at the end
void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL) {
        newNode->next = newNode; // Circular reference for the first node
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

// Function to insert a node after a specific position (middle)
void insertAfter(int data, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL) {
        printf("List is empty. Insertion not possible.\n");
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < position; ++i) {
        temp = temp->next;
        if (temp == head) {
            printf("Invalid position. Insertion not possible.\n");
            return;
        }
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to display the circular linked list
void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    int choice, data, position;

    do {
        printf("\nCircular Linked List Operations:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert after a specific position\n");
        printf("4. Display the list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtFirst(data);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position (1-based index): ");
                scanf("%d", &position);
                insertAfter(data, position);
                break;
            case 4:
                printf("Circular Linked List: ");
                displayList();
                break;
            case 5:
                printf("Exiting. Have a great day!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
