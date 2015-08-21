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

#define left p*2,l,m
#define right p*2+1,m+1,r

const int N=120;
const int M=6000;
const int oo=1000000000;
int ANS,n,m,F[N][M],T[N][M],d[N][M],s[8*M],mi[8*M];

void build(int p,int l,int r){
    s[p]=-1;
    mi[p]=oo;
    if (l==r) return;
    int m=l+r>>1;
    build(left);
    build(right);
}

void pass(int p){
    if (s[p]!=-1){
        upmin(mi[p],s[p]);
        if (s[p*2]==-1 || s[p*2]>s[p]) s[p*2]=s[p];
        if (s[p*2+1]==-1 || s[p*2+1]>s[p]) s[p*2+1]=s[p];
        s[p]=-1;
    }
}

void ins(int p,int l,int r,int a,int b,int c){
    pass(p);
    upmin(mi[p],c);
    if (l==a && r==b){
        s[p]=c;
        return;
    }
    int m=l+r>>1;
    if (b<=m) ins(left,a,b,c);
    else if (a>m) ins(right,a,b,c);
    else{
        ins(left,a,m,c);
        ins(right,m+1,b,c);
    }
}

int fnd(int p,int l,int r,int a,int b){
    pass(p);
    if (l==a && r==b) return mi[p];
    int m=l+r>>1;
    if (b<=m) return fnd(left,a,b);
    if (a>m) return fnd(right,a,b);
    return min(fnd(left,a,m),fnd(right,m+1,b));
}

int main(){
//freopen("I.in","r",stdin);
    while(scanf("%d%d",&n,&m),n&&m){
        rep(i,1,n) rep(j,1,m) scanf("%d",&T[i][j]);
        rep(i,1,n) rep(j,1,m) scanf("%d",&F[i][j]);
        rep(j,1,m) d[1][j]=T[1][j];
        rep(i,2,n){
            build(1,1,m);
            rep(j,1,m) ins(1,1,m,max(1,j-F[i-1][j]),min(m,j+F[i-1][j]),d[i-1][j]);
            rep(j,1,m) d[i][j]=fnd(1,1,m,max(1,j-F[i][j]),min(m,j+F[i][j]))+T[i][j];
        }
        ANS=d[n][1];
        rep(j,1,m) upmin(ANS,d[n][j]);
        printf("%d\n",ANS);
    }
}
