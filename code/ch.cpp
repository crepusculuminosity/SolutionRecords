#include <iostream>
int bin[10000002];
int flag[10000002];
int max;
int find(int x) {
  while (bin[x] != x)
    x = bin[x];
  return x;
}
int merge(int x, int y) {
  int fy, fx;
  fy = find(y);
  fx = find(x);
  if (fy != fx) {
    if (flag[fx] >= flag[fy]) {
      bin[fy] = fx;
      flag[fx] += flag[fy];
      if (max < flag[fx])
        max = flag[fx];
    } else {
      bin[fx] = fy;
      flag[fy] += flag[fx];
      if (max < flag[fy])
        max = flag[fy];
    }
  }
  return 0;
}
int main() {
  freopen("data.in", "r", stdin);
  int i, x, y;
  int n;
  while (scanf("%d", &n) != EOF) {
    max = 1;
    for (i = 1; i <= 10000000; i++) {
      bin[i] = i;
      flag[i] = 1;
    }
    for (i = 0; i < n; i++) {
      scanf("%d %d", &x, &y);
      merge(x, y);
    }
    printf("%d\n", max);
  }
  return 0;
}