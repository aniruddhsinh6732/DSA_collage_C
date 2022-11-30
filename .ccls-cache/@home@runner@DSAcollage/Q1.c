#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int arr[MAX];

void insert();
void delete ();
void search();
void print();
int i = 0;

int main() {
  int ch;
  while (1) {
    printf("1.insert\n2.delete\n3.search\n4.print\n5.exit\n");
    printf("Enter your choice : ");
    scanf("%d", &ch);
    switch (ch) {
    case 1:
      insert();
      break;
    case 2:
      delete ();
      break;
    case 3:
      search();
      break;
    case 4:
      print();
      break;
    case 5:
      exit(1);

    default:
      printf("invalid choice\n");
    }
  }

  return 0;
}

void insert() {
  int val;
  if (i != MAX - 1) {
    printf("Enter value you want to insert into array : ");
    scanf("%d", &val);
    arr[i] = val;
    i++;
  } else {
    printf("array is full!!\n");
  }
}

void delete () {
  int pos, j;
  printf("enter position you want to delete : ");
  scanf("%d", &pos);
  if (pos >= 0 && pos < MAX) {
    while (i > pos) {
      for (j = pos; i > j; j++) {
        arr[j] = arr[j + 1];
      }
    }
    if (pos == i)
      i--;
  }
}

void search() {
  int val, j;
  printf("enter value you want to search in array : ");
  scanf("%d", &val);
  for (j = 0; j <= i; j++) {
    if (arr[j] == val) {
      printf("value is present in array.\n");
      printf("position of value is %d\n", j);
      return;
    }
  }
  printf("value is not present in array\n");
}

void print() {
  int j;
  for (j = 0; i > j; j++) {
    printf("%d ", arr[j]);
  }
  printf("\n");
}