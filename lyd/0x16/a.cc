#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int trie[maxn][26],tot=1,cnt[maxn];
char ch[maxn];
void insert(char *str) {
	int len=strlen(str),p=1;
	for(int i=0;i<len;i++) {
		int ch=str[i]-'a';
		if(trie[p][ch]==0) trie[p][ch]=++tot;
		p=trie[p][ch];
		
	}
	cnt[p]++;
}
int query(char *str) {
	int ans=0,len=strlen(str),p=1;
	for(int i=0;i<len;i++) {
		int ch=str[i]-'a';
		if(trie[p][ch]==0) break;
		p=trie[p][ch];
		ans+=cnt[p];
	}
	return ans;
}

int main() {
	//freopen("data.in","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>ch;
		insert(ch);
	}
	for(int i=1;i<=m;i++) {
		cin>>ch;
		cout<<query(ch)<<'\n';
	}
	return 0;
}