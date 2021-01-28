#include <bits/stdc++.h>
using namespace std;
int a[15];
bool f;
void dfs(int x, int y, int cnt) {
  // if(s<x&&s<y) return;
  if (cnt == 10) {
    f = 1;
    return;
  }
  cnt++;
  if (a[cnt] > x)
    dfs(a[cnt], y, cnt);
  if (a[cnt] > y)
    dfs(x, a[cnt], cnt);

  /*if(a[cnt]>x&&a[cnt]>y) {
    dfs(a[cnt],y,cnt);
    dfs(x,a[cnt],cnt);
}
if(a[cnt]>x&&a[cnt]<y) dfs(a[cnt],y,cnt);
if(a[cnt]<x&&a[cnt]>y) dfs(x,a[cnt],cnt);*/
}

int main() {
  freopen("data.in", "r", stdin);

  int _;
  cin >> _;
  while (_--) {
    f = 0;
    for (int i = 1; i <= 10; i++)
      cin >> a[i];

    dfs(0, 0, 0);
    if (f == 1)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}