#include <bits/stdc++.h>
using namespace std;
constexpr int maxn=1e4+10;

struct tsk {
  int r,d,w;
  bool operator< (const tsk& x) const {
    return d>x.d;
  }
}q[maxn];

bool cmp(tsk a,tsk b) {
  return a.r<b.r;
}
