#include <stdio.h>
#include <string.h>
#define TABLE_SIZE 10

struct Employee {
    int empId;
    char empName[100];
};

struct Employee hashTable[TABLE_SIZE];

void initHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i].empId = -1; // -1 indicates an empty spot
        strcpy(hashTable[i].empName, "");
    }
}

int hashFunction(int empId) {
    return empId % TABLE_SIZE;
}

void insertEmployee(int empId, char empName[]) {
    int index = hashFunction(empId);
    int i = 0;
    while (hashTable[(index + i) % TABLE_SIZE].empId != -1) {
        i++;
        if (i == TABLE_SIZE) {
            printf("Hash table is full! Cannot insert.\n");
            return;
        }
    }
    index = (index + i) % TABLE_SIZE;
    hashTable[index].empId = empId;
    strcpy(hashTable[index].empName, empName);
    printf("Employee inserted at index %d\n", index);
}

void searchEmployee(int empId) {
    int index = hashFunction(empId);
    int i = 0;
    while (hashTable[(index + i) % TABLE_SIZE].empId != -1) {
        if (hashTable[(index + i) % TABLE_SIZE].empId == empId) {
            printf("Employee found at index %d: ID: %d, Name: %s\n", (index + i) % TABLE_SIZE, empId, hashTable[(index + i) % TABLE_SIZE].empName);
            return;
        }
        i++;
        if (i == TABLE_SIZE) {
            printf("Employee not found.\n");
            return;
        }
    }
    printf("Employee not found.\n");
}

void displayHashTable() {
    printf("\nHash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i].empId != -1) {
            printf("Index %d: ID: %d, Name: %s\n", i, hashTable[i].empId, hashTable[i].empName);
        } else {
            printf("Index %d: Empty\n", i);
        }
    }
}

int main() {
    initHashTable();
    int choice, empId;
    char empName[100];

    while (1) {
        printf("\n1. Insert Employee\n2. Search Employee\n3. Display Hash Table\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Employee ID: ");
                scanf("%d", &empId);
                printf("Enter Employee Name: ");
                scanf("%s", empName);
                insertEmployee(empId, empName);
                break;
            case 2:
                printf("Enter Employee ID to search: ");
                scanf("%d", &empId);
                searchEmployee(empId);
                break;
            case 3:
                displayHashTable();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}