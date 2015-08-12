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

int n,m,x,u,usd[1200];
vector<int> e[1200],ans;
vector<pair<int,int> > an;
set<int> fa[1200],fa2[1200],st;

void dfs(int u,int uu){
    For(i,e[u].size()){
        int v=e[u][i];
        if (v<=m) fa[v].insert(uu);
        dfs(v,uu);
    }
}

void dfs2(int u,int uu){
    For(i,e[u].size()){
        int v=e[u][i];
        if (usd[v]) continue;
        if (st.find(v)!=st.end()) continue;
        st.insert(v);
        if (v<=m) fa2[v].insert(uu);
        dfs(v,uu);
    }
}

int main(){
freopen("hospital.in","r",stdin);
freopen("hospital.out","w",stdout);
    cin>>n>>m;
    rep(i,1,m){
        cin>>x;
        while(x--){
            cin>>u;
            e[u].push_back(i);
        }
    }
    rep(u,m+1,n) dfs(u,u);
    rep(i,1,m) if (!fa[i].size()) ans.push_back(i);
    cout<<ans.size()<<endl;
    For(i,ans.size()-1) cout<<ans[i]<<' ';
    cout<<ans[ans.size()-1]<<endl;

    rep(i,1,m) if (fa[i].size()==1){
        int uu=*(fa[i].begin());
        an.push_back(make_pair(i,uu));
        usd[i]=1; usd[uu]=1;
        rep(u,1,n) fa2[u].clear();
        rep(u,m+1,n) if (!usd[u]) {st.clear(); dfs2(u,u);}
        rep(j,1,m) if (i<j && fa[j].size()>0 && fa2[j].size()==0) an.push_back(make_pair(i,j));
        usd[i]=0; usd[uu]=0;
    }

    cout<<an.size()<<endl;
    if (an.size()<=10000){
        For(i,an.size()) cout<<an[i].first<<' '<<an[i].second<<endl;
    }
}
