#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
//#include<iostream>
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
#define FI first
#define SE second
using namespace std;
typedef long long ll;
typedef map<int,int>::iterator It;

int cas,n,m,u,v,l,Q,maxm,fa[120000];
ll ans,a[1200000];
struct edge{
    int v,l;
    edge(){}
    edge(int v,int l):v(v),l(l){}
};
vector<edge> e[120000];

void dfs(int u,int now){
    a[now]++;
    upmax(maxm,now);
    For(i,e[u].size()){
        int v=e[u][i].v;
        if (v==fa[u]) continue;
        fa[v]=u;
        dfs(v,now^e[u][i].l);
    }
}

int main(){
//freopen("11.in","r",stdin);
    scanf("%d",&cas);
    while(cas--){
        scanf("%d",&n);
        rep(i,1,n) e[i].clear();
        rep(i,1,n-1){
            scanf("%d%d%d",&u,&v,&l);
            e[u].push_back(edge(v,l));
            e[v].push_back(edge(u,l));
        }
        maxm=0;
        dfs(1,0);
        scanf("%d",&Q);
        while(Q--){
            scanf("%d",&m);
            ans=0;
            rep(i,0,maxm) //ans+=a[i]*a[i^m];
                if (i!=i^m) ans+=a[i]*a[i^m];
                else ans+=a[i]*(a[i]-1);
            ans/=2;
            if (m==0) ans+=n;
            printf("%I64d\n",ans);
        }
        rep(i,0,maxm) a[i]=0;
    }
}
