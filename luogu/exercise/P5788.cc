#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 3e6 + 10;
stack<int> s;
int n;
int a[maxn], R[maxn];

int main() {
  //freopen("data.in", "r", stdin);
 // freopen("data.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= n + 1; i++) {
    while (!s.empty() && a[s.top()] < a[i])
      R[s.top()] = i, s.pop();
    s.push(i);
  }
  for (int i = 1; i <= n; i++) 
    cout<<R[i]<<' ';
  return 0;
}