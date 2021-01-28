#include <bits/stdc++.h>
using namespace std;

const int MAXN=100005;
class BigInteger
{
private:
    int val[MAXN];
    short len;
public:
    BigInteger();
    BigInteger(int n);
    void clean();
    friend ostream& operator<< (ostream&, const BigInteger&);
    friend istream& operator>> (istream&, BigInteger&);
    friend BigInteger operator+ (const BigInteger& a, const BigInteger& b);
    friend BigInteger operator* (const BigInteger& a, const BigInteger& b);
};

BigInteger::BigInteger(int n)
{
    for(int i=0;i<MAXN;i++) val[i]=0;
    n=n>0?n:-n;
    for(len=1;n;len++,n/=10)
        val[len]=n%10;
    len--;
}

BigInteger::BigInteger()
{
    for(int i=0;i<MAXN;i++) val[i]=0;
    len=0;
}

ostream& operator<<(ostream& out, const BigInteger& obj)
{
    if(obj.len==0){
        cout<<0;
        return out;
    }
    for(int i=obj.len;i>0;i--)
        out<<obj.val[i];
    return out;
} 

istream& operator>> (istream& in, BigInteger& obj)
{
    string s;
    in>>s;
    int i=s.length(),j=0;
    obj.len=s.length();
    for(;i>0;i--,j++)
        obj.val[i]=s[j]-'0';
    return in;
}

BigInteger operator+ (const BigInteger& a, const BigInteger& b)
{
    BigInteger c;
    int max=a.len>b.len?a.len:b.len;
    for(int i=1;i<=max;i++)
    {
        c.val[i]+=a.val[i]+b.val[i];
        c.val[i+1]=c.val[i]/10;
        c.val[i]%=10;
    }
    if(c.val[max+1]==0) c.len=max;
    else c.len=max+1;
    return c;
}

BigInteger operator* (const BigInteger& a, const BigInteger& b)
{
    BigInteger c;
    c.len=a.len+b.len;
    for(int i=1;i<=a.len;i++)
        for(int j=1;j<=b.len;j++)
            c.val[i+j-1]+=a.val[i]*b.val[j];
    for(int i=1;i<=c.len;i++){
        c.val[i+1]+=c.val[i]/10;
        c.val[i]%=10;
    }
    c.clean();
    return c;
}

void BigInteger::clean()
{
    while(len>0&&!val[len])
        len--;
}

int main()
{
    BigInteger pro(1);
    int a[5005]={0},n,res=0;
    int q=2;
    cin>>n;
    for(int i=2;res<=n;i++)
    {
        a[i]=i;
        res+=i;
        q++;
    }
    
    //while(a[q]) q++;
    if(res-n==1) {
        a[2]=1;
        a[q-1]++;
    }
    if(res-n>1){
        a[res-n]=1;
    }
    for(int i=2;i<=q-1;i++){
        pro=pro*a[i];
        if(a[i]==1) continue;
        cout<<a[i]<<" ";
    }
    cout<<endl<<pro<<endl;
    return 0;
}
