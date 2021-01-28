#include <bits/stdc++.h>
using namespace std;
int n;
const int MAXN = 25;
int a[MAXN][MAXN], b[MAXN][MAXN];

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    scanf("%d", &n);
    getchar();
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        a[i][j] = getchar() - '0';
      }
      getchar();
    }
  }
}