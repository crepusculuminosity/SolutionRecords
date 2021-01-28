#include <bits/stdc++.h>
using namespace std;
priority_queue<int> q1;
priority_queue<int, vector<int>, greater<int>> q2;
int n, x;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    q1.push(x);
    q2.push(x);
  }
  while (q1.size() > 1) {
    int a = q1.top();
    q1.pop();
    int b = q1.top();
    q1.pop();
    q1.push(a * b + 1);

    a = q2.top();
    q2.pop();
    b = q2.top();
    q2.pop();
    q2.push(a * b + 1);
  }
  printf("%d\n", q2.top() - q1.top());
  return 0;
}