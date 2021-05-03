#include <bits/stdc++.h>
#define IOS                                                                    \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0)
#define INF 0x3f3f3f3f
#define MEM(x, y) memset(x, y, sizeof(x))
#define Maxn 50
#define P pair<int, int>
using namespace std;
int n;
int maxx;         
int d[Maxn][Maxn]; 
void Floyd() {
  for (int k = 0; k <= maxx; k++)
    for (int i = 0; i <= maxx; i++)
      for (int j = 0; j <= maxx; j++)
        d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
}
int main() {
  IOS;
  while (cin >> n, n) {
    MEM(d, INF); 
    for (int i = 0; i <= n; i++)
      d[i][i] = 0; 
    maxx = -1;
    while (n--) {
      int a, b, c;
      cin >> a >> b >> c;
      maxx = max(maxx, max(a, b));
      d[a][b] = d[b][a] = c;
    }
    Floyd();                        
    int ans = INF;                  
    int pos;                        
    for (int i = 0; i <= maxx; i++) 
    {
      int sum = 0;
      for (int j = 0; j <= maxx; j++)
        sum += d[i][j];
      if (ans > sum) {
        ans = sum;
        pos = i;
      }
    }
    cout << pos << ' ' << ans << endl;
  }
  return 0;
}