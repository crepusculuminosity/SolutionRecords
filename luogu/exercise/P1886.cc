#include <deque>
#include <iostream>
using namespace std;

const int maxn = 1e6 + 10;
int a[maxn];
int n, k;
int main() {
  freopen("data.in", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  deque<int> q;
  int t = k, now = k;
  q.push_front(a[k]);
  /*for (int i = k - 1; i >= 1; i--) {
    if (a[i] > a[t])
      break;
    q.push_front(a[i]);
    t = i;
  }*/
  while (a[--t] < a[now])
    q.push_front(a[t]), t = now;
  while (!q.empty()) {
    cout << q.front() << ' ';
    q.pop_front();
  }

  return 0;
}
