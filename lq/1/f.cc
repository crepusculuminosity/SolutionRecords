#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
const int INF=0x3f3f3f3f;
int d[maxn],vis[maxn];
struct node {
  int to,w;
};
struct Hnode {
  int d,u;
  bool operator< (const Hnode& x) const {
    return d>x.d;
  }
};
int n,m,s;
vector<node> G[maxn];

void dijkstra(int x) {
  priority_queue<Hnode> q;
  for(int i=1;i<=n;i++) d[i]=INF;
  d[x]=0;
  q.push({0,x});
  while(!q.empty()) {
    Hnode s=q.top(); q.pop();
    int u=s.u;
    if(vis[u]) continue;
    vis[u]=1;
    for(int i=0;i<G[u].size();i++) {
      node e=G[u][i];
      if(d[e.to]>d[u]+e.w) {
        d[e.to]=d[u]+e.w;
        q.push(Hnode{d[e.to],e.to});
      }
    }
  }
}

int main() {
  //freopen("data.in","r",stdin);
  cin>>n>>m>>s;
  for(int i=0;i<m;i++) {
    int a,b,c;
    cin>>a>>b>>c;
    G[a].push_back(node{b,c});
  }
  dijkstra(s);
  for(int i=1;i<=n;i++)
    cout<<d[i]<<' ';
  return 0;
}
