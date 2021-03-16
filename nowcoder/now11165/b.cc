#include <bits/stdc++.h>
using namespace std;
constexpr int M = 2010;
constexpr int L = 2010;
constexpr int mod = 1e9 + 7;
class Trie {
public:
  int ch[L][10], cnt;
  bool mk[L];
  Trie() { cnt = 1; }
  void insert(char *s) {
    int n_junior = strlen(s + 1), p = 1;
    for (int i = 1; i <= n_junior; i++) {
      int c = s[i] - '0';
      if (!ch[p][c])
        ch[p][c] = ++cnt;
      p = ch[p][c];
    }
    mk[p] = 1;
  }
};
int n, m, f[2][L][2], ans;
char w[M], s[L];
class Acam : public Trie {
public:
  int fa[L];
  void build() {
    for (int i = 0; i <= 9; i++)
      ch[0][i] = 1;
    queue<int> q;
    while (q.size())
      q.pop();
    q.push(1);
    while (q.size()) {
      int x = q.front();
      q.pop();
      mk[x] |= mk[fa[x]];
      for (int c = 0; c <= 9; c++)
        if (ch[x][c]) {
          fa[ch[x][c]] = ch[fa[x]][c];
          q.push(ch[x][c]);
        } else
          ch[x][c] = ch[fa[x]][c];
    }
  }
  void dp() {
    for (int i = 1; i <= w[1] - '0'; i++)
      if (!mk[ch[1][i]])
        (f[1][ch[1][i]][i == w[1] - '0'] += 1) %= mod;
    for (int i = 2; i <= m; i++) {
      memset(f[i & 1], 0, sizeof f[i & 1]);
      for (int j = 1; j <= 9; j++)
        if (!mk[ch[1][j]])
          (f[i & 1][ch[1][j]][0] += 1) %= mod;
      for (int j = 1; j <= cnt; j++) {
        if (mk[j])
          continue;
        if (f[(i - 1) & 1][j][0])
          for (int c = 0; c <= 9; c++)
            if (!mk[ch[j][c]])
              (f[i & 1][ch[j][c]][0] += f[(i - 1) & 1][j][0]) %= mod;
        if (f[(i - 1) & 1][j][1])
          for (int c = 0; c <= w[i] - '0'; c++)
            if (!mk[ch[j][c]])
              (f[i & 1][ch[j][c]][c == w[i] - '0'] += f[(i - 1) & 1][j][1]) %=
                  mod;
      }
    }
    for (int i = 1; i <= cnt; i++)
      if (!mk[i])
        (((ans += f[m & 1][i][0]) %= mod) += f[m & 1][i][1]) %= mod;
  }
} q;
int main() {
  // freopen("data.in","r",stdin);
  scanf("%s\n%d", w + 1, &n), m = strlen(w + 1);
  for (int i = 1; i <= n; i++)
    scanf("%s", s + 1), q.insert(s);
  q.build();
  q.dp();
  printf("%d", ans);
  return 0;
}