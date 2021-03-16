#include <bits/stdc++.h>
using namespace std;

struct point {
  double x, y;
} q[15];

inline double dis(point &a, point &b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

inline bool eq(point &a, point &b) {
  return fabs(a.x - b.x) < 1e-9 && fabs(a.y - b.y) < 1e-9;
}