#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;
const int N = 200005, INF = 1e9;
int n = 0, k = 0;
int to[N * 4], next[N * 4], w[N * 4], head[N * 4], edge = 0;
int dis[N * 4], inq[N * 4], cnt[N * 4];
queue<int> q;
inline void addEdge(int u, int v, int argw) {
  w[edge] = argw, to[edge] = v, next[edge] = head[u], head[u] = edge++;
}
inline void spfa(int s) {
  for (int i = 0; i <= n; ++i)
    dis[i] = -INF;
  q.push(s);
  dis[s] = 0;
  inq[s] = 1;
  ++cnt[s];
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    if (cnt[x] == n + 1) {
      printf("-1\n");
      exit(0);
    }
    inq[x] = 0;
    for (int e = head[x]; ~e; e = next[e]) {
      int v = to[e], ww = w[e];
      if (dis[x] + ww > dis[v]) {
        dis[v] = dis[x] + ww;
        if (!inq[v]) {
          inq[v] = 1;
          ++cnt[v];
          q.push(v);
        }
      }
    }
  }
}
int main(void) {
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
<<<<<<< HEAD
  memset(head, -1, sizeof(head));
  scanf("%d %d", &n, &k);
  while (k--) {
    int x = 0, a = 0, b = 0;
    scanf("%d %d %d", &x, &a, &b);
    switch (x) {
    case 1: {
      addEdge(a, b, 0);
      addEdge(b, a, 0);
      break;
    }
    case 2: {
      if (a == b) {
        printf("-1\n");
        exit(0);
      }
      addEdge(a, b, 1);
      break;
    }
    case 3: {
      addEdge(b, a, 0);
      break;
    }
    case 4: {
      if (a == b) {
        printf("-1\n");
        exit(0);
      }
      addEdge(b, a, 1);
      break;
    }
    case 5: {
      addEdge(a, b, 0);
      break;
    }
    }
  }
  for (int i = n; i >= 1; --i)
    addEdge(0, i, 1);
  spfa(0);
  long long ans = 0;
  for (int i = 1; i <= n; ++i)
    ans += dis[i];
  printf("%lld\n", ans);
=======
  p[0] = 1;
  cin >> (a + 1) >> (b + 1);
  int n = strlen(a + 1), m = strlen(b + 1);
  for (int i = 1; i <= m; i++)
    h = h * 131 + b[i] - 'A' + 1;
  // cout << h << endl;
  for (int i = 1; i <= n; i++) {
    f[i] = f[i - 1] * 131 + a[i] - 'A' + 1;
    p[i] = p[i - 1] * 131;
  }
  int ans = 0;
  for (int i = m; i <= n; i++)
    if (f[i] - f[i - m] * p[m] == h)
      ++ans;
  cout << ans;
>>>>>>> 3877bd7880c6ed0997d87175835e2269005a3cfa
  return 0;
}