<<<<<<< HEAD
=======
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
const int maxn=1e5+10;
int d[maxn],tot=1,trie[maxn*31][2],n; 
void insert(int n) {
	int p=1;
	for(int i=31;i>=0;i--) {
		int ch=(n>>i)&1;
		if(trie[p][ch]==0) trie[p][ch]=++tot;
		p=trie[p][ch];
	}
}
int query(int n) {
	int ans=0,p=1;
	for(int i=31;i>=0;i--) {
		int ch=(n>>i)&1, oh=ch^1;
		if(trie[p][oh]) p=trie[p][oh],ans=ans<<1|1;
		else p=trie[p][ch],ans<<=1;
	}
	return ans;
}
struct node {
	int to,w;
};
vector<node> G[maxn];
inline void add(int u, int v, int w) {
	G[u].push_back(node{v,w});
}
inline int read() {
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+ch-48,ch=getchar();
	return x;
}
void dfs(int u, int fa) {
	//d[u]=0;
	for(int i=0;i<G[u].size();i++) {
		node& e=G[u][i];
		if(e.to==fa) continue;
		d[e.to]=d[u]^e.w;
		dfs(e.to,u);
	}
}
int main() {
//freopen("data.in","r",stdin);
	
	while(~scanf("%d",&n)) {
		memset(trie,0,sizeof(trie));
		memset(d,0,sizeof(d));
		tot=1;
		for(int i=0;i<=n;i++) G[i].clear();
		for(int i=1;i<=n-1;i++) {
		int u=read(),v=read(),w=read();
		add(u+1,v+1,w);
		add(v+1,u+1,w);
	}
	dfs(1,0);
	int ans=0;
	for(int i=1;i<=n;i++) {
		ans=max(ans,query(d[i]));
		insert(d[i]); 
	} 
	printf("%d\n",ans);
	}
	 
	return 0;
}

>>>>>>> be19aecb4372925c9f857ee8ed55390d6bcba235
