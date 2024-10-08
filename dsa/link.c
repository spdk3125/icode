#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* next;
};
struct node* head;
void insert();
void print();
int main() {
    head = NULL;
    printf("n = ");
    int n,i,x;
    scanf("%d",&n);
    for(i = 0; i < n; i++) {
        printf("Data = ");
        scanf("%d",&x);
        insert(x);
        print();
    }
    

}

void insert(int x) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    // temp->next = NULL;
    // if(head != NULL) temp->next = head;
    temp->next = head;
    head = temp;
}

void print() {
    struct node* temp = head;
    printf("List = ");
    while(temp != NULL) {
        printf("%d->",temp->data);
        temp= temp->next;

    }
    printf("NULL \n");
}

