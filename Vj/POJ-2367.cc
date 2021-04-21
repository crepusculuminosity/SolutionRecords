#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int n;
int in[110];
vector<int> G[110];


int main() {
  //freopen("data.in","r",stdin);
  //freopen("data.out","w",stdout);
  cin>>n;
  for(int i=1;i<=n;i++) {
    int x;
    while(cin>>x&&x) {
      G[i].push_back(x);
      ++in[x];
    }
  }
  queue<int> q;
  for(int i=1;i<=n;i++) if(!in[i]) q.push(i);
  while(!q.empty()) {
    int u=q.front(); q.pop();
    cout<<u<<' ';
    for(int i=0;i<G[u].size();i++) {
      --in[G[u][i]];
      if(!in[G[u][i]]) q.push(G[u][i]);
    }
  }
  return 0;
}