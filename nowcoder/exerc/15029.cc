#include <algorithm>
#include <iostream>

using namespace std;

int map[1005][1005];
int main() {
  int n, m, k, x;
  cin >> n >> m >> k;
  getchar();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      x = getchar() - 48;
      map[i][j] = -map[i - 1][j - 1] + map[i - 1][j] + map[i][j - 1] + x;
    }
    getchar();
  }
  int cnt = 0;
  for (int i = k; i <= n; i++) {
    for (int j = k; j <= m; j++) {
      if (map[i][j] - map[i - k][j] - map[i][j - k] + map[i - k][j - k]) {
        cnt++;
      }
    }
  }
  cout << cnt << endl;
  getchar();
  getchar();
}