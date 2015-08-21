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

const ll mo=1000000007;
ll ans,g[200];
int n,cnt,k,m,a[120][120],flag,f[120];

int main(){
//freopen("04.in","r",stdin);
ios::sync_with_stdio(false);
    g[0]=1;
    rep(i,1,100) g[i]=(g[i-1]*i)%mo;
    while(cin>>n>>m){
        cnt=-1; ans=1;
        rep(i,1,m){
            cin>>a[i][1];
            if (a[i][1]==-1) cnt++;
            else{
                rep(j,2,n) cin>>a[i][j];
                rep(j,1,n) f[j]=0;
                rep(j,1,n) f[a[i][j]]=1;
                rep(j,1,n) if (!f[j]) ans=0;
            }
        }
        if (cnt==-1){
            rep(i,1,n){
                k=i;
                per(j,m,1) k=a[j][k];
                if (k!=i) ans=0;
            }
        }
        else{
            while(cnt--) ans=(ans*g[n])%mo;
        }
        cout<<ans<<endl;
    }
}
