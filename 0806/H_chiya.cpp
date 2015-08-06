#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
//#include<iostream>
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

int cas,n,ans,top,i,qa[120000];
struct node{
    int l,r,p;
    bool operator<(const node &u)const{
        return r>u.r;
    }
}tmp,a[120000];
priority_queue<node> q;

bool cmp(node a,node b){
    return a.l<b.l;
}

int main(){
freopen("H.in","r",stdin);
    scanf("%d",&cas);
    while (cas--){
        scanf("%d",&n);
        rep(i,1,n) scanf("%d",&a[i].l);
        rep(i,1,n) scanf("%d",&a[i].r);
        rep(i,1,n) a[i].p=i;
        sort(a+1,a+n+1,cmp);
        ans=0; top=0;
        for(i=1;i<=n && a[i].l<=ans;i++) q.push(a[i]);
        while (!q.empty()){
            tmp=q.top();
            q.pop();
            qa[++top]=tmp.p;
            if (tmp.r>=ans){
                ans++;
                for(;i<=n && a[i].l<=ans;i++) q.push(a[i]);
            }
        }
        for(;i<=n;i++) qa[++top]=a[i].p;
        printf("%d\n",ans);
        rep(i,1,top-1) printf("%d ",qa[i]);
        printf("%d\n",qa[top]);
    }
}
