#include <bits/stdc++.h>
using namespace std;

int main() {
  int t, n, m;
  //freopen("data.in", "r", stdin);
  //  freopen("data.out", "w", stdout);
  set<vector<int>> st;
  cin >> t;
  while (t--) {
    
    cin >> n;
    vector<int> a, buf, zero(n, 0);
    for (int i = 0; i < n; i++) {
      cin >> m;
      a.push_back(m);
    }
    buf = a;
    for (;;) {
      for (int i = 0; i < n; i++) {
        a[i] = abs(a[i] - buf[(i + 1) % n]);
      }
      st.insert(buf);
      if (a == zero) {
        printf("ZERO\n");
        break;
      }
      if (st.count(a)) {
        printf("LOOP\n");
        break;
      }
      buf = a;
    }
    a.clear();
    st.clear();
  }

  return 0;
}