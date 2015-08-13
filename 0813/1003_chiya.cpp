#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<cmath>
#define rep(i,a,b) for(int i=a,_b=b;i<=_b;i++)
#define per(i,a,b) for(int i=a,_b=b;i>=_b;i--)
#define For(i,b) for(int i=0,_b=b;i<_b;i++)
#define upmax(a,b) if ((a)<(b)) (a)=(b)
#define upmin(a,b) if ((a)>(b)) (a)=(b)
using namespace std;
typedef long long ll;

int n,cas,g[1200000],t[1200000],f[1200000],s[1200000];
const int mo=258280327;

int gcd(int a,int b){
    if (!b) return a;
    return gcd(b,a%b);
}

int main(){
//freopen("03.in","r",stdin);
//ios::sync_with_stdio(false);
    n=1000000;
    rep(d,1,n)
        for(int i=1;i*d<=n;i++)
            if (gcd(d,i)==1) g[i*d]++;
    rep(d,1,n)
        for(int i=1;i*d<=n;i++)
            t[i*d]=(t[i*d]+g[i-1])%mo;
    rep(i,1,n) f[i]=(f[i-1]+2*i-1-t[i-1])%mo;
    rep(i,1,n) s[i]=(s[i-1]+f[i])%mo;
    scanf("%d",&cas);
    while(cas--){
        scanf("%d",&n);
        printf("%d\n",s[n]);
    }
}
