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

const int N=12000;
const int mo=1000000007;
int cas,n,P,u,v,H,maxw,maxdp,uu,vv,m,len,m2,mm,top,fa[N],dp[N],vis[N],q[N],w[N],nt[N],qq[N];
ll ans;
vector<int> e[N];

void dfs(int u){
    For(i,e[u].size()){
        int v=e[u][i];
        if (v==fa[u] || vis[v]) continue;
        fa[v]=u;
        dp[v]=dp[u]+1;
        dfs(v);
    }
}

void dfs2(int u){
    For(i,e[u].size()){
        int v=e[u][i];
        if (dp[v]>=dp[vv]) vv=v;
        dfs2(v);
    }
}

void dfs3(int u){
    if (top>=dp[u] && q[m+dp[u]]>w[u]) return;
    if (top<dp[u] || q[m+dp[u]]<w[u]){
        top=dp[u];
        q[m+top]=w[u];
    }
    For(i,e[u].size()){
        int v=e[u][i];
        if (v==fa[u] || !vis[v]) continue;
        dfs3(v);
    }
}

bool cmp(int a,int b){
    return w[a]<w[b];
}

int comp(){
    if (m>mm) return 1;
    if (mm>m) return 0;
    rep(i,1,m){
        if (q[i]>qq[i]) return 1;
        if (qq[i]>q[i]) return 0;
    }
    return 1;
}

void work(int H){
    rep(i,1,n) vis[i]=0;
    fa[H]=0; dp[H]=1;
    dfs(H);
    uu=H;
    rep(i,1,n) if (dp[i]>dp[uu] && w[i]) uu=i;
    maxdp=dp[uu];
    m=0;
    rep(i,1,n) if (dp[i]==maxdp && w[i]) q[++m]=i;
    rep(j,1,maxdp-1){
        maxw=0; m2=0;
        rep(i,1,m) upmax(maxw,w[q[i]]);
        rep(i,1,m) if (w[q[i]]==maxw && !vis[q[i]]){
            vis[q[i]]=1;
            q[++m2]=q[i];
        }
        m=m2;
        rep(i,1,m) nt[fa[q[i]]]=q[i];
        rep(i,1,m) q[i]=fa[q[i]];
    }

    rep(i,1,n) vis[i]=0;
    uu=vv=H;
    rep(j,1,maxdp-1){
        uu=nt[uu];
        vis[uu]=1;
    }
    m=0;
    for(;uu!=H;uu=fa[uu]) q[++m]=w[uu];

    fa[H]=0; rep(i,1,n) dp[i]=0; dp[H]=1;
    dfs(H);
    maxdp=0;
    rep(i,1,n) upmax(maxdp,dp[i]);
    rep(i,1,n) vis[i]=0;
    rep(i,1,n) if (dp[i]==maxdp){
        for(vv=i;vv!=H && !vis[vv];vv=fa[vv]) vis[vv]=1;
    }

    top=0;
    dfs3(H);
    m+=top;
}

int main(){
//freopen("1001.in","r",stdin);
//freopen("01.out","w",stdout);
ios::sync_with_stdio(false);
    cin>>cas;
    rep(ca,1,cas){
        cin>>n>>P;
        rep(i,1,n) vis[i]=0;
        rep(i,1,n) e[i].clear();
        rep(i,1,n-1){
            cin>>u>>v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        rep(i,1,n) cin>>w[i];
        rep(i,1,n) sort(e[i].begin(),e[i].end(),cmp);
        fa[1]=0; dp[1]=1;
        dfs(1);
        uu=1;
        rep(i,1,n) if (dp[i]>dp[uu]) uu=i;
        fa[uu]=0; dp[uu]=1;
        dfs(uu);
        vv=1;
        rep(i,1,n) if (dp[i]>dp[vv]) vv=i;
        len=(dp[vv]-1)/2;
        while(len--) vv=fa[vv];
        int H2=fa[vv];

        work(vv);
        mm=m;
        rep(i,1,m) qq[i]=q[i];
        work(H2);

        int who=comp();
        if (!who){
            m=mm;
            rep(i,1,m) q[i]=qq[i];
        }

        ans=0;
        rep(i,1,m) ans = (ans * P + q[i]) % mo;
        cout<<"Case #"<<ca<<": "<<ans<<endl;
        rep(i,1,m-1) cout<<q[i]<<' ';
        cout<<q[m]<<endl;
    }
}

