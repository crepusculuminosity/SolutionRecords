#include <bits/stdc++.h>
using namespace std;
int vis[30000];

int main() {
  string s;
  cin >> s;
  int ans = 0;
  for (int i = 0; i < s.size(); i++) {
    int k = 1;
    memset(vis, 0, sizeof(vis));
    for (int j = i + 1; j < s.size() && k <= 26; j++) {
      if (s[j] == s[i])
        break;
      if (vis[s[j]] == 0)
        vis[s[j]] = 1, ++ans, ++k;
    }
  }
  cout << ans;
  return 0;
}