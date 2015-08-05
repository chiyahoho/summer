#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#define rep(i,a,b) for(int i=a,_b=b;i<=_b;i++)
#define per(i,a,b) for(int i=a,_b=b;i>=_b;i--)
#define For(i,b) for(int i=0,_b=b;i<_b;i++)
#define upmax(a,b) if ((a)<(b)) (a)=(b)
#define upmin(a,b) if ((a)>(b)) (a)=(b)
using namespace std;
const int N = 2000000;
const int sz = 26;
string A,B;
int cas,u,v,nn,ru[N],top,qq[N];
vector<int> e[N];
unsigned long long atot,ans,cntA[sz],cntB[sz],dp[N];

struct SAM{
	struct node{
		int ch[sz];
		int f, len, u;
		void init() {
			f = -1, len = 0;
			memset(ch,-1,sizeof ch);
		}
	};
	node a[N<<1];
	int tot, last;
	void init() {
		tot = 0, last = 0;
		a[tot++].init();
	}
	int newnode() {
		a[tot].init();
		return tot++;
	}
	void add(int c,int v) {
		int u, p, q, r;
		p = newnode();
		a[p].u = v;
		u = last;
		a[p].len = a[last].len + 1;
		for ( ; u != -1 && a[u].ch[c] == -1; u = a[u].f) a[u].ch[c] = p;
		if (u == -1) a[p].f = 0;
		else {
			q = a[u].ch[c];
			if (a[u].len + 1 == a[q].len) a[p].f = q;
			else {
				r = newnode();
				a[r] = a[q];
				a[r].len = a[u].len + 1;
				a[p].f = a[q].f = r;
				for ( ; u != -1 && a[u].ch[c] == q; u = a[u].f) a[u].ch[c] = r;
			}
		}
		last = p;
	}
} sam;

int main() {
ios::sync_with_stdio(false);
//freopen("A.in","r",stdin);
	cin>>cas;
	while(cas--){
        sam.init();
        cin>>A>>B;
        For(i,sz) cntA[i]=cntB[i]=0;
        atot=0;

        For(i,A.size()) sam.add(A[i]-'a',i);
        nn=sam.tot;
        For(u,nn) dp[u]=0; dp[0]=1;
        For(u,nn) For(i,sz) if (sam.a[u].ch[i] != -1){
            v=sam.a[u].ch[i];
            ru[v]++;
        }
        qq[top=1]=0;
        while(top){
            u=qq[top--];
            For(i,sz) if (sam.a[u].ch[i] != -1){
                v=sam.a[u].ch[i];
                ru[v]--;
                cntA[i]+=dp[u];
                dp[v]+=dp[u];
                atot+=dp[u];
                if (!ru[v]) qq[++top]=v;
            }
        }
        ans=atot;

        sam.init();
        For(i,B.size()) sam.add(B[i]-'a',i);
        nn=sam.tot;
        For(u,nn) e[u].clear();
        For(u,nn) dp[u]=1;
        For(u,nn) For(i,sz) if (sam.a[u].ch[i] != -1){
            v=sam.a[u].ch[i];
            ru[u]++;
            e[v].push_back(u);
        }
        top=0;
        For(u,nn) if (!ru[u]) qq[++top]=u;
        while(top){
            u=qq[top--];
            For(i,e[u].size()){
                v=e[u][i];
                ru[v]--;
                dp[v]+=dp[u];
                if (!ru[v]) qq[++top]=v;
            }
        }
        ans+=dp[0];
        For(i,sz) cntB[i]=dp[sam.a[0].ch[i]];
        For(i,sz) ans+=(atot-cntA[i])*cntB[i];
        cout<<ans<<endl;
	}
}
