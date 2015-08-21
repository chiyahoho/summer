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

const int maxn=400;
int n,m,K,u,v,l;

struct Stoer_Wagner{
    int n,g[maxn][maxn], b[maxn], dist[maxn];
    int Min_Cut_Phase(int ph,int &x,int &y){
        int i,j,t;
        b[t=1]=ph;
        for(i=1;i<=n;++i)
            if (b[i]!=ph) dist[i]=g[1][i];
        for(i=1;i<n;++i){
            x=t;
            for(t=0,j=1;j<=n;++j)
                if (b[j]!=ph && (!t || dist[j]>dist[t])) t=j;
            b[t]=ph;
            for(j=1;j<=n;++j)
                if (b[j]!=ph) dist[j]+=g[t][j];
        }
        //cout<<"y"<<' '<<y<<' '<<dist[t]<<endl;
        return y=t,dist[t];
    }
    void Merge(int x,int y){
        int i;
        if (x>y) swap(x,y);
        for(i=1;i<=n;++i)
            if (i!=x && i!=y)
                g[i][x]+=g[i][y],g[x][i]+=g[i][y];
        if (y==n) return;
        for(i=1;i<n;++i) if (i!=y){
            swap(g[i][y],g[i][n]);
            swap(g[y][i],g[n][i]);
        }
    }
    int Min_Cut(){
        int i,ret=0x3fffffff,x,y;
        memset(b,0,sizeof(b));
        for(i=1;n>1;++i,--n){
            int ccc=Min_Cut_Phase(i,x,y);
            upmin(ret,ccc);
            //cout<<x<<' '<<y<<' '<<ret<<endl;
            Merge(x,y);
        }
        return ret;
    }
}S;

int chg(int u){
    if (u==1) return K;
    if (u==K) return 1;
    return u;
}

int main(){
//freopen("b.in","r",stdin);
    while(scanf("%d%d%d",&n,&m,&K),n){
        rep(i,1,n) rep(j,1,n) S.g[i][j]=0;
        rep(i,1,m){
            scanf("%d%d%d",&u,&v,&l);
            u=chg(u); v=chg(v);
            S.g[u][v]+=l;
            S.g[v][u]+=l;
        }
        S.n=n;
        printf("%d\n",S.Min_Cut());
    }
}
