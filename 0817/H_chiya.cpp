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

int n,now,ans,ANS,f[500];
struct node{
    int u,v;
}a[500];

bool cmp(node a,node b){
    return a.v<b.v;
}

int main(){
//freopen("H.in","r",stdin);
    while(scanf("%d",&n),n){
        rep(i,1,n) scanf("%d%d",&a[i].u,&a[i].v);
        rep(i,1,n) f[i]=1;
        sort(a+1,a+n+1,cmp);
        ANS=0;
        rep(bg,0,4){
            ans=0;
            rep(i,1,n) f[i]=1;
            for(int i=bg;i<=1000;i+=5){
                rep(j,1,n) if (f[j] && a[j].u<=i &&a[j].v>i){
                    f[j]=0;
                    ans++;
                    break;
                }
            }
            upmax(ANS,ans);
        }
        printf("%d\n",ANS);
    }
}
