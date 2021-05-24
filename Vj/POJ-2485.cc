#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 510;

struct edge {
  int u, v, w;
  bool operator<(const edge &x) const { return w < x.w; }
} es[maxn * maxn / 2];
