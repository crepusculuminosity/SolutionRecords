#include <bits/stdc++.h>
using namespace std;

deque<int> q;
inline int read() {
  int x = 0, f = 1; //
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-')
      f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}

int main() {
  int n = read(), m = read();
  while (m--) {
    int op, a;
    // int op=read();
    scanf("%d", &op);
    if (op == 1) {
      // int a=read();
      scanf("%d", &a);
      q.push_front(a);
    } else if (op == 2)
      q.pop_front();
    else if (op == 3) {
      scanf("%d", &a);
      // int a=read();
      q.push_back(a);
    } else if (op == 4)
      q.pop_back();
    else if (op == 5)
      reverse(q.begin(), q.end());
    else if (op == 6) {
      printf("%d\n", q.size());
      for (int i = 0; i < q.size(); i++)
        printf("%d ", q[i]);
      printf("\n");
    } else
      sort(q.begin(), q.end());
  }
  return 0;
}