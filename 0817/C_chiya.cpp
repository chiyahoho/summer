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

const int N=120;
const double eps=1e-8;
int n,m,upper,lower;
double D,sinP,cosP,ans,s[N];

int is(double a){
    if (a>eps) return 1;
    if (a<-eps) return -1;
    return 0;
}

struct point{
    double x,y,z;
    point(){}
    point(double x,double y,double z):x(x),y(y),z(z){}
    void read(){
        scanf("%lf%lf%lf",&x,&y,&z);
    }
    double len(){
        return sqrt(x*x+y*y+z*z);
    }
    point operator *(const double &a)const{
        return point(x*a,y*a,z*a);
    }
    point operator +(const point &a)const{
        return point(x+a.x,y+a.y,z+a.z);
    }
    point operator -(const point &a)const{
        return point(x-a.x,y-a.y,z-a.z);
    }
    double operator *(const point &a)const{
        return x*a.y - a.x*y;
    }
    bool operator <(const point &a)const{
        return x+eps<a.x || (!is(x-a.x) && y+eps<a.y);
    }
}PL,P1,p[N],bao[N];

void hull(point a,point b,int l,int r){
    int x=l;
    rep(k,l,r) if (s[x]+eps<s[k] || (is(s[x]-s[k])==0 && p[x]<p[k])) x=k;
    point y=p[x];
    int i=l-1,j=r+1;
    rep(k,l,r){
        s[i+1]=(y-a)*(p[k]-a);
        if (is(s[i+1])==1) swap(p[++i],p[k]);
    }
    per(k,r,l){
        s[j-1]=(b-y)*(p[k]-y);
        if (is(s[j-1])==1) swap(p[--j],p[k]);
    }
    if (l<=i) hull(a,y,l,i);
    bao[++m]=y;
    if (j<=r) hull(y,b,j,r);
}

void tubao(){
    rep(i,2,n) if (p[i]<p[1]) swap(p[1],p[i]);
    rep(i,0,n+1) s[i]=0;
    bao[m=1]=p[1];
    hull(p[1],p[1],2,n);
    bao[m+1]=bao[1];
    ans=0;
    rep(i,1,m) ans+=bao[i]*bao[i+1];
    if (is(ans)==-1) ans=-ans;
    printf("%.2f\n",ans/2);
}

int main(){
    while(1){
        PL.read();
        scanf("%lf",&D);
        if (!is(PL.x) && !is(PL.y) && !is(PL.z)) break;
        scanf("%d",&n);
        rep(i,1,n) p[i].read();
        p[0].read();
        P1=point(0,0,0);
        if (is(D)){
            if (is(PL.x)) P1.x=D/PL.x;
            else if (is(PL.y)) P1.y=D/PL.y;
            else if (is(PL.z)) P1.z=D/PL.z;
            rep(i,0,n) p[i]=p[i]-P1;
        }

        double len=PL.len();
        PL = PL * (1/len);
        if (is(PL.x) || is(PL.y)){
            cosP = PL.y / sqrt(PL.x * PL.x + PL.y * PL.y);
            sinP = PL.x / sqrt(PL.x * PL.x + PL.y * PL.y);
            rep(i,0,n){
                P1.x = p[i].x * cosP - p[i].y * sinP;
                P1.y = p[i].x * sinP + p[i].y * cosP;
                P1.z = p[i].z;
                p[i] = P1;
            }
            cosP = PL.z / PL.len();
            sinP = sqrt(1 - cosP * cosP);
            rep(i,0,n){
                P1.x = p[i].x;
                P1.y = p[i].y * cosP - p[i].z * sinP;
                P1.z = p[i].y * sinP + p[i].z * cosP;
                p[i] = P1;
            }
        }

        upper=lower=0;
        rep(i,1,n)
            if (is(p[0].z)==is(p[i].z-p[0].z) || is(p[i].z-p[0].z)==0) upper=1;
            else lower=1;
        if (!lower) printf("0.00\n");
        else if (upper && lower) printf("Infi\n");
        else {
            rep(i,1,n) p[i]=(p[i] - p[0]) * (p[0].z / (p[0].z - p[i].z)) + p[0];
            tubao();
        }
    }
}
