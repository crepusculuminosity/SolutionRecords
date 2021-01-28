#include <bits/stdc++.h>
int main() {
  int a[5] = {1, 2, 3, 4, 5};
  memset(a, 0, sizeof(a));
  for (int i = 0; i < 5; i++)
    printf("%d ", a[i]);
  printf("\n");

  memset(a, -1, sizeof(a));
  for (int i = 0; i < 5; i++)
    printf("%d ", a[i]);
  printf("\n");

  memset(a, 0x5a5b5c4f, sizeof(a));
  for (int i = 0; i < 5; i++)
    printf("%d ", a[i]);
  printf("\n");

  memset(a, 0x7f, sizeof(a));
  for (int i = 0; i < 5; i++)
    printf("%d ", a[i]);
  printf("\n");

  memset(a, 0x3f, sizeof(a));
  for (int i = 0; i < 5; i++)
    printf("%d ", a[i]);
  printf("\n");
  return 0;
}