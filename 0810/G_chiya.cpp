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

int flag,n,g[10],tmp,u,v,b[120000],c[120000],X1,X2,DX,Y1,Y2,DY;
struct node{
    int x,y;
}a[120000];

int gcd(int a,int b){ if (!b) return a; return gcd(b,a%b);}
bool cmp(node a,node b){return a.x<b.x || (a.x==b.x && a.y<b.y);}

void calc(int u,int v,int ca){
    if (flag) return;
    int X1,X2,DX,Y1,Y2,DY,now;
    rep(i,1,n) b[i]=0;
    if (!ca){
        X1=a[u].x; DX=a[v].x-a[u].x;
        now=X1;
        rep(i,1,n) if (a[i].x==now){
            b[i]=1;
            now+=DX;
            X2=a[i].x;
        }
        int m=0;
        rep(i,1,n) if (!b[i]) c[++m]=a[i].y;
        if (m==0){
            Y1=a[1].y;
            Y2=a[2].y;
            if (Y1>Y2) swap(Y1,Y2);
            DY=Y2-Y1;
        }
        else if (m==1){
            Y1=c[1];
            rep(i,1,n) if (a[i].y==Y1) b[i]=1;
            if (a[1].y!=Y1) Y2=a[1].y;
            else Y2=a[2].y;
            if (Y1>Y2) swap(Y1,Y2);
            DY=Y2-Y1;
        }
        else{
            Y1=c[1]; Y2=c[m];
            DY=abs(c[2]-c[1]);
            rep(i,3,m) DY=gcd(DY,abs(c[i]-c[i-1]));
            if (Y1<Y2){
                now=Y1;
                rep(i,1,n) if(a[i].y==now) b[i]=1,now+=DY;
            }
            else{
                now=Y1;
                rep(i,1,n) if(a[i].y==now) b[i]=1,now-=DY;
                swap(Y1,Y2);
            }
        }
        int flag2=1;
        rep(i,1,n) flag2&=b[i];
        if (flag2){
            printf("%d %d %d %d %d %d\n",X1,X2,DX,Y1,Y2,DY);
            flag=1;
        }
    }
//================================================================================
    else{
        Y1=a[u].y; DY=a[v].y-a[u].y;
        now=Y1;
        rep(i,1,n) if (a[i].y==now){
            b[i]=1;
            now+=DY;
            Y2=a[i].y;
        }
        int m=0;
        rep(i,1,n) if (!b[i]) c[++m]=a[i].x;
        if (m==0){
            X1=a[1].x;
            X2=a[2].x;
            DX=X2-X1;
        }
        else if (m==1){
            X1=c[1];
            rep(i,1,n) if (a[i].x==X1) b[i]=1;
            if (a[1].x!=X1) X2=a[1].x;
            else X2=a[2].x;
            if (X1>X2) swap(X1,X2);
            DX=X2-X1;
        }
        else{
            X1=c[1]; X2=c[m];
            DX=c[2]-c[1];
            rep(i,3,m) DX=gcd(DX,c[i]-c[i-1]);
            now=X1;
            rep(i,1,n) if (a[i].x==now) b[i]=1,now+=DX;
        }
        int flag2=1;
        rep(i,1,n) flag2&=b[i];
        if (flag2){
            if (Y1>Y2){
                swap(Y1,Y2);
                DY=-DY;
            }
            printf("%d %d %d %d %d %d\n",X1,X2,DX,Y1,Y2,DY);
            flag=1;
        }
    }
}

int main(){
freopen("grid.in","r",stdin);
freopen("grid.out","w",stdout);
    scanf("%d",&n);
    rep(i,1,n) scanf("%d%d",&a[i].x,&a[i].y);
    sort(a+1,a+n+1,cmp);

    if (a[1].x==a[2].x){
        X1=a[1].x-1; X2=X1+2; DX=2;
        Y1=a[1].y; Y2=a[n].y; DY=a[2].y-a[1].y;
        printf("%d %d %d %d %d %d\n",X1,X2,DX,Y1,Y2,DY);
        return 0;
    }
    else if (a[1].y==a[2].y){
        Y1=a[1].y-1; Y2=Y1+2; DY=2;
        X1=a[1].x; X2=a[n].x; DX=a[2].x-a[1].x;
        printf("%d %d %d %d %d %d\n",X1,X2,DX,Y1,Y2,DY);
        return 0;
    }

    for(g[1]=0;g[1]<=1;g[1]++)
    for(g[2]=0;g[2]<=1;g[2]++)
    for(g[3]=0;g[3]<=1;g[3]++){
        tmp=g[1]+g[2]+g[3];
        if (tmp>=2){
            rep(i,1,3) if (g[i]) {u=i; break;}
            rep(i,u+1,3) if (g[i]) {v=i; break;}
            calc(u,v,0);
        }
        else{
            rep(i,1,3) if (!g[i]) {u=i; break;}
            rep(i,u+1,3) if (!g[i]) {v=i; break;}
            calc(u,v,1);
        }
    }
}
