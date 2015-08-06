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

int cas,n,uu,L[220000],R[220000],C[220000];
const ll oo=1ll<<62;
ll ans[220000],mi[2000000],ma[2000000],s[2000000];

void build(int p,int l,int r){
    s[p]=-1;
    if (l==r){
        if (l==1) mi[p]=ma[p]=0;
        else mi[p]=ma[p]=oo;
        return;
    }
    int m=l+r>>1;
    build(p*2,l,m);
    build(p*2+1,m+1,r);

    mi[p]=min(mi[p*2],mi[p*2+1]);
    ma[p]=max(ma[p*2],ma[p*2+1]);
}

inline void pass(int p){
    if (s[p]!=-1 && mi[p]!=-1){
        if (s[p*2]==-1 || s[p*2]>s[p]) s[p*2]=s[p];
        if (s[p*2+1]==-1 || s[p*2+1]>s[p]) s[p*2+1]=s[p];
        if (s[p]<mi[p]) mi[p]=s[p];
        if (s[p]<ma[p]) ma[p]=s[p];
        s[p]=-1;
    }
}

void fnd(int p,int l,int r){
    pass(p*2); pass(p*2+1);

    if (l==r){
        ans[l]=mi[p];
        mi[p]=ma[p]=-1;
        uu=l;
        return;
    }
    int m=l+r>>1;
    if (mi[p]==mi[p*2]) fnd(p*2,l,m);
    else fnd(p*2+1,m+1,r);

    if (mi[p*2]==-1 && mi[p*2+1]==-1) mi[p]=ma[p]=-1;
    else {
        mi[p]=oo;
        if (mi[p*2]!=-1 && mi[p*2]<mi[p]) mi[p]=mi[p*2];
        if (mi[p*2+1]!=-1 && mi[p*2+1]<mi[p]) mi[p]=mi[p*2+1];
        ma[p]=max(ma[p*2],ma[p*2+1]);
    }
}

void ins(int p,int l,int r,int a,int b,ll c){
    if (mi[p]==-1) return;
    pass(p);

    if (l==a && r==b){
        s[p]=c;
        pass(p);
        return;
    }
    int m=l+r>>1;
    if (b<=m) ins(p*2,l,m,a,b,c);
    else if (a>m) ins(p*2+1,m+1,r,a,b,c);
    else {
        ins(p*2,l,m,a,m,c);
        ins(p*2+1,m+1,r,m+1,b,c);
    }

    if (mi[p*2]==-1 && mi[p*2+1]==-1) mi[p]=ma[p]=-1;
    else {
        mi[p]=oo;
        if (mi[p*2]!=-1 && mi[p*2]<mi[p]) mi[p]=mi[p*2];
        if (mi[p*2+1]!=-1 && mi[p*2+1]<mi[p]) mi[p]=mi[p*2+1];
        ma[p]=max(ma[p*2],ma[p*2+1]);
    }
}


int main(){
//freopen("I.in","r",stdin);
    scanf("%d",&cas);
    while (cas--){
        scanf("%d",&n);
        rep(i,1,n) scanf("%d",&L[i]);
        rep(i,1,n) scanf("%d",&R[i]);
        rep(i,1,n) scanf("%d",&C[i]);
        build(1,1,n);
        //rep(i,1,9) cout<<mi[i]<<endl;
        rep(i,1,n){
            fnd(1,1,n);
            //cout<<i<<' '<<uu<<' '<<ans[uu]<<endl;
            int L1=uu+L[uu],R1=uu+R[uu];
            if (R1>n) R1=n;
            if (ans[uu]<oo && L1<=R1) ins(1,1,n,L1,R1,ans[uu]+C[uu]);
            //cout<<L1<<' '<<R1<<endl;

            L1=uu-R[uu],R1=uu-L[uu];
            if (L1<1) L1=1;
            if (ans[uu]<oo && L1<=R1) ins(1,1,n,L1,R1,ans[uu]+C[uu]);
            //cout<<L1<<' '<<R1<<endl;
        }
        rep(i,1,n) if (ans[i]==oo) ans[i]=-1;
        rep(i,1,n-1) printf("%d ",ans[i]);
        printf("%d\n",ans[n]);
    }
}
