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

const ll oo=~0ull>>3;
int n,A,B,ans,r[160],s[160],sum[160];
ll f[160][160];

int main(){
//freopen("I.in","r",stdin);
ios::sync_with_stdio(false);
    while(cin>>n>>A>>B){
        rep(i,1,n) cin>>r[i]>>s[i];
        sum[n+1]=0;
        per(i,n,1) sum[i]=sum[i+1]+s[i];
        rep(i,0,n+1) rep(j,0,151) f[i][j]=oo;
        f[n+1][0]=0;
        per(i,n,1){
            rep(j,0,sum[i]) upmin(f[i][j],-f[i+1][sum[i]-j+1]-r[i]+1);
            rep(j,0,sum[i]) upmin(f[i][j],max(1ll,f[i+1][j]+r[i]+1));
        }
        per(i,sum[1],0) if (f[1][i]<=A-B){
            cout<<i<<' '<<sum[1]-i<<endl;
            break;
        }
    }
}
