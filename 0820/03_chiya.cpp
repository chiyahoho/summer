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

int cas,N,n,m,ans,j,f[300000];
double s[300000];
const double eps=1e-8;

int is(double a){
    return a<-eps?-1 : a>eps;
}
struct point{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
    void read(){cin>>x>>y;}
    void write(){cout<<x<<' '<<y<<endl;}
    bool operator <(const point a)const{return is(x-a.x)<0 || (is(x-a.x)==0 && is(y-a.y)<0);}
    point operator +(const point a)const{return point(x+a.x,y+a.y);}
    point operator -(const point a)const{return point(x-a.x,y-a.y);}
    double operator *(const point a)const{return x*a.y-a.x*y;}
    point operator *(const double a)const{return point(x*a,y*a);}
}O,bao[300000],BAO[600000],p[300000];

void hull(point a,point b,int l,int r){
    int x=l;
    rep(k,l,r) if (is(s[x]-s[k])<0 || (is(s[x]-s[k])==0 && p[x]<p[k])) x=k;
    point y=p[x];
    int i=l-1,j=r+1;
    rep(k,l,r) if (is(s[i+1]=(y-a)*(p[k]-a))>0) swap(p[++i],p[k]);
    per(k,r,l) if (is(s[j-1]=(b-y)*(p[k]-y))>0) swap(p[--j],p[k]);
    if (j<=r) hull(y,b,j,r);
    bao[++m]=y;
    if (l<=i) hull(a,y,l,i);
}

int main(){
//freopen("03.in","r",stdin);
//freopen("03.out","w",stdout);
ios::sync_with_stdio(false);
    cin>>cas;
    while(cas--){
        cin>>N;
        rep(i,1,N) BAO[i].read(),BAO[i+N]=BAO[i];
        cin>>n;
        rep(i,0,n) s[i]=0;
        rep(i,1,n) p[i].read();
        rep(i,2,n) if (p[i]<p[1]) swap(p[i],p[1]);
        bao[m=1]=p[1];
        hull(p[1],p[1],2,n);
        O=point(0,0);
        rep(i,1,m) O=O+bao[i];
        O=O*(1.0/m);
        //O.write();
        j=1;
        rep(i,1,m){
            while(is((bao[i]-O)*(BAO[j]-O)) * is((bao[i]-O)*(BAO[j+1]-O)) ==1 || is((BAO[j+1]-BAO[j])*( ((bao[i]-O)*10000000000000.0+O) -BAO[j])) * is((BAO[j+1]-BAO[j])*(O-BAO[j])) == 1) j++;
            f[(j-1)%N+1]=f[j%N+1]=1;
        }

        cout<<"Yes"<<endl;
        ans=0;
        rep(i,1,N) if (f[i]) ans++;
        cout<<ans<<endl;
        rep(i,1,N) if (f[i]){
            f[i]=0;
            cout<<i;
            if (--ans) cout<<' ';
            else cout<<endl;
        }
    }
}
