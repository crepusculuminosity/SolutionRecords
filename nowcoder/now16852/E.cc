#include <bits/stdc++.h>
using namespace std;
const int maxn = 550;
int a[maxn][maxn];
int n;
struct node {
  int s, b;
  bool operator<(const node &x) const { return s < x.s; }
};
void solve(int *a, int *b) {
  priority_queue<node> q;
  for (int i = 1; i <= n; i++)
    q.push(node{a[i] + b[1], 1});
  for (int i = 1; i <= n; i++) {
    node e = q.top();
    q.pop();
    a[i] = e.s;
    int B = e.b;
    if (B + 1 <= n)
      q.push(node{e.s - b[B] + b[B + 1], B + 1});
  }
}
bool cmp(int x, int y) { return x > y; }
int main() {
  //freopen("data.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
      cin >> a[i][j];
    sort(a[i] + 1, a[i] + 1 + n, cmp);
  }
  for (int i = 2; i <= n; i++)
    solve(a[1], a[i]);
  for (int i = 1; i <= n; i++)
    printf("%d ", a[1][i]);
  return 0;
}