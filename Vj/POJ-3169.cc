#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int N = 1e3 + 10, M = 1e4 + 10;
struct Node {
  int to, next, dis;
} edge[M << 1];
int head[N], tot;
int n, ml, md, d[N], v[N], cnt[N];
bool SPFA(int s);
int read();
void write(int x);
void add(int from, int to, int dis);
int main() {
  n = read(), ml = read(), md = read();
  for (int i = 1; i <= ml; i++) {
    int a = read(), b = read(), d = read();
    add(a, b, d);
  }
  for (int i = 1; i <= md; i++) {
    int a = read(), b = read(), d = read();
    add(b, a, -d);
  }
  for (int i = 1; i <= n - 1; i++)
    add(i + 1, i, 0);
  for (int i = 1; i <= n; i++)
    add(0, i, 0);
  if (SPFA(0))
    cout << -1 << endl;
  else if (!SPFA(1) && d[n] == 0x3f3f3f3f)
    cout << -2 << endl;
  else
    cout << d[n] << endl;
  return 0;
}
bool SPFA(int s) {
  memset(d, 0x3f, sizeof(d));
  memset(v, 0, sizeof(v));
  memset(cnt, 0, sizeof(cnt));
  queue<int> q;
  q.push(s);
  d[s] = 0, v[s] = 1;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    v[x] = 0;
    for (int i = head[x]; i; i = edge[i].next) {
      int y = edge[i].to;
      if (d[y] > d[x] + edge[i].dis) {
        d[y] = d[x] + edge[i].dis;
        cnt[y] = cnt[x] + 1;
        if (cnt[y] >= n + 1)
          return true;
        if (!v[y])
          q.push(y), v[y] = 1;
      }
    }
  }
  return false;
}
void add(int from, int to, int dis) {
  tot++;
  edge[tot].to = to;
  edge[tot].dis = dis;
  edge[tot].next = head[from];
  head[from] = tot;
}
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
void write(int x) {
  if (x < 0)
    putchar('-'), x = -x;
  if (x > 9)
    write(x / 10);
  putchar(x % 10 + '0');
}