#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct fra {
  ll a = 1, b = 1;
  fra(ll a, ll b) { a = a, b = b; }
  fra() { a = 1, b = 1; }
  void sip() {
    ll div = __gcd(a, b);
    a /= div, b /= div;
  }
  friend fra operator+(const fra &x, const fra &y) {
    // freopenfra res;
    fra res(x.a * y.b + y.a * x.b, x.b * y.b);
    res.a = x.a * y.b + y.a * x.b;
    res.b = x.b * y.b;
    res.sip();
    // res.sip();
    return res;
  }
};
int num(ll x) {
  int sum = 0;
  while (x) {
    sum++;
    x /= 10;
  }
  return sum;
}
int main() {
  int n;
  while (cin >> n) {
    // cin>>n;
    // fra res; res.a=1,res.b=1;
    fra res(1, 1);
    fra x;
    for (int i = 2; i <= n; i++) {
      // x(1,i);
      x.a = 1, x.b = i;
      res = res + x;
    }
    res.a *= n;
    res.sip();

    ll v = res.a / res.b;
    res.a = res.a % res.b;
    if (res.a == 0)
      cout << v;

    else {
      int len1 = num(v);
      for (int i = 1; i <= len1; i++)
        cout << " ";
      cout << res.a << endl;

      int len2 = num(res.b);
      cout << v;
      for (int i = 1; i <= len2; i++)
        cout << "-";
      cout << endl;

      for (int i = 1; i <= len1; i++)
        cout << " ";
      cout << res.b;
    }
    cout << endl;
  }

  return 0;
}