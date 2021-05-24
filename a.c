#include <stdio.h>

int main() {
  const int a = 1;
  int *cur = (int *)&a;
  *cur = 2;
  printf("%d %p\n%d %p", a, &a, *cur, cur);
  return 0;
}