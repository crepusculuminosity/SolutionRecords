#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
int cnt;
const int maxn = 1e4 + 10;
int num[maxn], prime[maxn], vis[maxn];

inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9')
    ch = getchar();
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + ch - 48, ch = getchar();
  return x;
}

bool check(int x, int y) {
  int res = 0, u, v;
  while (x) {
    u = x % 10, v = y % 10;
    x /= 10, y /= 10;
    if (u != v)
      ++res;
  }
  return res == 1;
}

void init() {
  for (int i = 2; i < maxn; i++) {
    if (num[i] == 0 && i >= 1000) {
      prime[++cnt] = i;
      // dp[i] = dp[i - 1] + 1;
    }
    for (int j = i + i; j < maxn; j += i) {
      num[j] = 1;
    }
  }
}
struct node {
  int x, s;
};

int bfs(int a, int b) {
  memset(vis, 0, sizeof(vis));
  queue<node> q;
  q.push(node{a, 0});
  vis[a] = 1;
  while (!q.empty()) {
    node now = q.front();
    q.pop();
    if (now.x == b)
      return now.s;

    for (int i = 1; i <= cnt; i++) {
      if (check(prime[i], now.x) && !vis[prime[i]]) {
        q.push(node{prime[i], now.s + 1});
        vis[prime[i]] = 1;
      }
    }
  }
  return -1;
}

int main() {
  init();

  // freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
  cout << cnt << endl << endl;
  for (int i = 1; i <= cnt; i++)
    cout << prime[i] << ",";
  return 0;
}