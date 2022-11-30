#include <stdio.h>
#include <stdlib.h>
// c. Insert a node such that linked list is in ascending order
struct node {
  int data;
  struct node *link;
};

void create_llist(struct node *head);
void add_to_last(struct node *head, int temp);
void print_list(struct node *head);
void count_node(struct node *head);
struct node *add_front(struct node *head);
void add_end(struct node *head);
struct node *del_node(struct node *head);
struct node *del_front(struct node *head);
int return_count(struct node *head);
struct node *sort_list(struct node *head);

int main() {
  struct node *head = malloc(sizeof(struct node));
  struct node *sptr;
  head->link = NULL;
  create_llist(head);
  head = add_front(head);
  add_end(head);
  head = del_front(head);
  sptr = head;
  print_list(head);
  head = del_node(head);
  sptr = head;
  print_list(head);
  head = del_node(head);
  print_list(head);
}

void add_to_last(struct node *head, int temp) {
  struct node *ptr = head;
  while (ptr->link != NULL) {
    ptr = ptr->link;
  }

  ptr->data = temp;
}

void print_list(struct node *head) {
  struct node *ptr = head;
  while (ptr != NULL) {
    printf("%d ", ptr->data);
    ptr = ptr->link;
  }
}

int return_count(struct node *head) {
  struct node *ptr = head;
  int count = 0;
  while (ptr != NULL) {
    count++;
    ptr = ptr->link;
  }
  return count;
}

void create_llist(struct node *head) {
  struct node *ptr1 = head;
  struct node *ptr2;
  int num, temp, i;

  printf("enter a number node you want : ");
  scanf("%d", &num);

  for (i = 1; i <= num - 1; i++) {
    ptr2 = malloc(sizeof(struct node));
    printf("enter a data for node %d :", i);
    scanf("%d", &temp);
    ptr1->data = temp;
    ptr1->link = ptr2;
    ptr2->link = NULL;
    ptr1 = ptr2;
  }

  printf("enter data for last node of your programme :");
  scanf("%d", &temp);
  add_to_last(head, temp);
}

void count_node(struct node *head) {
  struct node *ptr = head;
  int count = 0;
  while (ptr != NULL) {
    count++;
    ptr = ptr->link;
  }

  printf("\nnum of nodes : %d", count);
}

struct node *add_front(struct node *head) {
  struct node *ptr = malloc(sizeof(struct node));
  int data;
  if (head == NULL) {
    printf("linked list is empty\n");
  } else {
    printf("Enter data for new first element : ");
    scanf("%d", &data);
    ptr->data = data;
    ptr->link = NULL;
    ptr->link = head;
    head = ptr;
  }
  return head;
}

void add_end(struct node *head) {
  struct node *eptr = malloc(sizeof(struct node));
  struct node *ptr = malloc(sizeof(struct node));
  int data;
  eptr = head;
  printf("Enter data for new last element : ");
  scanf("%d", &data);
  ptr->data = data;
  ptr->link = NULL;
  while (eptr->link != NULL) {
    eptr = eptr->link;
  }
  eptr->link = ptr;
}

struct node *del_front(struct node *head) {
  struct node *ptr = malloc(sizeof(struct node));

  if (head == NULL) {
    printf("linked list is empty\n");
  } else {
    ptr = head;
    head = head->link;
    free(ptr);
    ptr = NULL;
  }
  return head;
}

struct node *del_node(struct node *head) {
  struct node *ptr1 = head;
  struct node *ptr2 = NULL;
  int x, i, pos, r_pos;
  printf("\nWhich type of deletion you want?\n1.delete node at particular "
         "node\n2.Delete a node before specified position\n3.Delete a node "
         "after specified position\n");
  scanf("%d", &x);

  switch (x) {
  case 1:
    printf("Enter position you want to delete : ");
    scanf("%d", &pos);
    r_pos = 0;
    break;
  case 2:
    printf("Enter position before you want to delete : ");
    scanf("%d", &pos);
    r_pos = -1;
    break;
  case 3:
    printf("Enter position after you want to delete :  ");
    scanf("%d", &pos);
    r_pos = 1;
    break;
  default:
    printf("your choice is invalid \n");
    pos = r_pos = 0;
    break;
  }

  pos = pos + r_pos;

  if (pos == 0) {
    printf("not possible\n");
  } else if (pos == 1) {
    head = del_front(head);
  } else {
    for (i = 1; i < pos; i++) {
      ptr2 = ptr1;
      ptr1 = ptr1->link;
    }
    ptr2->link = ptr1->link;
    free(ptr1);
    ptr1 = NULL;
  }
  return head;
}

struct node *sort_list(struct node *head) {
  struct node *ptr2;
  int temp, count, i;
  ptr2 = head;
  i = 0;
  count = return_count(head);
  while (i < count) {
    ptr2 = head;
    while (ptr2->link != NULL) {
      if (ptr2->data > ptr2->link->data) {
        temp = ptr2->data;
        ptr2->data = ptr2->link->data;
        ptr2->link->data = temp;
        break;
      } else {
        ptr2 = ptr2->link;
      }
    }
    i++;
  }
  return head;
}
