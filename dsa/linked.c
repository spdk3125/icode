#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new element at the beginning of the singly linked list
void insertAtFirst(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a new element at the end of the singly linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to insert a new element at a specific position in the singly linked list
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position == 0) {
        insertAtFirst(head, data);
        return;
    }
    struct Node* temp = *head;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete the first node of the singly linked list
void deleteFromFirst(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
    *head = temp->next;
    free(temp);
}

// Function to delete the last node of the singly linked list
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Function to delete a node at a specific position in the singly linked list
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
    if (position == 0) {
        deleteFromFirst(head);
        return;
    }
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range\n");
        return;
    }
    struct Node* nextPtr = temp->next->next;
    free(temp->next);
    temp->next = nextPtr;
}

// Function to print the linked list
void print(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

bool search(struct Node* head, int x) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == x)
            return true;
        current = current->next;
    }
    return false;
}

int displayMenu() {
    int choice;
    printf("\nMenu:\n");
    printf("1. Insert at beginning\n");
    printf("2. Insert at end\n");
    printf("3. Insert at specific position\n");
    printf("4. Delete from beginning\n");
    printf("5. Delete from end\n");
    printf("6. Delete from specific position\n");
    printf("7. Print the linked list\n");
    printf("8. search linked list\n");
    printf("9. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    struct Node* head = NULL;

    // // Example usage:
    // insertAtFirst(&head, 10);
    // insertAtEnd(&head, 20);
    // insertAtEnd(&head, 5);
    // insertAtEnd(&head, 30);
    // insertAtPosition(&head, 15, 2);

    int choice;
    do {
        choice = displayMenu();
        switch (choice) {
            case 1:
                {
                    int data;
                    printf("Enter data to insert at the beginning: ");
                    scanf("%d", &data);
                    insertAtFirst(&head, data);
                }
                break;
            case 2:
                {
                    int data;
                    printf("Enter data to insert at the end: ");
                    scanf("%d", &data);
                    insertAtEnd(&head, data);
                }
                break;
            case 3:
                {
                    int data, position;
                    printf("Enter data and position to insert: ");
                    scanf("%d %d", &data, &position);
                    insertAtPosition(&head, data, position);
                }
                break;
            case 4:
                deleteFromFirst(&head);
                break;
            case 5:
                deleteFromEnd(&head);
                break;
            case 6:
                {
                    int position;
                    printf("Enter position to delete: ");
                    scanf("%d", &position);
                    deleteAtPosition(&head, position);
                }
                break;
            case 7:
                printf("Linked list:\n");
                print(head);
                break;
            case 8:{
                int element;
                printf("Enter element to search: ");
                scanf("%d", &element);
                search(head, element) ? printf("Yes\n") : printf("No\n");
                }
                break;
            case 9:
                printf("Exiting. Have a great day!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 9);

    // Free memory for the linked list (you can add this part)
    // ...

    return 0;
}

