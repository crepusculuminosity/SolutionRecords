
#include <bits/stdc++.h>
using namespace std;
int a[5000005];
int n,k;


/*inline int read()
{
    int x=0,f=1;
    char c=getchar();
    while (c<'0'||c>'9')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        //x=(x<<1)+(x<<3)+(c^48);
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}*/
namespace IStream{
    const int L=1<<15;
    char buffer[L],*S,*T;
    inline char _getChar(){
        if(S==T){
            T=(S=buffer)+fread(buffer,1,L,stdin);
            if(S==T) return EOF;
        }
        return *S++;
    }
    inline int _getInt(){
        char ch; int re=0;
        for(ch=_getChar();ch<'0'||ch>'9';ch=_getChar());
        while(ch>='0'&&ch<='9')
            re=(re<<1)+(re<<3)+(ch-'0'),ch=_getChar();
        return re;
    }
}

void _swap(int& a, int& b)
{
    int tmp=a;
    a=b;
    b=tmp;
}

void _qSort(int l, int r)
{
    if(l>=r) return;
    int mid=a[(l+r)/2];

    int p=l, q=r;

    do{
        while(a[p]<mid) p++;
        while(a[q]>mid) q--;

        if(p<=q){
            _swap(a[p],a[q]);
            p++;
            q--;
        }
    }while(p<=q);

    if(l<q) _qSort(l,q);
    if(p<r) _qSort(p,r);
}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;++i)
        a[i]=IStream::_getInt();
    _qSort(0,n-1);
    printf("%d",a[k]);
    return 0;
}