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

const int N=230000;
int n,m,l,r,ca;
double s[8*N],len[8*N],aa,bb,cc,ck,sk,k;
char S[50];

struct point{
    double x,y,z;
    point (){}
    point (double x,double y,double z):x(x),y(y),z(z){}
    point operator -(const point &b)const{
        return point(x-b.x, y-b.y, z-b.z);
    }
    double len(){
        return sqrt(x*x + y*y +z*z);
    }
    void read(){
        scanf("%lf%lf%lf",&x,&y,&z);
    }
    void write(){
        printf("%.6f %.6f %.6f\n",x,y,z);
    }
}P,P2,a[N];

struct matrix{
    double a[4][4];
    matrix (){}
    matrix (double a00, double a01, double a02, double a03,
            double a10, double a11, double a12, double a13, 
            double a20, double a21, double a22, double a23, 
            double a30, double a31, double a32, double a33){
        a[0][0]=a00; a[0][1]=a01; a[0][2]=a02; a[0][3]=a03; 
        a[1][0]=a10; a[1][1]=a11; a[1][2]=a12; a[1][3]=a13; 
        a[2][0]=a20; a[2][1]=a21; a[2][2]=a22; a[2][3]=a23; 
        a[3][0]=a30; a[3][1]=a31; a[3][2]=a32; a[3][3]=a33; 
    }
    matrix operator *(const matrix &b)const{
        matrix c;
        For(i,4) For(j,4) c.a[i][j]=0;
        For(i,4) For(j,4) For(k,4) c.a[i][j]+=a[i][k]*b.a[k][j];
        return c;
    }
}ini,c,tr[8*N];

void pass1(int p,int l,int r){
    if (l==r){
        point P;
        P.x= a[l].x*tr[p].a[0][0] + a[l].y*tr[p].a[1][0] + a[l].z*tr[p].a[2][0] + tr[p].a[3][0];
        P.y= a[l].x*tr[p].a[0][1] + a[l].y*tr[p].a[1][1] + a[l].z*tr[p].a[2][1] + tr[p].a[3][1];
        P.z= a[l].x*tr[p].a[0][2] + a[l].y*tr[p].a[1][2] + a[l].z*tr[p].a[2][2] + tr[p].a[3][2];
        a[l]=P;
    }
    else{
        tr[p*2]=tr[p*2]*tr[p];
        tr[p*2+1]=tr[p*2+1]*tr[p];
    }
    tr[p]=ini;
}

void pass2(int p){
    s[p*2]*=s[p];
    s[p*2+1]*=s[p];
    len[p]*=s[p];
    s[p]=1;
}

void ins1(int p,int l,int r,int a,int b,matrix c){
    pass1(p,l,r);
    if (l==a && r==b){
        tr[p]=tr[p]*c;
        return;
    }
    int m=l+r>>1;
    if (b<=m) ins1(p*2,l,m,a,b,c);
    else if (a>m) ins1(p*2+1,m+1,r,a,b,c);
    else{
        ins1(p*2,l,m,a,m,c);
        ins1(p*2+1,m+1,r,m+1,b,c);
    }
}

void ins2(int p,int l,int r,int a,double b){
    pass2(p);
    if (l==r){
        len[p]=b;
        return;
    }
    int m=l+r>>1;
    if (a<=m) ins2(p*2,l,m,a,b);
    else ins2(p*2+1,m+1,r,a,b);
    pass2(p*2); pass2(p*2+1);
    len[p]=len[p*2]+len[p*2+1];
}

void mul(int p,int l,int r,int a,int b,double c){
    pass2(p);
    if (l==a && r==b){
        s[p]*=c;
        return;
    }
    int m=l+r>>1;
    if (b<=m) mul(p*2,l,m,a,b,c);
    else if (a>m) mul(p*2+1,m+1,r,a,b,c);
    else{
        mul(p*2,l,m,a,m,c);
        mul(p*2+1,m+1,r,m+1,b,c);
    }
    pass2(p*2); pass2(p*2+1);
    len[p]=len[p*2]+len[p*2+1];
}

void build1(int p,int l,int r){
    tr[p]=ini;
    if (l==r) return;
    int m=l+r>>1;
    build1(p*2,l,m);
    build1(p*2+1,m+1,r);
}

void build2(int p,int l,int r){
    s[p]=1;
    if (l==r){
        len[p]=(a[l+1]-a[l]).len();
        return;
    }
    int m=l+r>>1;
    build2(p*2,l,m);
    build2(p*2+1,m+1,r);
    len[p]=len[p*2]+len[p*2+1];
}

void getP(int p,int l,int r,int a){
    pass1(p,l,r);
    if (l==r) return;
    int m=l+r>>1;
    if (a<=m) getP(p*2,l,m,a);
    else getP(p*2+1,m+1,r,a);
}

double fnd(int p,int l,int r,int a,int b){
    pass2(p);
    if (l==a && r==b) return len[p];
    int m=l+r>>1;
    if (b<=m) return fnd(p*2,l,m,a,b);
    if (a>m) return fnd(p*2+1,m+1,r,a,b);
    return fnd(p*2,l,m,a,m)+fnd(p*2+1,m+1,r,m+1,b);
}

void cng(int l,int r){
    if (l>1){
        getP(1,1,n,l-1);
        getP(1,1,n,l);
        ins2(1,1,n-1,l-1,(a[l]-a[l-1]).len());
    }
    if (r<n){
        getP(1,1,n,r);
        getP(1,1,n,r+1);
        ins2(1,1,n-1,r,(a[r+1]-a[r]).len());
    }
}

void predo(){
    For(i,4) For(j,4) ini.a[i][j]=(i==j);
    printf("Case #%d:\n",++ca);
}

int main(){
freopen("1009.in","r",stdin);
freopen("09.out","w",stdout);
    while(scanf("%d%d",&n,&m),n){
        predo();
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
                aa=P2.x/P2.len(); bb=P2.y/P2.len(); cc=P2.z/P2.len();
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
                getP(1,1,n,l);
                a[l].write();
            }
            else if (S[0]=='L'){
                scanf("%d%d",&l,&r);
                printf("%.6f\n",fnd(1,1,n-1,l,r-1));
            }
        }
    }
}
