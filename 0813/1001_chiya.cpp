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

const int N=220000;
int cas,l,r,n,m,a[N],buy[N],sell[N],sz[2*N];
ll ans,pr[2*N];

int main(){
//freopen("01.in","r",stdin);
ios::sync_with_stdio(false);
    cin>>cas;
    while(cas--){
        cin>>n>>m;
        ans=0;
        rep(i,1,n) cin>>a[i];
        rep(i,0,n) cin>>buy[i]>>sell[i];
        l=n+1; r=n+1;
        pr[l]=buy[0];
        sz[l]=m;
        ans=-pr[l]*sz[l];
        rep(i,1,n){
            int here=a[i]-a[i-1];
            while (here){
                if (sz[l]<=here) here-=sz[l++];
                else {sz[l]-=here; here=0;}
            }
            here=a[i]-a[i-1];
            while(l<=r && pr[r]>=buy[i]){
                ans+=pr[r]*sz[r];
                here+=sz[r--];
            }
            pr[++r]=buy[i];
            sz[r]=here;
            ans-=pr[r]*sz[r];
            here=0;
            while(l<=r && pr[l]<=sell[i]) here+=sz[l++];
            pr[--l]=sell[i];
            sz[l]=here;
        }
        rep(i,l,r) ans+=pr[i]*sz[i];
        cout<<-ans<<endl;
    }
}
