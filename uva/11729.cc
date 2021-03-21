#include <bits/stdc++.h>
using namespace std;

int n;

struct Job {
  int b, j;
  bool operator<(const Job &x) const { return j > x.j; }
} job[10005];

int main() {
  int k = 1;
  while (scanf("%d", &n) == 1 && n) {
    int ans = 0, x = 0;
    for (int i = 1; i <= n; i++)
      scanf("%d%d", &job[i].b, &job[i].j);
    sort(job + 1, job + 1 + n);
    for (int i = 1; i <= n; i++) {
      x += job[i].b;
      ans = max(ans, x + job[i].j);
    }
    printf("Case %d: %d\n", k++, ans);
  }
  return 0;
}