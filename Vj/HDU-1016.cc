#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 20;
int a[maxn], vis[maxn];
int n;

bool check(int x) {
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0)
      return 0;
  return 1;
}

void dfs(int cur) {
  if (cur == n && check(a[0] + a[n - 1])) {
    for (int i = 0; i < n - 1; i++)
      printf("%d ", a[i]);
    printf("%d", a[n - 1]);
    puts("");
  }

  for (int i = 2; i <= n; i++) {
    if (!vis[i] && check(i + a[cur - 1])) {
      a[cur] = i, vis[i] = 1;
      dfs(cur + 1);
      vis[i] = 0;
    }
  }
}

int main() {
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  // clock_t s, e;
  // s = clock();
  int kse = 1;
  while (~scanf("%d", &n)) {
    // if (kse >= 2)
    // puts("");
    memset(vis, 0, sizeof(vis));
    memset(a, 0, sizeof(a));
    a[0] = 1;
    printf("Case %d:\n", kse++);
    dfs(1);
    puts("");
  }
  // e = clock();
  // printf("%f\n", (double)(e - s) / CLOCKS_PER_SEC);
  return 0;
}