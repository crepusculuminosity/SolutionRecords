#include <bits/stdc++.h>
using namespace std;

int a[1005], cnt;

int main() {
  int x, n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    if (a[x])
      continue;
    a[x] = 1;
    ++cnt;
  }
  printf("%d\n", cnt);
  for (int i = 1; i <= 1000; i++) {
    if (a[i])
      printf("%d ", i);
  }
  printf("\n");
  return 0;
}