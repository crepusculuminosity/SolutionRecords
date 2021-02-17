#include <bits/stdc++.h>
using namespace std;
int is_s, is_q, is_pq;
stack<int> s;
queue<int> q;
priority_queue<int> pq;
int n;

inline void clr() {
  while (!s.empty())
    s.pop();
  while (!q.empty())
    q.pop();
  while (!pq.empty())
    pq.pop();
  is_s = is_q = is_pq = 1;
}

inline void ist(int x) {
  s.push(x);
  q.push(x);
  pq.push(x);
}

inline void pp(int x) {
  if (s.empty())
    is_s = is_q = is_pq = 0;
  else {
    int tmp;

    tmp = s.top();
    s.pop();
    if (tmp != x)
      is_s = 0;

    tmp = q.front();
    q.pop();
    if (tmp != x)
      is_q = 0;

    tmp = pq.top();
    pq.pop();
    if (tmp != x)
      is_pq = 0;
  }
}

int main() {
  // freopen("data.in", "r", stdin);
  while (cin >> n) {
    clr();
    while (n--) {
      int a, b;
      cin >> a >> b;
      if (a == 1)
        ist(b);
      else
        pp(b);
    }
    // cout<<is_s<<" "<<is_q<<" "<<is_pq<<endl;
    if (is_s && !is_q && !is_pq)
      puts("stack");
    else if (!is_s && is_q && !is_pq)
      puts("queue");
    else if (!is_s && !is_q && is_pq)
      puts("priority_queue");
    else if (!is_s && !is_q && !is_pq)
      puts("impossible");
    else
      puts("not sure");
  }
  return 0;
}