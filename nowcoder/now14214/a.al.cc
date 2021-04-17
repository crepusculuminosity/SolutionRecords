#include <bits/stdc++.h>
using namespace std;
using ll = long long;
unordered_map<ll, ll> mp;
vector<pair<ll, ll>> v;
bool cmp(pair<ll, ll> &a, pair<ll, ll> &b) {
  return a.first * a.second > b.first * b.second;
}
int main() {
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    ll x;
    cin >> x;
    ++mp[x];
  }
  for (auto x : mp)
    v.push_back(x);
  sort(v.begin(), v.end(), cmp);
  cout << v[0].first * v[0].second;
  return 0;
}