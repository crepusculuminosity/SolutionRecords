#include <cstring>
#include <iostream>
#include <string>
using namespace std;

const int maxn = 30;

// string w;
char w[1010];
int n, start;
/*G 邻接矩阵存图，in，out记录入度和出度*/
int G[maxn][maxn], in[maxn], out[maxn], vis[maxn];

void dfs(int u) {
  vis[u] = 0;
  for (int i = 1; i <= 26; ++i) {
    if (G[u][i] && vis[i])
      dfs(i);
  }
}

bool solve() {
  /*_in, _out记录欧拉回路中起点和终点的数量*/
  int t, u, v, _in = 0, _out = 0;
  memset(vis, 0, sizeof(vis));
  memset(G, 0, sizeof(G));
  memset(in, 0, sizeof(in));
  memset(out, 0, sizeof(out));
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cin >> w;
    u = w[0] - 'a' + 1;
    v = w[strlen(w) - 1] - 'a' + 1;
    G[u][v]++, G[v][u]++, out[u]++, in[v]++;
    vis[u] = vis[v] = 1;
  }
  dfs(u);
  for (int i = 1; i <= 26; ++i) {
    if (vis[i])
      return false;
    if (in[i] != out[i]) {
      if (in[i] - out[i] == 1)
        _in++;
      else if (out[i] - in[i] == 1)
        _out++;
      else
        return false;
    }
  }
  if ((_in == 1 && _out == 1) || (_in == 0 && _out == 0)) {
    return true;
  }
  return false;
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n;
  while (n--) {
    if (solve())
      cout << "Ordering is possible." << endl;
    else
      cout << "The door cannot be opened." << endl;
  }
  return 0;
}