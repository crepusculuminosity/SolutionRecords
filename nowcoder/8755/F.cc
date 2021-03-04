#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e5 + 10;
typedef long long ll;
ll dp[maxn], a[maxn];

inline ll read() {
  ll x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9')
    ch = getchar();
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}

int main() {
  ll n = read();
  for (int i = 1; i <= n; i++)
    a[i] = read();
  dp[1] = a[1], dp[3] = a[2];
  for (int i = 4; i <= n;)
}