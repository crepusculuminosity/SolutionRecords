#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1034;
constexpr int len = 32;
char s[maxn];
int gh[len][len];
int cnt;
void solve(char *s, int &p, int r, int c, int w) {
  char ch = s[p++];
  if (ch == 'p') {
    solve(s, p, r, c + w / 2, w / 2);
    solve(s, p, r, c, w / 2);
    solve(s, p, r + w / 2, c, w / 2);
    solve(s, p, r + w / 2, c + w / 2, w / 2);
  }
  if (ch == 'f') {
    for (int i = r; i < r + w; i++) {
      for (int j = c; j < c + w; j++) {
        if (gh[i][j] == 0)
          gh[i][j] = 1, ++cnt;
      }
    }
  }
}

int main() {
  // freopen("data.in", "r", stdin);
  int _;
  scanf("%d", &_);
  while (_--) {
    memset(gh, 0, sizeof(gh));
    cnt = 0;
    for (int i = 0; i < 2; i++) {
      scanf("%s", s);
      int p = 0;
      solve(s, p, 0, 0, len);
    }
    printf("There are %d black pixels.\n", cnt);
  }
  return 0;
}