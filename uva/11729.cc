#include <bits/stdc++.h>
using namespace std;

int n, ans;
int minq;
int x;
struct Job {
  int b, j;
  bool operator<(const Job &x) const { return j > x.j; }
} q[1005];

int main() {
  int k = 1;
  // freopen("data.in","r",stdin);
  while (scanf("%d", &n) == 1 && n) {
    minq = 0, x = 0;
    // memset(sum,0,sizeof(sum));
    for (int i = 1; i <= n; i++) {
      scanf("%d%d", &q[i].b, &q[i].j);
    }
    sort(q + 1, q + 1 + n);
    for (int i = 1; i <= n; i++) {
      x += q[i].b;
      minq = max(minq, x + q[i].j);
    }
    printf("Case %d: %d\n", k++, minq);
  }
  return 0;
}
