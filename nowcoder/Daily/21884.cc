#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int p = 233;
const ll INF = 9223372036854775807;
int vis[300];

inline ll read() {
  ll x = 0;
  char c = getchar();
  while (c < '0' || c > '9')
    c = getchar();
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x;
}

inline ll F(ll x) { return ((x * x % p * x) % p + x * x % p) % p; }
inline ll G(ll x) { return ((x * x % p * x) % p - x * x % p + p * p) % p; }

struct A {
  ll now, num;
};

int main() {
  int t = read(); // read<int>(t);
  // scanf("%d",&t);
  while (t--) {
    memset(vis, 0, sizeof(vis));
    ll a, b; // read<ll>(a),read<ll>(b);//使用快读会TLE
    // scanf("%lld%lld",&a,&b);
    a = read(), b = read();
    if (a == b) {
      printf("0\n");
      continue;
    }
    if (b >= p) {
      printf("-1\n");
      continue;
    }
    queue<A> q;
    if (a >= p) {
      ll c = F(a), d = G(a);
      vis[c] = 1, vis[d] = 1;
      q.push(A{c, 1});
      q.push(A{d, 1});
    } else {
      vis[a] = 1;
      q.push(A{a, 0});
    }
    ll ans = INF;
    while (!q.empty()) {
      A tmp = q.front();
      q.pop();
      if (tmp.now == b) {
        ans = tmp.num;
        break;
      } else {
        ll t1 = F(tmp.now), t2 = G(tmp.now);
        if (!vis[t1])
          q.push(A{t1, tmp.num + 1});
        if (!vis[t2])
          q.push(A{t2, tmp.num + 1});
        vis[t1] = 1;
        vis[t2] = 1;
      }
    }
    if (ans == INF)
      printf("-1\n");
    else
      printf("%lld\n", ans);
  }
  return 0;
}
