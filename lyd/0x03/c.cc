#include <iostream>
#include <map>
using namespace std;
const int maxn = 1e4 + 10;
int b[maxn];
typedef long long ll;
map<ll, bool> mp;
int N, I, H, R;

int main() {
  // freopen("data.in", "r", stdin);
  cin >> N >> I >> H >> R;
  for (int i = 1; i <= R; i++) {
    int l, r;
    cin >> l >> r;
    if (l > r)
      swap(l, r);
    ll tmp = l * (ll)1e5 + r;
    if (mp[tmp])
      continue;
    mp[tmp] = 1;
    --b[l + 1], ++b[r];
  }
  int t = b[1] + H;
  cout << t << '\n';
  for (int i = 2; i <= N; i++) {
    t += b[i];
    cout << t << '\n';
  }
  return 0;
}