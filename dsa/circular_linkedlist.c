#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
newNode->data = data;
newNode->next = NULL;
    return newNode;
}
Node* insertFirst(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
newNode->next = newNode;
        return newNode;
    } else {
newNode->next = head;
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        return newNode;
    }
}
Node* insertLast(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
newNode->next = newNode;
        return newNode;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
newNode->next = head;
        return head;
    }
}
Node* insertMiddle(Node* head, int data, int position) {
    Node* newNode = createNode(data);
    if (position == 0) {
        return insertFirst(head, data);
    } else {
        Node* temp = head;
        int count = 1;
        while (temp->next != head && count < position) {
            temp = temp->next;
            count++;
        }
        if (temp->next == head && count < position) {
            return insertLast(head, data);
        } else {
newNode->next = temp->next;
            temp->next = newNode;
            return head;
        }
    }
}
Node* deleteFirst(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == head) {
        free(head);
        return NULL;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = head->next;
        free(head);
        return temp->next;
    }
}
Node* deleteLast(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == head) {
        free(head);
        return NULL;
    } else {
        Node* temp = head;
        while (temp->next->next != head) {
            temp = temp->next;
        }
        Node* nodeToDelete = temp->next;
        temp->next = head;
        free(nodeToDelete);
        return head;
    }
}
Node* deleteMiddle(Node* head, int position) {
    if (position == 0) {
        return deleteFirst(head);
    } else {
        Node* temp = head;
        int count = 1;
        while (temp->next != head && count < position) {
            temp = temp->next;
            count++;
        }
        if (temp->next == head && count < position) {
            return deleteLast(head);
        } else {
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            free(nodeToDelete);
            return head;
        }
    }
}
void printList(Node* head) {
    Node* temp = head;
    do {
printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
printf("%d\n", temp->data); 
}
int findPosition(Node* head, int data) {
    int position = 1;
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            return position;
        }
        position++;
        temp = temp->next;
    }
    return -1;
}
int main() {
    Node* head = NULL;
    int n,i,data, choice, position;
printf("Enter the number of nodes : ");
scanf("%d", &n);
    for ( i = 0; i< n; i++) {
printf("Enter data for node %d: ", i+1);
scanf("%d", &data);
        head = insertLast(head, data);
     }
printList(head);
    while (1) {
printf("1. Insert at beginning\n");
printf("2. Insert at end\n");
printf("3. Insert at middle\n");
printf("4. Delete from beginning\n");
printf("5. Delete from end\n");
printf("6. Delete from middle\n");
printf("7. Find position\n");
printf("8. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
        switch (choice)  {
            case 1:
printf("Enter data: ");
scanf("%d", &data);
                head = insertFirst(head, data);
printList(head);
                break;
            case 2:
printf("Enter data: ");
scanf("%d", &data);
                head = insertLast(head, data);
printList(head);
                break;
            case 3:
printf("Enter data: ");
scanf("%d", &data);
printf("Enter position: ");
scanf("%d", &position);
                head = insertMiddle(head, data, position);
printList(head);
                break;
            case 4:
                head = deleteFirst(head);
printList(head);
                break;
            case 5:
                head = deleteLast(head);
printList(head);
                break;
            case 6:
printf("Enter position: ");
scanf("%d", &position);
                head = deleteMiddle(head, position);
printList(head);
                break;
            case 7:
printf("Enter data to find position: ");
scanf("%d", &data);
                position = findPosition(head, data);
                if (position == -1) {
printf("Node not found\n");
                } else {
printf("Position: %d\n", position);
                }
                break;
            case 8:
printf("Exiting the program...\n");
        return 0;
    default:
printf("Invalid choice. Please choose a valid option.\n");
        }
    }
    }

