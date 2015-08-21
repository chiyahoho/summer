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
#define It map<point,int>::iterator
using namespace std;
typedef long long ll;

int cas,n,m,d1,d2,ans;
char c1,c2,ch;
struct point{
    int x,y,z,f;
    void init(char c1,int d1,char c2,int d2){
        x=y=z=0,f=1;
        //cout<<c1<<d1<<c2<<d2<<endl;
        if (c1=='X') x=d1;
        if (c1=='Y') y=d1;
        if (c1=='Z') z=d1;
        if (c2=='X') x=d2;
        if (c2=='Y') y=d2;
        if (c2=='Z') z=d2;
        if (d1>n || d2>n || d1<1 || d2<1) f=0;
    }
    bool operator ==(const point &a)const{
        return x==a.x && y==a.y && z==a.z;
    }
    bool operator <(const point &a)const{
        return x<a.x || (x==a.x && y<a.y) || (x==a.x && y==a.y && z<a.z);
    }
}d,p[2000];
map<point,int> mp;

int jiao(point a,point b){
    int flag=0;
    if (a.x && a.x==b.x && (a.y*b.z>0 || a.z*b.y>0)) flag=1;
    if (a.y && a.y==b.y && (a.x*b.z>0 || a.z*b.x>0)) flag=1;
    if (a.z && a.z==b.z && (a.y*b.x>0 || a.x*b.y>0)) flag=1;
    d.x=max(a.x,b.x);
    d.y=max(a.y,b.y);
    d.z=max(a.z,b.z);
    return flag;
}

void ins(point d){
    if (mp.find(d)!=mp.end()) mp[d]++;
    else mp[d]=1;
}

int main(){
//freopen("C.in","r",stdin);
    scanf("%d",&cas);
    while(cas--){
        scanf("%d%d",&n,&m);
        mp.clear();
        rep(i,1,m){
            scanf("%c%c%c%d%c%c%c%d",&ch,&c1,&ch,&d1,&ch,&c2,&ch,&d2);
            p[i].init(c1,d1,c2,d2);
        }
        rep(i,2,m) if (p[i].f){
            rep(j,1,i-1) if (p[j].f && (p[i]==p[j])) {p[i].f=0;break;}
            if (!p[i].f)continue;
            rep(j,1,i-1) if (p[j].f && jiao(p[i],p[j])) ins(d);
        }
        ans=0;
        rep(i,1,m) if (p[i].f) ans+=n;
        for(It it=mp.begin();it!=mp.end();it++)
            if (it->second==1) ans--;
            else ans-=2;
        printf("%d\n",ans);
    }
}
