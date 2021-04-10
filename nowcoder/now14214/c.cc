#include <bits/stdc++.h>
using namespace std;
using ll = long long;
unordered_map<ll, ll> mp;
vector<pair<ll, ll>> v;
bool cmp(pair<ll, ll> &a, pair<ll, ll> &b) {
  return a.first * a.second > b.first * b.second;
}

inline ll read() {
  ll x = 0;
  char ch = getchar();
  while (!isdigit(ch))
    ch = getchar();
  while (isdigit(ch))
    x = x * 10 + ch - 48, ch = getchar();
  return x;
}

int main() {
  clock_t s = clock();
  freopen("data.in", "r", stdin);
  freopen("data1.out", "w", stdout);
  int n;
  while (~scanf("%lld", &n)) {
    mp.clear();
    v.clear();
    for (int i = 1; i <= n; i++) {
      ll x = read();
      // cin >> x;
      ++mp[x];
    }
    for (auto x : mp)
      v.push_back(x);
    sort(v.begin(), v.end(), cmp);
    // cout << v[0].first * v[0].second<<endl;
    printf("%lld\n", v[0].first * v[0].second);
  }
  clock_t now = clock();
  cout << (double)(now - s) / CLOCKS_PER_SEC;
  return 0;
}