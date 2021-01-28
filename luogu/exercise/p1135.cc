#include <bits/stdc++.h>
#define mkp make_pair
using namespace std;

const int MAXN = 210;
int a[MAXN];
bool vis[MAXN];
struct node {
  int id, step;
} h;
int s, t, n;
queue<node> q;

int main() {
  cin >> n >> s >> t;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  q.push((node){s, 0});
  vis[s] = 1;
  while (!q.empty()) {
    h = q.front();
    q.pop();
    if (h.id == t)
      break;
    int now = h.id;
    if (now + a[now] <= n && !vis[now + a[now]]) {
      vis[now + a[now]] = 1;
      q.push((node){now + a[now], h.step + 1});
    }
    if (now - a[now] >= 1 && !vis[now - a[now]]) {
      vis[now - a[now]] = 1;
      q.push((node){now - a[now], h.step + 1});
    }
  }
  if (h.id == t)
    cout << h.step;
  else
    cout << -1;
  return 0;
}