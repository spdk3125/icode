#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
} Contact;

typedef struct Node {
    Contact contact;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} ContactList;

// Function prototypes
void initializeList(ContactList* list);
void addContact(ContactList* list, Contact contact);
void removeContact(ContactList* list, char* name);
void displayContacts(ContactList* list);
void freeList(ContactList* list);

int main() {
    ContactList list;
    initializeList(&list);

    int choice;
    do {
        printf("\nContact Management System\n");
        printf("1. Add Contact\n");
        printf("2. Remove Contact\n");
        printf("3. Display Contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            Contact contact;
            printf("Enter name: ");
            scanf("%s", contact.name);
            printf("Enter phone number: ");
            scanf("%s", contact.phone);
            addContact(&list, contact);
        } else if (choice == 2) {
            char name[MAX_NAME_LENGTH];
            printf("Enter name of the contact to remove: ");
            scanf("%s", name);
            removeContact(&list, name);
        } else if (choice == 3) {
            displayContacts(&list);
        }
    } while (choice != 4);

    freeList(&list);
    return 0;
}

void initializeList(ContactList* list) {
    list->head = NULL;
}

void addContact(ContactList* list, Contact contact) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->contact = contact;
    newNode->next = list->head;
    list->head = newNode;
}

void removeContact(ContactList* list, char* name) {
    Node* current = list->head;
    Node* previous = NULL;

    while (current != NULL && strcmp(current->contact.name, name) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Contact not found.\n");
        return;
    }

    if (previous == NULL) {
        list->head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
    printf("Contact removed.\n");
}

void displayContacts(ContactList* list) {
    Node* current = list->head;
    if (current == NULL) {
        printf("No contacts to display.\n");
        return;
    }

    while (current != NULL) {
        printf("Name: %s, Phone: %s\n", current->contact.name, current->contact.phone);
        current = current->next;
    }
}

void freeList(ContactList* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
}
