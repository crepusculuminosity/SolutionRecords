#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
using namespace std;
#define INF 0xfffffff
const int maxn = 100010;
typedef long long LL;
int c[maxn], lmin[maxn], lmax[maxn], rmin[maxn], rmax[maxn], a[maxn];
int lowbit(int x) { return x & (-x); }
void update(int i, int l) {
  while (i < maxn) {
    c[i] += l;
    i += lowbit(i);
  }
}
int sum(int i) {
  int ans = 0;
  while (i > 0) {
    ans += c[i];
    i -= lowbit(i);
  }
  return ans;
}
int main() {
 // freopen("data.in","r",stdin);
  //freopen("data1.out","w",stdout);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= n; i++) {
      update(a[i], 1);
      lmin[i] = sum(a[i] - 1);
      lmax[i] = i - 1 - lmin[i];
      // cout<<lmin[i]<<" "<<lmax[i]<<endl;
    }
    memset(c, 0, sizeof(c));
    for (int i = n; i >= 1; i--) {
      update(a[i], 1);
      rmin[i] = sum(a[i] - 1);
      rmax[i] = n - i - rmin[i];
      // cout<<rmin[i]<<" "<<rmax[i]<<endl;
    }
    LL ans = 0;
    for (int i = 1; i <= n; i++) {
      ans += lmin[i] * rmax[i];
      ans += lmax[i] * rmin[i];
    }
    cout << ans << endl;
  }
  return 0;
}