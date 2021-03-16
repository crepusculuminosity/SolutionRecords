#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int sum[maxn];

void build(int p) {
  int v;
  cin >> v;
  if (v == -1)
    return;
  sum[p] += v;
  build(p - 1);
  build(p + 1);
}

bool init() {
  int v;
  cin >> v;
  if (v == -1)
    return false;
  memset(sum, 0, sizeof(sum));
  int p = maxn / 2;
  sum[p] = v;
  build(p - 1);
  build(p + 1);
  return 1;
}

int main() {
  // freopen("data.in", "r", stdin);
  int kase = 0;
  while (init()) {
    int p = 0;
    while (!sum[p])
      p++;
    cout << "Case " << ++kase << ':' << endl << sum[p++];

    while (sum[p])
      cout << " " << sum[p++];
    cout << endl << endl;
  }
  return 0;
}