#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int L, T, n;
struct ants {
  int id;
  int pos;
  int dir;
  bool operator<(const ants &a) const { return pos < a.pos; }
} a[MAXN], b[MAXN];
int order[MAXN];

const char dirName[][10] = {"L", "Turning", "R"};

int main() {
  freopen("data.in", "r", stdin);

  int _;
  scanf("%d", &_);
  for (int kase = 1; kase <= _; kase++) {
    scanf("%d%d%d", &L, &T, &n);
    for (int i = 1; i <= n; i++) {
      char ch;
      int p, d;
      scanf("%d%c", &p, &ch);
      d = (ch == 'L' ? -1 : 1);
      a[i] = (ants){i, p, d};
      b[i] = (ants){0, p + T * d, d};
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
      order[a[i].id] = i;
    sort(b + 1, b + 1 + n);
    for (int i = 1; i < n; i++)
      if (b[i].pos == b[i + 1].pos)
        b[i].dir = b[i + 1].dir = 0;

    for (int i = 1; i <= n; i++) {
      int t = order[i];
      if (b[t].pos < 0 || b[t].pos > L)
        printf("Fell off\n");
      else
        printf("%d %s\n", b[t].pos, dirName[b[t].dir + 1]);
    }
    printf("\n");
  }
  return 0;
}
