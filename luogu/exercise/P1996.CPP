#include <bits/stdc++.h>
using namespace std;
struct Person {
  int id;
  Person *next, *prior;
  Person() { next = prior = nullptr; }
} n[100];

void kickout(Person *num) {
  num = num->prior;
  num->next = num->next->next;
  num = num->next;
  num->prior = num->prior->prior;
}

int main() {
  int tot, outNum, nowNum = 1;
  Person *now = n;
  cin >> tot >> outNum;

  for (int i = 1; i < tot - 1; i++) {
    n[i].prior = n + i - 1;
    n[i].next = n + i + 1;
    n[i].id = i + 1;
  }
  n[0].prior = n + tot - 1;
  n[0].next = n + 1;
  n[tot - 1].prior = n + tot - 2;
  n[tot - 1].next = n;
  n[0].id = 1;
  n[tot - 1].id = tot;

  while (tot) {
    if (nowNum == outNum) {
      cout << now->id << " ";
      kickout(now);

      nowNum = 1;
      tot--;
      now = now->next;
    } else {
      nowNum++;
      now = now->next;
    }
  }
  return 0;
}
/*{
    int n,m; cin>>n>>m;
    queue<int> q;
    for(int i=1;i<=n;i++) q.push(i);
    while(!q.empty())
    {
        for(int i=1;i<=m-1;i++)
        {
            int tmp=q.front();
            q.pop();q.push(tmp);
        }
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}
*/