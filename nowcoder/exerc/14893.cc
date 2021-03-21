#include <bits/stdc++.h>
using namespace std;
stack<int> s;
constexpr int maxn = 1e6 + 10;
int a[maxn], b[maxn];
int main() {
  // freopen("data.in", "r", stdin);
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = n; i; i--)
    b[i] = max(b[i + 1], a[i]);
  for (int i = 1; i <= n; i++) {
    s.push(a[i]);
    while (s.size() && s.top() > b[i + 1]) {
      cout << s.top() << ' ';
      s.pop();
    }
  }
  return 0;
}