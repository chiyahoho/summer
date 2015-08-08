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

struct node{
    int l,r;
    ll d;
    bool operator <(const node &a)const{
        return d>a.d;
    }
    node(int l,int r,ll d):l(l),r(r),d(d){}
};
set<int> st;
set<int>::iterator it,it2;
priority_queue<node> pq;
int cas,n,u,L[220000],R[220000];
ll C[220000],ans[220000];

int main(){
//freopen("I.in","r",stdin);
    scanf("%d",&cas);
    while (cas--){
        scanf("%d",&n);
        rep(i,1,n) scanf("%d",&L[i]);
        rep(i,1,n) scanf("%d",&R[i]);
        rep(i,1,n) scanf("%d",&C[i]);
        rep(i,1,n) ans[i]=-1;
        st.clear();
        rep(i,1,n) st.insert(i);
        while (!pq.empty()) pq.pop();
        pq.push(node(1,1,0));

        while (!pq.empty()){
            node tmp=pq.top();
            pq.pop();
            it=st.lower_bound(tmp.l); it2=st.upper_bound(tmp.r);
            for(;it!=it2;it++){
                u=*it;
                ans[u]=tmp.d;
                int L1=u+L[u],R1=u+R[u];
                if (R1>n) R1=n;
                if (L1<=R1) pq.push(node(L1,R1,ans[u]+C[u]));
                L1=u-R[u],R1=u-L[u];
                if (L1<1) L1=1;
                if (L1<=R1) pq.push(node(L1,R1,ans[u]+C[u]));
            }
            it=st.lower_bound(tmp.l);
            st.erase(it,it2);
        }
        rep(i,1,n-1) cout<<ans[i]<<' ';cout<<ans[n]<<endl;
    }
}
