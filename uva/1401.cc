#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 4e5 + 10;
int trie[maxn][26], tot;
int cnt[maxn], n;
char str[maxn], ch[110];
int dp[maxn];
constexpr int mod = 20071027;

void insert(char *str) {
  int len = strlen(str), p = 1;
  for (int i = 0; i < len; i++) {
    int ch = str[i] - 'a';
    if (trie[p][ch] == 0)
      trie[p][ch] = ++tot;
    p = trie[p][ch];
  }
  cnt[p] = 1;
}

int main() {
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int kse = 1;
  while (cin >> str) {
    memset(trie, 0, sizeof(trie));
    memset(cnt, 0, sizeof(cnt));
    memset(dp, 0, sizeof(dp));
    tot = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> ch;
      insert(ch);
    }
    int L = strlen(str);
    dp[L]=1;
    for (int i = L - 1; i >= 0; i--) {
      int x = 0;
      for (int j = i; j < L; j++) {
        int ch = str[j] - 'a';
        if (trie[x][ch] == 0)
          break;
        x = trie[x][ch];
        if (cnt[x])
          dp[i] = (dp[i] + dp[j + 1] + mod) % mod;
      }
    }
    cout << "Case " << kse++ << ": " << dp[0] << '\n';
  }
  return 0;
}