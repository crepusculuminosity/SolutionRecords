#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
constexpr int maxn = 1e6 + 10;
char s[maxn];
ull ha[maxn], p[maxn];

int main() {
  // freopen("data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int q;
  cin >> (s + 1) >> q;
  int len = strlen(s + 1);
  p[0] = 1;
  for (int i = 1; i <= len; i++) {
    ha[i] = ha[i - 1] * 131 + (s[i] - 'a' + 1);
    p[i] = 131 * p[i - 1];
  }
  while (q--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (ha[b] - ha[a - 1] * p[b - a + 1] == ha[d] - ha[c - 1] * p[d - c + 1])
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}