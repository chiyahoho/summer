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

int n,m,x,u,usd,vis[1200],vis2[1200],c[1200],an[1200][1200],ans2;
vector<int> e[1200],ans;

void dfs(int u){
    if (u==usd) return;
    vis[u]=1;
    For(i,e[u].size()) if (!vis[e[u][i]])
        dfs(e[u][i]);
}

int main(){
ios::sync_with_stdio(false);
freopen("hospital.in","r",stdin);
freopen("hospital.out","w",stdout);
    cin>>n>>m;
    rep(i,1,m){
        cin>>x;
        while(x--){
            cin>>u;
            e[u].push_back(i);
        }
    }
    rep(u,m+1,n) dfs(u);
    rep(i,1,m) if (!vis[i]) ans.push_back(i);
    cout<<ans.size()<<endl;
    For(i,ans.size()) cout<<ans[i]<<' ';
    cout<<endl;

    rep(i,1,n) vis2[i]=vis[i];
    rep(i,1,n){
        usd=i;
        rep(j,1,n) vis[j]=0;
        rep(j,m+1,n) dfs(j);
        int top=0;
        rep(j,1,n) if (vis2[j] && !vis[j]) c[++top]=j;
        rep(j,1,top) rep(k,j+1,top) an[c[j]][c[k]]=1;
    }

    rep(i,1,n) rep(j,1,n) if (an[i][j]) ans2++;
    cout<<ans2<<endl;
    if (ans2<=10000){
        rep(i,1,n) rep(j,1,n) if (an[i][j]) cout<<i<<' '<<j<<endl;
    }
}
