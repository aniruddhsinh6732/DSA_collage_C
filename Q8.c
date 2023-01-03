#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* AddToEmpty(struct node* head,int data);
struct node* AddAtBeg(struct node* head,int data);
struct node* AddAtLast(struct node* head,int data);
struct node* DelFirst(struct node* head);
struct node* DelAftPos(struct node* head,int pos);

int main()
{
    

    return 0;
}

struct node* AddToEmpty(struct node* head,int data){
    struct node* temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    head = temp;
    return head;
}

struct node* AddAtBeg(struct node* head,int data){
    struct node* temp = malloc(sizeof(struct node));
    struct node* plast;
    plast = head;
    plast = plast->next;
    while(plast->next != head){
        plast = plast->next;
    }
    plast->next = temp;
    temp->data = data;
    temp->next = head;
    head = temp;
    return head;
}

struct node* AddAtLast(struct node* head,int data){
    struct node* temp = malloc(sizeof(struct node));
    struct node* plast;
    plast = head;
    plast = plast->next;
    while(plast->next != head){
        plast = plast->next;
    }
    plast->next = temp;
    temp->data = data;
    temp->next = head;
    return head;
}

struct node* AddBefPos(struct node* head,int data,int pos){
    struct node* newp = NULL;
    struct node* temp1,*temp2;
    int npos = pos;
    temp1 = head;
    temp2 = NULL;
    newp = AddToEmpty(head,data);
    while(npos > 2){
        temp1 = temp1->next;
        npos--;
    }
    if(pos == 1){
        head = AddAtBeg(head,data);
    }else{
        temp2 = temp1->next;
        newp->next = temp2;
        temp1->next = newp;
    }
    return head;
}

struct node* DelFirst(struct node* head){
    struct node* temp,*plast;
    temp = head;
    plast = head->next;
    while(plast->next != head){
        plast = plast->next;
    }
    head = head->next;
    plast->next = head;
    free(temp);
    temp = NULL;
    return head;
}

struct node* DelAftPos(struct node* head,int pos){
    struct node* temp1,*temp2;
    temp1 = head;
    temp2 = NULL;
    while(pos != 1){
        temp1 = temp1->next;
    }   
    temp2 = temp1->next;
    if(temp2 == head){
        head = DelFirst(head);
    }else{
        temp1->next = temp2->next;
        free(temp2);
        temp2 = NULL;
    }
    return head;
}