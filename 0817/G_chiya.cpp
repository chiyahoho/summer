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

const int N=12000;
int ru[N],n,top,m,u,v,K,q[N];
double price[N],sz[N],ans,l;
struct node{
    double l;
    int v;
    node(){}
    node(int v,double l):l(l),v(v){}
};
vector<node> e[N];

int main(){
//freopen("G.in","r",stdin);
    while(scanf("%d",&n),n){
        rep(i,1,n){
            ru[i]=0;
            e[i].clear();
        }

        rep(i,1,n){
            scanf("%lf%lf",&price[i],&sz[i]);
        }
        scanf("%d",&m);
        rep(i,1,m){
            scanf("%d",&K);
            scanf("%d",&v);
            while(--K){
                scanf("%lf%d",&l,&u);
                e[u].push_back(node(v,l));
                ru[v]++;
                v=u;
            }
        }
        top=0;
        rep(i,1,n) if (!ru[i]) q[++top]=i;
        while(top){
            u=q[top--];
            For(i,e[u].size()){
                v=e[u][i].v;
                l=e[u][i].l;
                upmax(price[v],price[u]*l);
                if ((--ru[v])==0){
                    q[++top]=v;
                }
            }
        }
        ans=0;
        rep(i,1,n) ans+=price[i]*sz[i];
        printf("%.2f\n",ans);
    }
}
