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

int cas,n,m,ans;
double s[60000];
const double eps=1e-8;
int is(double a){return a<-eps?-1 : a>eps;}
struct point{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
    void read(){scanf("%lf%lf",&x,&y);}
    point operator +(const point &a)const{return point(x+a.x,y+a.y);}
    point operator -(const point &a)const{return point(x-a.x,y-a.y);}
    point operator *(const double &a)const{return point(x*a,y*a);}
    point operator /(const double &a)const{return point(x/a,y/a);}
    double operator *(const point &a)const{return x*a.y-a.x*y;}
    double operator %(const point &a)const{return x*a.x+y*a.y;}
    bool operator <(const point &a)const{return is(x-a.x)<0 || (is(x-a.x)==0 && is(y-a.y)<0);}
}root,p[60000],bao[60000];

void getroot(){
    root=point(0,0);
    double area=0;
    rep(i,1,n) area+=p[i+1]*p[i];
    area=area/2;
    if (is(area)==0) return;
    rep(i,1,n) root=root+((p[i]+p[i+1])*(p[i+1]*p[i]));
    root=(root/area)/6;
}

void hull(point a,point b,int l,int r){
    int x=l;
    rep(k,l,r) if (is(s[x]-s[k])<0 || (is(s[x]-s[k])==0 && p[x]<p[k])) x=k;
    point y=p[x];
    int i=l-1,j=r+1;
    rep(k,l,r) if (is(s[i+1]=( (y-a)*(p[k]-a) ))>0) swap(p[++i],p[k]);
    per(k,r,l) if (is(s[j-1]=( (b-y)*(p[k]-y) ))>0) swap(p[--j],p[k]);
    if (l<=i) hull(a,y,l,i);
    bao[++m]=y;
    if (j<=r) hull(y,b,j,r);
}

int main(){
//freopen("F.in","r",stdin);
    scanf("%d",&cas);
    while(cas--){
        scanf("%d",&n);
        rep(i,0,n+1) s[i]=0;
        rep(i,1,n) p[i].read();
        p[n+1]=p[1];
        getroot();
        rep(i,2,n) if (p[i]<p[1]) swap(p[i],p[1]);
        bao[m=1]=p[1];
        hull(p[1],p[1],2,n);
        bao[m+1]=bao[1];
        ans=0;
        rep(i,1,m) if (is((bao[i]-bao[i+1])%(root-bao[i+1]))>0 && is((bao[i+1]-bao[i])%(root-bao[i]))>0) ans++;
        printf("%d\n",ans);
    }
}
