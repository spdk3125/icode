#include <stdio.h>
#include <stdlib.h>
typedef struct tree {
    int element;
    struct tree* left;
    struct tree* right;
    int height;
}
 tree;
int max(int a, int b) {
    return (a > b) ? a : b;
}
int height(tree* T) {
    if (T == NULL) 
    return -1;
    return T->height;
}
tree* singleLeft(tree* k2) {
    tree* k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), height(k1->right)) + 1;
    return k1;
}
tree* singleRight(tree* k1) {
    tree* k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), height(k1->right)) + 1;
    return k2;
}
tree* doubleLeft(tree* k3) {
    k3->left = singleRight(k3->left);
    return singleLeft(k3);
}
tree* doubleRight(tree* k1) {
    k1->right = singleLeft(k1->right);
    return singleRight(k1);
}
tree* insert(int x, tree* T) {
    if (T == NULL) {
        T = (tree*)malloc(sizeof(tree));
        T->element = x;
        T->left = NULL;
        T->right = NULL;
        T->height = 0;
    } else if (x < T->element) {
        T->left = insert(x, T->left);
        if (height(T->left) - height(T->right) == 2) {
            if (x < T->left->element) {
                T = singleLeft(T);
            } else {
                T = doubleLeft(T);
            }
        }
    } else if (x > T->element) {
        T->right = insert(x, T->right);
        if (height(T->right) - height(T->left) == 2) {
            if (x > T->right->element) {
                T = singleRight(T);
            } else {
                T = doubleRight(T);
            }
        }
    }
    T->height = max(height(T->left), height(T->right)) + 1;
    return T;
}
tree* deleteNode(int x, tree* T) {
    if (T == NULL) return T;
    if (x < T->element) {
        T->left = deleteNode(x, T->left);
    } else if (x > T->element) {
        T->right = deleteNode(x, T->right);
    } else {
        if (T->left == NULL) {
            tree* temp = T->right;
            free(T);
            return temp;
        } else if (T->right == NULL) {
            tree* temp = T->left;
            free(T);
            return temp;
        }
        tree* temp = T->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        T->element = temp->element;
        T->right = deleteNode(temp->element, T->right);
    }
    if (T == NULL) return T;
    T->height = max(height(T->left), height(T->right)) + 1;
    if (height(T->left) - height(T->right) == 2) {
        if (height(T->left->left) - height(T->left->right) >= 0) {
            T = singleLeft(T);
        } else {
            T = doubleLeft(T);
        }
    } else if (height(T->right) - height(T->left) == 2) {
        if (height(T->right->right) - height(T->right->left) >= 0) {
            T = singleRight(T);
        } else {
            T = doubleRight(T);
        }
    }
    return T;
}
void printTree(tree* T) {
    if (T == NULL) return;
    printTree(T->left);
    printf("%d ", T->element);
    printTree(T->right);
}
void traverseTree(tree* T) {
    if (T == NULL) return;
    printf("Element: %d, Height: %d\n", T->element, T->height);
    traverseTree(T->left);
    traverseTree(T->right);
}
int main() {
    tree* T = NULL;
    int choice, element;
while (1) {
        printf("AVL Tree Menu\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Traverse Tree\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &element);
                T = insert(element, T);
                printTree(T);
                printf("\n");
                 break;
            case 2:
                printf("Enter element to delete: ");
                scanf("%d", &element);
                T = deleteNode(element, T);
                printTree(T);
                printf("\n");
                break;
           case 3:
                traverseTree(T);
                printf("\n");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
  return 0;
}
