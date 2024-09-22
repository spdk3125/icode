#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a binary tree node
struct TreeNode {
    char name[100]; // Directory or file name
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(const char* name) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode != NULL) {
        strcpy(newNode->name, name);
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

// Function to insert a node into the binary tree
struct TreeNode* insertNode(struct TreeNode* root, const char* name) {
    if (root == NULL) {
        return createNode(name);
    }
    if (strcmp(name, root->name) < 0) {
        root->left = insertNode(root->left, name);
    } else if (strcmp(name, root->name) > 0) {
        root->right = insertNode(root->right, name);
    }
    return root;
}

// Function to perform in-order traversal of the binary tree
void inOrderTraversal(struct TreeNode* root, int depth) {
    if (root != NULL) {
        inOrderTraversal(root->left, depth + 1);

        // Print indentation based on depth
        for (int i = 0; i < depth; ++i) {
            printf("│   ");
        }
        printf("├── %s\n", root->name);

        inOrderTraversal(root->right, depth + 1);
    }
}

// Function to free the memory allocated for the binary tree
void freeTree(struct TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    struct TreeNode* root = NULL;
    char name[100];
    char choice;

    do {
        printf("Enter a directory or file name: ");
        scanf("%s", name);
        root = insertNode(root, name);

        printf("Want to add another directory or file? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("\nFile System Hierarchy:\n");
    inOrderTraversal(root, 0);

    freeTree(root); // Free allocated memory

    return 0;
}
