#include <algorithm>
#include <cstring> // memset
#include <iostream>
#include <tuple>
#include <vector>

// Complexity: O(8 * n^2 + 8 n log n) = O(n^2)

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int maxn = 5000;
int n, x[maxn], y[maxn];

struct pt_idx {
  int fst, snd, idx;
};

bool operator<(pt_idx a, pt_idx b) {
  return tie(a.fst, a.snd) < tie(b.fst, b.snd);
}

ii ordering(int i, int d) {
  // >>, ^>, ^^, <^, <<, <v, vv, v>.

  // orthogonals:
  if (d == 0)
    return ii(y[i], x[i]);
  if (d == 2)
    return ii(-x[i], y[i]);
  if (d == 4)
    return ii(-y[i], -x[i]);
  if (d == 6)
    return ii(x[i], -y[i]);

  // diagonals:
  if (d == 1)
    return ii(-x[i] + y[i], x[i] + y[i]);
  if (d == 3)
    return ii(-x[i] - y[i], -x[i] + y[i]);
  if (d == 5)
    return ii(x[i] - y[i], -x[i] - y[i]);
  if (d == 7)
    return ii(x[i] + y[i], x[i] - y[i]);

  exit(1);
}

pt_idx order[8][maxn];
ll ways[9][maxn] = {};

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d%d", &x[i], &y[i]);

  for (int d = 0; d < 8; d++) {
    for (int i = 0; i < n; i++) {
      auto [fst, snd] = ordering(i, d);
      order[d][i] = {fst, snd, i};
    }
    sort(order[d], order[d] + n);
  }

  ll res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      ways[0][j] = (j == i);
    for (int d = 0; d < 8; d++) {
      int lst = -1, lstfst;
      for (int o = 0; o < n; o++) {
        const pt_idx &pt = order[d][o];
        if (lst == -1 || pt.fst != lstfst)
          ways[d + 1][pt.idx] = 0;
        else
          ways[d + 1][pt.idx] = ways[d][lst] + ways[d + 1][lst];

        lst = pt.idx;
        lstfst = pt.fst;
      }
    }

    res += ways[8][i];
  }

  printf("%lld\n", res);
}
