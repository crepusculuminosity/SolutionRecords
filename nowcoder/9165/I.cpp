#include <bits/stdc++.h>
using namespace std;

int a[100005]; // 1为黑色
int n, m;
int sum[100005];
int find(int l, int r) {
  memset(sum, 0, sizeof(sum));
  int cnt = 0;
  for (int i = l; i <= r; i++) {
    sum[i] = sum[i - 1] + a[i];
    if (a[i] == 0)
      sum[i] = 0;
    cnt = max(cnt, sum[i]);
  }
  return cnt;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  while (m--) {
    int op, l, r;
    scanf("%d%d%d", &op, &l, &r);

    if (op == 0) {
      for (int i = l; i <= r; i++) {
        if (a[i] == 1)
          a[i] = 0;
      }
      // for(int i=0; i<n; i++) printf("%d ",a[i]); printf("\n");
    }

    if (op == 1) {
      for (int i = l; i <= r; i++) {
        if (a[i] == 0)
          a[i] = 1;
      }
      // for(int i=0; i<n; i++) printf("%d ",a[i]); printf("\n");
    }

    if (op == 2) {
      for (int i = l; i <= r; i++) {
        a[i] = 1 - a[i];
      }
      // for(int i=0; i<n; i++) printf("%d ",a[i]); printf("\n");
    }

    if (op == 3) {
      int cnt = 0;
      for (int i = l; i <= r; i++) {
        if (a[i])
          ++cnt;
      }
      printf("%d\n", cnt);
    }

    if (op == 4) {
      printf("%d\n", find(l, r));
    }
  }
  return 0;
}