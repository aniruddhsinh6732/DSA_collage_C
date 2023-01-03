#include <stdio.h>

void conquer(int arr[], int si, int mid, int ei) {
  int i, j, len;
  len = ei - si + 1;
  int merged[len];
  int idx1, idx2, x;
  idx1 = si;
  idx2 = mid + 1;
  x = 0;

  while (idx1 <= mid && idx2 <= ei) {
    if (arr[idx1] <= arr[idx2]) {
      merged[x++] = arr[idx1++];
    } else {
      merged[x++] = arr[idx2++];
    }
  }

  while (idx1 <= mid) {
    merged[x++] = arr[idx1++];
  }

  while (idx2 <= ei) {
    merged[x++] = arr[idx2++];
  }

  for (i = 0, j = si; i < len; i++, j++) {
    arr[j] = merged[i];
  }
}

void divide(int arr[], int si, int ei) {
  int mid;
  if (si >= ei) {
    return;
  }

  mid = (si + ei) / 2;

  divide(arr, si, mid);
  divide(arr, mid + 1, ei);
  conquer(arr, si, mid, ei);
}

int main() {
  int arr[] = {6, 3, 9, 5, 2, 8};
  int i;
  divide(arr, 0, 6);

  for (i = 0; i < 6; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}