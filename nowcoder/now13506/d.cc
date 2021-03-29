#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
  set<int> vis;
  scanf("%d", &N);
  while (N > 1) {
    if (vis.count(N)) {
      puts("UNHAPPY");
      return 0;
    }
    vis.insert(N);
    int nxt = 0;
    for (int v = N; v; v /= 10)
      nxt += (v % 10) * (v % 10);
    N = nxt;
  }
  j puts("HAPPY");
}