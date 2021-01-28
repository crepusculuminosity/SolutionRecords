#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;
int N, M;
char a[105][105];

void dfs(int x, int y) {
  a[x][y] = '.';
  for (int dx = -1; dx <= 1; dx++) {
    for (int dy = -1; dy <= 1; dy++) {
      int xx = x + dx, yy = y + dy;
      if (xx >= 1 && xx <= N && yy >= 1 && yy <= M && a[xx][yy] == 'W')
        dfs(xx, yy);
    }
  }
  return;
}

int main() {
  freopen("data.in", "r", stdin);

  int res = 0;
  scanf("%d%d", &N, &M);
  getchar();
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      a[i][j] = getchar();
    }
    getchar();
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      if (a[i][j] == 'W') {
        dfs(i, j);
        res++;
      }
    }
  }
  printf("%d\n", res);
  return 0;
}