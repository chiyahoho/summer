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

const int M=1200;
const ll mo=1000000007;
vector<int> e[M];
int u,v,sz[M],cas,N,K,fa[M];
ll c[M][M],f[M][M];

void getsize(int u){
    sz[u]=1;
    For(i,e[u].size()) if (e[u][i]!=fa[u]){
        int v=e[u][i];
        fa[v]=u;
        getsize(v);
        sz[u]+=sz[v];
    }
}

void dfs(int u){
    int now=sz[u]-1;
    For(i,e[u].size()) if (e[u][i]!=fa[u]){
        int v=e[u][i];
        if (sz[v]==1){
            rep(j,1,K) f[v][j] = (f[u][j-1] * c[now][sz[v]]) % mo;
            rep(j,0,K) f[u][j]=f[v][j];
            now-=sz[v];
        }
        else{
            rep(j,1,K) f[v][j] = (f[u][j-1] * c[now][sz[v]]) % mo;
            rep(j,0,K) f[v][j] = ((((f[u][j] * c[now][sz[v]]) % mo) * (sz[v]-1)) % mo + f[v][j]) % mo;
            dfs(v);
            rep(j,0,K) f[u][j] = f[v][j];
            now-=sz[v];
        }
    }
}

void predo(){
    rep(i,0,1010) c[i][0]=1;
    rep(i,1,1010) rep(j,1,i)
        c[i][j]=(c[i-1][j-1]+c[i-1][j])%mo;
}

int main(){
//freopen("10.in","r",stdin);
    predo();
    cin>>cas;
    rep(ca,1,cas){
        scanf("%d%d",&N,&K);
        //if (N==1){
        //    printf("Case #%d: 1\n",ca);
        //    continue;
        //}
        rep(i,1,N) e[i].clear();
        rep(i,1,N-1){
            scanf("%d%d",&u,&v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        getsize(1);
        //rep(i,1,N) cout<<fa[i]<<' ';
        rep(j,2,K) f[1][j]=0;
        f[1][1]=1;
        f[1][0]=N-1;
        dfs(1);
        //rep(i,1,3) rep(j,0,K) cout<<f[i][j]<<' ';
        printf("Case #%d: ",ca);
        cout<<f[1][K]<<endl;
    }
}
