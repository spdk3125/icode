#include<stdio.h>
#include<stdlib.h>
struct tree {
    int element;
    struct tree* left;
    struct tree* right;
};
struct tree* insert(int x, struct tree* T) {
    if(T==NULL) {
        T = (struct tree*)malloc(sizeof(struct tree));
        if(T!=NULL) {
            T->element = x;
            T->left = NULL;
            T->right = NULL;
        }
    } else if(x < T->element)
        T->left = insert(x, T->left);
    else if(x > T->element)
        T->right = insert(x, T->right);
    return T;
}

struct tree* find(int x, struct tree* T) {
    if(T==NULL)
        return NULL;
    if(x < T->element)
        return find(x, T->left);
    else if(x > T->element)
        return find(x, T->right);
    else
        return T;
}
struct tree* findmin(struct tree* T) {
    if(T==NULL)
        return NULL;
    else if(T->left == NULL)
        return T;
    else
        return findmin(T->left);
}
struct tree* findmax(struct tree* T) {
    if(T==NULL)
        return NULL;
    else if(T->right == NULL)
        return T;
    else
        return findmax(T->right);
}
struct tree* deletenode(int x, struct tree* T) {
    if(T==NULL) {
        printf("Element not found\n");
        return T;
    } else if(x < T->element)
        T->left = deletenode(x, T->left);
    else if(x > T->element)
        T->right = deletenode(x, T->right);
    else if(T->left && T->right) {
        int temp = findmin(T->right)->element;
        T->element = temp;
        T->right = deletenode(temp, T->right);
    } else {
        struct tree* temp = T;
        if(T->left == NULL)
            T = T->right;
        else if(T->right == NULL)
            T = T->left;
        free(temp);
    }
    return T;
}
void printTree(struct tree* T) {
    if(T == NULL)
        return;
    printTree(T->left);
    printf("%d ", T->element);
    printTree(T->right);
}
void inorder(struct tree* T){
 if(T!=NULL){
  inorder(T->left );
  printf("%d ",T->element);
  inorder(T->right);
   }
}
void preorder(struct tree* T){
 if(T!=NULL){
  printf("%d ",T->element);
  preorder(T->left );
  preorder(T->right);
 }
}
void postorder(struct tree* T){
 if(T!=NULL){
  postorder(T->left );
  postorder(T->right);
  printf("%d ",T->element);
 }
}
int main() {
    struct tree* root = NULL;
    int choice, x;
    printf("1. Insert\n");
    printf("2. Find\n");
    printf("3. Find Min\n");
    printf("4. Find Max\n");
    printf("5. Delete\n");
    printf("6. Print Tree\n");
    printf("7. Print Tree (Inorder)\n");
    printf("8. Print Tree (Preorder)\n");
    printf("9. Print Tree (Postorder)\n");
    printf("10. Exit\n");
    while(1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &x);
                root = insert(x, root);
                break;
            case 2:
                printf("Enter element to find: ");
                scanf("%d", &x);
                if(find(x, root) != NULL)
                    printf("Element found\n");
                else
                    printf("Element not found\n");
                break;
            case 3:
                if(findmin(root) != NULL)
                    printf("Min element is %d\n", findmin(root)->element);
                else
                    printf("Tree is empty\n");
                break;
            case 4:
                if(findmax(root) != NULL)
                    printf("Max element is %d\n", findmax(root)->element);
                else
                    printf("Tree is empty\n");
                break;
            case 5:
                printf("Enter element to delete: ");
                scanf("%d", &x);
                root = deletenode(x, root);
                break;
            case 6:
                printTree(root);
                printf("\n");
                break;
            case 7:
                inorder(root);
                printf("\n");
                break;
            case 8:
                preorder(root);
                printf("\n");
                break;
            case 9:
                postorder(root);
                printf("\n");
                break;
            case 10:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;}
