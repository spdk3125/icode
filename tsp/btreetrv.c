#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Employee structure
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
    } else {
        root->right = insertEmployee(root->right, id, name);
    }
    return root;
}


void inOrderTraversal(Employee* root) {
    if (root) {
        inOrderTraversal(root->left);
        printf("%s (ID: %d)\n", root->name, root->id);
        inOrderTraversal(root->right);
    }
}

int main() {
    Employee* ceo = NULL;
    int id;
    char name[50];
    char choice;

    do {
        printf("Enter employee ID: ");
        scanf("%d", &id);
        printf("Enter employee name: ");
        scanf("%s", name);

        ceo = insertEmployee(ceo, id, name);

        printf("Add another employee? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("\nEmployee Hierarchy (In-Order Traversal):\n");
    inOrderTraversal(ceo);

    

    return 0;
}
