#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int maxn = 10010;
int n, l, p;

struct node {
  int a, b;
  bool operator<(const node &x) const { return a < x.a; }
} q[maxn];

priority_queue<int> que;

int main() {
  // freopen("data.in", "r", stdin);
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> q[i].a >> q[i].b;
  cin >> l >> p;
  for (int i = 1; i <= n; i++)
    q[i].a = l - q[i].a;
  ++n;
  q[n].a = l, q[n].b = 0;
  sort(q + 1, q + 1 + n);
  int now = 0, ans = 0;
  bool f = 1;
  for (int i = 1; i <= n; i++) {
    int d = q[i].a - now;
    while (p < d) {
      if (que.empty()) {
        f = 0;
        break;
      }
      p += que.top();
      que.pop();
      ++ans;
    }
    if (!f)
      break;
    p -= d;
    now = q[i].a;
    que.push(q[i].b);
  }
  if (!f)
    cout << -1;
  else
    cout << ans;
  return 0;
}
