#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int trie[maxn][26],p,cnt[maxn];
char str[maxn];
void insert(char *str) {
	int len=strlen(str),p=1;
	for(int i=0;i<len;i++) {
		int ch=str[i]-'a';
		if(trie[p][ch]==0) trie[p][ch]=++tot;
		p=trie[p][ch];
	}
	cnt[p]=1;
}
int search(char *str) {
	int len=strlen(str),p=1,ans=0;
	for(int i=0;i<len;i++) {
		int ch=str[i]-'a';
		if(trie[p][ch]==0) break;
		ans+=cnt[p];
		p=trie[p][ch];
	}
	return ans;
}


int main() {
	freopen("data.in","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n,m;
	cin>>n>>m;
	while(n--) {
		cin>>str;
		insert(str);
	} 
}
