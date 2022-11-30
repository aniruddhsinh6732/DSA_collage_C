/* Write a program to implement SIMPLE QUEUE and CIRCULAR
QUEUE using arrays that performs following operations:
a. INSERT
b. DELETE
c. DISPLAY */
#include <stdio.h>
#include <stdlib.h>
#define MAX 6

int queue[MAX];
int front = -1;
int rear = -1;

void push(int data);
void pop();
void print();

int main() {
  int ch, data;
  while (1) {
    printf("1.insert\n2.delete\n3.display\n4.exit\n");
    printf("Enter your choice : ");
    scanf("%d", &ch);
    switch (ch) {
    case 1:
      printf("Enter a value : ");
      scanf("%d", &data);
      push(data);
      break;
    case 2:
      pop();
      break;
    case 3:
      print();
    case 4:
      exit(1);
    defualt:
      printf("invalid choice\n");
    }
  }
}

void push(int data) {
  if (rear == MAX - 1)
    printf("queue is overflow\n");
  else
    queue[rear] = data;
  rear++;
}

void pop() {
  if (front == -1 || front >= rear) {
    printf("queue is underflow\n");
  } else {
    front++;
  }
}

void print() {
  int i;
  if (rear == MAX - 1)
    printf("queue is overflow\n");
  else
    for (i = front; i < rear; i++) {
      printf("%d ", queue[i]);
    }
  printf("\n");
}