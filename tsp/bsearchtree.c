#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Employee {
    int id;
    char name[50];
    struct Employee* left;
    struct Employee* right;
} Employee;

Employee* createEmployee(int id, const char* name) {
    Employee* emp = (Employee*)malloc(sizeof(Employee));
    emp->id = id;
    strcpy(emp->name, name);
    emp->left = NULL;
    emp->right = NULL;
    return emp;
}

Employee* insertEmployee(Employee* root, int id, const char* name) {
    if (root == NULL) {
        return createEmployee(id, name);
    }
    if (id < root->id) {
        root->left = insertEmployee(root->left, id, name);
    } else if (id > root->id) {
        root->right = insertEmployee(root->right, id, name);
    } else {
        printf("Employee with ID %d already exists.\n", id);
    }
    return root;
}


void inOrderTraversal(Employee* root) {
    if (root) {
        inOrderTraversal(root->left);
        printf("ID: %d, Name: %s\n", root->id, root->name);
        inOrderTraversal(root->right);
    }
}

int main() {
    Employee* directory = NULL;
    int id;
    char name[50];
    char choice;

    do {
        printf("Enter employee ID: ");
        scanf("%d", &id);
        printf("Enter employee name: ");
        scanf("%s", name);

        directory = insertEmployee(directory, id, name);

        printf("Add another employee? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("\nEmployee Directory (Sorted by ID):\n");
    inOrderTraversal(directory);



    return 0;
}
