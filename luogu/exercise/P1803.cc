#include <bits/stdc++.h>
using namespace std;

struct interval {
  int left;
  int right;
} x[1000500];

bool cmp(interval a, interval b) { return a.right < b.right; }
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &x[i].left, &x[i].right);
  }
  sort(x + 1, x + n + 1, cmp);
  int now = x[1].right, sum = 1;
  for (int i = 2; i <= n; i++) {
    if (now <= x[i].left) {
      now = x[i].right;
      sum++;
    }
  }
  printf("%d\n", sum);
  return 0;
}