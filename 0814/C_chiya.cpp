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

int n,m,l,r,u,v,ans;
struct edge{
    int u,v;
}e[120000];

bool cmp(edge a,edge b){
    return a.u<b.u;
}

int main(){
//freopen("C.in","r",stdin);
ios::sync_with_stdio(false);
    while(cin>>n>>m){
        ans=n+1;
        rep(i,1,m) cin>>e[i].u>>e[i].v;
        sort(e+1,e+m+1,cmp);
        r=0; l=0;
        rep(i,1,m){
            if (e[i].u>r){
                ans+=2*(r-l);
                l=e[i].u;
            }
            upmax(r,e[i].v);
        }
        ans+=2*(r-l);
        cout<<ans<<endl;
    }
}
