//#include <bits/stdc++.h>
// using namespace std;
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN = 1e5 + 10;
int dis[MAXN];
queue<int> q;

void bfs(int s, int y) {
  int x;
  while (!q.empty()) {
    /* code */
    q.pop();
  }
  memset(dis, -1, sizeof(dis));
  dis[s] = 0;
  q.push(s);
  while (!q.empty()) {
    /* code */
    x = q.front();
    q.pop();
    if (x == y) {
      printf("%d\n", dis[y]);
      return;
    }
    if (x + 1 <= MAXN && dis[x + 1] == -1) {
      dis[x + 1] = dis[x] + 1, q.push(x + 1);
    }
    if (x - 1 >= 0 && dis[x - 1] == -1) {
      dis[x - 1] = dis[x] + 1, q.push(x - 1);
    }
    if (x * 2 <= MAXN && dis[x * 2] == -1) {
      dis[x * 2] = dis[x] + 1, q.push(x * 2);
    }
  }
}

int main() {
  int t;
  scanf("%d", &t);
  int x, y;
  while (t--) {
    scanf("%d%d", &x, &y);
    bfs(x, y);
  }
  return 0;
}
