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

const int N=320;
const int oo=1000000000;
int cas,n,m,tot,ans,S,T,h[N],d[N],f[N],q[N];
struct edge{
    int v,l,c,n;
}e[(N+3)*N];
struct SM{
    int c,lv,atk;
}sm[N];
struct BM{
    int lv,atk,e[3];
}bm[N];
struct PRE{
    int v,e;
}pre[N];

inline void add(int u,int v,int c){
    e[++tot].v=v;
    e[tot].l=1;
    e[tot].c=c;
    e[tot].n=h[u];
    h[u]=tot;

    e[++tot].v=u;
    e[tot].l=0;
    e[tot].c=-c;
    e[tot].n=h[v];
    h[v]=tot;
}

inline int relax(int u,int y,int v){
    if (d[u]+e[y].c>d[v]){
        d[v]=d[u]+e[y].c;
        pre[v].v=u;
        pre[v].e=y;
        return 1;
    }
    return 0;
}

int spfa(){
    int i,l,r,u,v,y,k;
    rep(i,1,T){
        d[i]=-oo;
        f[i]=0;
        pre[i].v=-1;
        pre[i].e=0;
    }
    l=0; r=1;
    q[1]=S; d[S]=0;
    while(l<r){
        u=q[++l];
        f[u]=0;
        for(y=h[u];y;y=e[y].n){
            v=e[y].v;
            if (e[y].l && relax(u,y,v) && !f[v]){
                f[v]=1;
                q[++r]=v;
            }
        }
    }
    if (d[T]<=0) return 0;
    for(v=T;pre[v].v!=-1;v=pre[v].v){
        y=pre[v].e;
        ans+=e[y].c;
        e[y].l=0;
        e[y^1].l=1;
    }
    return 1;
}

int main(){
//freopen("04.in","r",stdin);
//ios::sync_with_stdio(false);
    scanf("%d",&cas);
    while(cas--){
        scanf("%d%d",&n,&m);
        tot=1; ans=0;
        rep(i,1,n+2) h[i]=0;

        rep(i,1,n) scanf("%d%d%d",&sm[i].c,&sm[i].lv,&sm[i].atk);
        rep(i,1,m) {
            scanf("%d%d%d",&bm[i].lv,&bm[i].atk,&bm[i].e[0]);
            rep(j,1,bm[i].e[0]) scanf("%d",&bm[i].e[j]);
        }
        S=n+1; T=n+2;
        rep(i,1,n) if (sm[i].c==0)
            rep(j,1,n) if (sm[j].c==1){
                int maxatk=0;
                rep(k,1,m) if (sm[i].lv+sm[j].lv==bm[k].lv){
                    if (bm[k].e[0]==2 && !((i==bm[k].e[1] || i==bm[k].e[2]) && (j==bm[k].e[1] || j==bm[k].e[2]))) continue;
                    if (bm[k].e[0]==1 && i!=bm[k].e[1] && j!=bm[k].e[1]) continue;
                    upmax(maxatk,bm[k].atk-sm[i].atk-sm[j].atk);
                }
                add(i,j,maxatk);
            }
        rep(i,1,n)
            if (sm[i].c==0){
                add(S,i,0);
            }
            else{
                add(i,T,0);
            }
        while (spfa()){}
        rep(i,1,n) ans+=sm[i].atk;
        printf("%d\n",ans);
    }
}
