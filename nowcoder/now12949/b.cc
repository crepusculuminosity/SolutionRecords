#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e5 + 10;
int n;
vector<int> G[6];
void work() {
  bool f = 0;
  for (int i = 1; i <= 5; i++)
    f |= G[i].empty();
  if (f)
    cout << "-1\n";
  else {
    for (int i = 1; i <= 5; i++) {
      cout << G[i].back() << ' ';
      G[i].pop_back();
    }
    cout << '\n';
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  // freopen("data.in", "r", stdin);
  // freopen("data.out", "w", stdout);
  // int n;
  // G[1]={},G[2]={},G[3]={},G[5]={},G[4]={};
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    G[x].push_back(i);
    work();
  }
  return 0;
}