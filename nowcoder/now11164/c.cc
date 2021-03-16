#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e6 + 10;
char a[maxn], b[maxn];
list<char> l;
int main() {
  // freopen("data.in", "r",stdin);
  scanf("%s", a);
  scanf("%s", b);
  int len = strlen(b);
  auto now = l.begin();
  l.insert(now, a[0]);
  for (int i = 0; i < len - 1; i++) {
    if (b[i] == 'L')
      --now;
    l.insert(now, a[i + 1]);
  }
  for (auto i = l.begin(); i != l.end(); i++)
    putchar(*i);
  return 0;
}