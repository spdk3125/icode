#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* next;
};
struct node* head = NULL;
struct node* create(int x) {
    struct node* NN = (struct node*)malloc(sizeof(struct node));
    NN->data = x;
    NN->next = NULL;
    return NN;
}
void insertbeg(int x) {
    struct node* temp;
    struct node* NN = create(x);
if(head == NULL) {
        head = NN;
    } else {
        temp=head;
        NN->next = temp;
        head = NN;
    }
}
void insertmid(int x){
    int i,p;
    struct node* temp;
    struct node* NN=create(x);
printf(" Enter the position: ");
scanf("%d",&p);
if(head == NULL) {
        head = NN;
        NN->next=NULL;
    }
else  {
        temp=head;
i=1;
while(i<p-1&& temp->next!=NULL) {
            temp=temp->next;
i++;
        }
        NN->next=temp->next;
        temp->next=NN;
    } 
}
void insertlast(int x){
    struct node* temp;
    struct node* NN=create(x);
if(head == NULL) {
        head = NN;
    }
else{
        temp= head;
        while(temp->next!=NULL) {
            temp= temp->next;
        }
        temp->next=NN;
        NN->next=NULL;
    }
}
struct node* delbeg(struct node* head){
    struct node* temp=head;
    temp=head;
if(head == NULL) {
printf("1");
    }
    else {
        head=temp->next;
        temp->next=NULL;
        free(temp);
        return head;
    }
}
void dellast(struct node* head){
    struct node* temp,*prev;
if(head == NULL) {
        return;
    }
else{
        temp=head;
        while(temp->next!=NULL) {
prev=temp;
            temp=temp->next;
        }
prev->next=NULL;
        free(temp);
    }
}
void delmid(int p) {
if(head == NULL) 
    return;
    struct node* temp = head;
    int i = 1;
while(i< p-1 && temp->next != NULL) {
        temp = temp->next;
i++;
    }
    struct node* list = temp->next;
    temp->next = list->next;
    free(list);
}
void findpos(int p,struct node* head){
    struct node* temp;
    int item;
    p=1;
if(head == NULL) 
printf("The node is null ");
    else
      temp=head;
printf("Enter the data to find:");
scanf("%d",&item);
      while(temp->data!=item)  {
          temp=temp->next;
          p++;
      }
printf("The position is %d\n",p);
}
void display() {
printf("The elements are: ");
    struct node* temp = head;
while(temp != NULL) {
printf("%d -> ", temp->data);
        temp = temp->next;
    }
printf("NULL\n");
}
int main() {
    int choice,p,i,n;
printf("Enter number of nodes: ");
scanf("%d", &n);
for(i = 0; i< n; i++)  {
printf("Enter node %d: ", i+1);
        int x;
scanf("%d", &x);
insertlast(x);
     }
display();
while(1){
printf("1.Insert beginning\n");
printf("2.Insert middle\n");
printf("3.Insert last\n" );
printf("4.Delete beginning\n");
printf("5.Delete middle\n");
printf("6.Delete last\n");
printf("7.Find position \n");
printf("8.Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
        switch(choice)   {
            case 1:
               printf("Enter node to insert: ");
               int x;
               scanf("%d", &x);
               insertbeg(x);
               display();
                break;
          case 2:
               printf("Enter the data to insert: ");
               scanf("%d",&x);
               insertmid(x);
               display();
                break;
           case 3:
               printf("Enter the data to insert: ");
               scanf("%d",&x);
               insertlast(x);
              display();
                break;
            case 4:
                head=delbeg(head);
                display();
                break;
            case 5:
               printf("Enter position to delete: ");
              scanf("%d", &p);
              delmid(p);
              display();
               break;
           case 6:
              dellast(head);
               display ();
               break;
          case 7:
              findpos(p,head);
               break;
         case 8:
	exit(1);      	
        }
    }
    return 0;
}

