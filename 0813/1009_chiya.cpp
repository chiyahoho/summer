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

struct point{
    double x,y,z;
}P;

void ins2(int p,int l,int r,int a,double b){
    pass2(p);
    if (l==r){
        len[p]=b;
        return;
    }
    int m=l+r>>1;
    if (a<=m) ins2(p*2,l,m,a,b);
    else ins2(p*2+1,m+1,r,a,b);
    pass(p*2); pass(p*2+1);
    len[p]=len[p*2]+len[p*2+1];
}

void cng(int l,int r){
    point p1,p2;
    if (l>1){
        p1=getP(1,1,n,l-1);
        p2=getP(1,1,n,l);
        ins2(1,1,n-1,l-1,(p2-p1).len());
    }
    if (r<n){
        p1=getP(1,1,n,r);
        p2=getP(1,1,n,r+1);
        ins2(1,1,n-1,r,(p2-p1).len());
    }
}

int main(){
freopen(".in","r",stdin);
    while(scanf("%d%d",&n,&m),n){
        rep(i,1,n) a[i].read();
        build1(1,1,n);
        build2(1,1,n-1);
        rep(i,1,m){
            scanf("%s",S);
            if (S[0]=='T'){
                scanf("%d%d",&l,&r);
                P.read();
                c=matrix(1,0,0,0,
                         0,1,0,0,
                         0,0,1,0,
                         P.x,P.y,P.z,1);
                ins1(1,1,n,l,r,c);
                cng(l,r);
            }
            else if (S[0]=='S'){
                scanf("%d%d",&l,&r);
                P.read();
                scanf("%lf",&k);
                c=matrix(k,0,0,0,
                         0,k,0,0,
                         0,0,k,0,
                         (1-k)*P.x,(1-k)*P.y,(1-k)*P.z,1);
                ins1(1,1,n,l,r,c);
                cng(l,r);
                if (l<r) mul(1,1,n-1,l,r-1,k);
            }
            else if (S[0]=='R'){
                scanf("%d%d",&l,&r);
                P.read();
                P2.read();
                aa=P2.x; bb=P2.y; cc=P2.z;
                scanf("%lf",&k);
                ck=cos(k); sk=sin(k);
                c=matrix(1,0,0,0,
                         0,1,0,0,
                         0,0,1,0,
                         -P.x,-P.y,-P.z,1);
                c=c*matrix( aa*aa*(1-ck)+ck, aa*bb*(1-ck)+cc*sk, aa*cc*(1-ck)-bb*sk, 0,
                            aa*bb*(1-ck)-cc*sk, bb*bb*(1-ck)+ck, bb*cc*(1-ck)+aa*sk, 0,
                            aa*cc*(1-ck)+bb*sk, bb*cc*(1-ck)-aa*sk, cc*cc*(1-ck)+ck, 0,
                            0, 0, 0, 1);
                c=c*matrix( 1,0,0,0,
                            0,1,0,0,
                            0,0,1,0,
                            P.x,P.y,P.z,1);
                ins1(1,1,n,l,r,c);
                cng(l,r);
            }
            else if (S[0]=='C'){
                scanf("%d",&l);
                P=getP(1,1,n,l);
                P.write();
            }
            else if (S[0]=='L'){
                scanf("%d%d",&l,&r);
                printf("%.6f\n",fnd(1,1,n-1,l,r-1));
            }
        }
    }
}
