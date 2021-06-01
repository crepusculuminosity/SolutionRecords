#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
constexpr int maxn = 1010;
int a[maxn];
int n;
struct node {
  int x, y;
  bool f;
};
unordered_map<int, node> mp;
#define mkp make_pair
int main() {

  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  while (cin >> n) {
    int ans = -0x7fffffff;
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1; i < n; i++) {
      for (int j = i + 1; j <= n; j++)
        mp[i + j].f = 1, mp[i + j].x = i, mp[i + j].y = j;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j < i; j++)
    }
  }
}