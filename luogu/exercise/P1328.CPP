#include <bits/stdc++.h>
using namespace std;
const int MAXN = 210;
int vis[5][5] = {{0, 0, 1, 1, 0},
                 {1, 0, 0, 1, 0},
                 {0, 1, 0, 0, 1},
                 {0, 0, 1, 0, 1},
                 {1, 1, 0, 0, 0}};
int a[MAXN], b[MAXN];
int main() {
  int n, na, nb, cnta, cntb;
  cnta = cntb = 0;
  cin >> n >> na >> nb;
  for (int i = 0; i < na; i++)
    cin >> a[i];
  for (int i = 0; i < nb; i++)
    cin >> b[i];
  for (int i = 0; i < n; i++) {
    cnta += vis[a[i % na]][b[i % nb]];
    cntb += vis[b[i % nb]][a[i % na]];
  }
  cout << cnta << " " << cntb << endl;
  return 0;
}