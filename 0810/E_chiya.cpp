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

int n,m,ans,now,a[120000],b[120000];

int main(){
freopen("electricity.in","r",stdin);
freopen("electricity.out","w",stdout);
    scanf("%d%d",&n,&m);
    rep(i,1,n) scanf("%d",&a[i]);
    rep(i,1,m) scanf("%d",&b[i]);
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    ans=1,now=0;
    while(m){
        if (!now && n) now=a[n--],ans--;
        if (!now) break;
        now--; ans+=b[m--];
    }
    printf("%d\n",ans);
}

