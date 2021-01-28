#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
namespace IStream {
const int L = 1 << 15;
char buffer[L], *S, *T;
inline char _getChar() {
  if (S == T) {
    T = (S = buffer) + fread(buffer, 1, L, stdin);
    if (S == T)
      return EOF;
  }
  return *S++;
}

inline int _getInt() {
  char ch;
  int re = 0, f = 1;
  for (ch = _getChar(); ch < '0' || ch > '9'; ch = _getChar())
    ;
  while (ch >= '0' && ch <= '9') {
    re = (re << 1) + (re << 3) + (ch - '0');
    ch = _getChar();
  }
  return re;
  /*ch=_getChar();
while (ch<'0'||ch>'9') {
    if(ch=='-') f=-1;
    ch=_getChar();

}
while (ch>='0'&&ch<='9') {
    re=(re<<1)+(re<<3)+ch-'0';
    ch=_getChar();
}
return re*f;*/
}
} // namespace IStream
const int maxn = 5e5 + 5;
int n, k, vis[maxn];
struct node {
  int val, id;
  bool operator<(const node &t) const { return val < t.val; }
} nd[maxn];
inline int read() {
  int x = 0;
  char c = getchar();
  while (c < '0' || c > '9')
    c = getchar();
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x;
}
int main() {
  // freopen("data.in","r",stdin);
  // cin >> n >> k;
  // n=read(),k=read();
  n = IStream::_getInt(), k = IStream::_getInt();
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 5; j++) {
      // nd[++cnt].val=read();
      nd[++cnt].val = IStream::_getInt();
      // cin >> nd[++cnt].val;
      nd[cnt].id = i;
    }
  }
  sort(nd + 1, nd + cnt + 1);
  int l = 1, r = 1, ans = inf, flag = 0;
  while (r <= cnt) {
    while (flag != n && r <= cnt) {
      if (!vis[nd[r].id]) {
        vis[nd[r].id]++;
        flag++;
      } else {
        vis[nd[r].id]++;
      }
      r++;
    }
    if (flag == n) {
      if ((nd[r - 1].val - nd[l].val) <= k)
        ans = min(ans, nd[r - 1].val - nd[l].val);
      if (vis[nd[l].id] == 1) {
        flag--;
      }
      vis[nd[l].id]--;
      l++;
    }
  }
  if (ans == inf)
    cout << "-1\n";
  else
    cout << ans << endl;
  return 0;
}