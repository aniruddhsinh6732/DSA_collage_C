#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node* prev;
    int data;
    struct node* next;
};

struct node* CreateList(struct node* head);
struct node* AddAtEmpty(struct node* head,int data);
struct node* AddAtFront(struct node* head,int data);
struct node* AddAtLast(struct node* head,int data);
struct node* DelAtLast(struct node* head);
struct node* DelBefPos(struct node* head);

int main()
{
    struct node* head = malloc(sizeof(struct node));
    
    return 0;
}

struct node* CreateList(struct node* head){
  int n,data,i;
  printf("Enter The Number Of Nodes : ");
  scanf("%d",&n);

  if(n == 0){
    return head;
  }else{
    printf("Enter The Element For The Node1 : ");
    scanf("%d",&data);
    head = AddAtLast(head,data);
    for(i=1;i<n;i++){
      printf("Enter The Element For The Node %d : ",i+1);
      scanf("%d",&data);
      head = AddAtLast(head,data);
    }
  }
  return head;
}

struct node* AddAtEmpty(struct node* head,int data){
    head->prev = NULL;
    head->next = NULL;
    head->data = data;
    return head;
}

struct node* AddAtFront(struct node* head,int data){
    struct node* temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->next = head;
    temp->data = data;
    head = temp;
    return head;
}

struct node* AddAtLast(struct node* head,int data){
    struct node* newn = malloc(sizeof(struct node));
    struct node* temp;
    temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    newn->prev = temp;
    newn->data = data;
    newn->next = NULL;
    temp->next = newn;
    return head;
}

struct node* DelAtLast(struct node* head){
    struct node* temp;
    temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
    temp = NULL;
    return head;
}

struct node* DelBefPos(struct node* head){
    int pos;
    struct node* temp1,*temp2;
    temp1 = head;
    printf("Enter Position Before You Want To Delete : ");
    scanf("%d",&pos);
    while(pos > 2){
        temp1 = temp1->next;
    }
    temp2 = temp1->prev;
    temp2->next = temp1->next;
    temp1->next->prev = temp2;
    free(temp1);
    temp1 = NULL;
    return head;
}