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

int cas,n,m,u,v,L,R,now,y,vis[120000],h[120000],d[120000],pre[120000];
struct edge{
    int u,v,l,n;
}e[120000];
set<int> st;
set<int>::iterator it;

void work(int u){
    for(int y=h[u];y;y=e[y].n){
        int v=e[y].v;
        if (vis[v]) continue;
        vis[v]=1;
        st.insert(v);
        pre[v]=y;
    }
}

int main(){
freopen("06.in","r",stdin);
ios::sync_with_stdio(false);
    cin>>cas;
    while(cas--){
        cin>>n>>m;
        rep(i,1,n) vis[i]=h[i]=0;
        st.clear();

        rep(i,1,m){
            cin>>u>>v;
            e[i].v=v;
            e[i].u=u;
            e[i].l=n;
            e[i].n=h[u];
            h[u]=i;
        }
        L=2; R=n;
        d[1]=0; vis[1]=1; now=0;
        work(1);
        while (st.size()){
            now++;
            it=st.begin();
            if (*it==L){
                u=L++;
                st.erase(u);
            }
            else {
                u=R--;
                st.erase(u);
            }
            d[u]=now;
            y=pre[u];
            e[y].l=now-d[e[y].u];
            work(u);
        }
        rep(i,1,m) cout<<e[i].l<<endl;
    }
}
