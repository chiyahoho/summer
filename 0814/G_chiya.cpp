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

int n,m,x,a[320000],s[320000];
char ch;
set<int> st;
struct tree{
    int mi,s;
}tr[5000000];

inline void pass(int p){
    if (tr[p].s!=0){
        tr[p].mi+=tr[p].s;
        tr[p*2].s+=tr[p].s;
        tr[p*2+1].s+=tr[p].s;
        tr[p].s=0;
    }
}

void build(int p,int l,int r){
    tr[p].mi=tr[p].s=0;
    if (l==r){
        tr[p].mi=s[l];
        tr[p].s=0;
        return;
    }
    int m=l+r>>1;
    build(p*2,l,m);
    build(p*2+1,m+1,r);
    tr[p].mi=min(tr[p*2].mi,tr[p*2+1].mi);
}

void ins(int p,int l,int r,int a,int b,int c){
    pass(p);
    if (l==a && r==b){
        tr[p].s+=c;
        pass(p);
        return;
    }
    int m=l+r>>1;
    if (b<=m) ins(p*2,l,m,a,b,c);
    else if (a>m) ins(p*2+1,m+1,r,a,b,c);
    else{
        ins(p*2,l,m,a,m,c);
        ins(p*2+1,m+1,r,m+1,b,c);
    }
    pass(p*2); pass(p*2+1);
    tr[p].mi=min(tr[p*2].mi,tr[p*2+1].mi);
}

int fnd(int p,int l,int r){
    pass(p);
    if (tr[p].mi>1) return 0;
    if (l==r) return l;
    int m=l+r>>1;
    int x=fnd(p*2+1,m+1,r);
    if (x!=0) return x;
    return fnd(p*2,l,m);
}

int main(){
//freopen("G.in","r",stdin);
//freopen("G.out","r",stdin);
ios::sync_with_stdio(false);
    while(cin>>n>>m){
        st.clear();
        rep(i,1,n){
            cin>>ch;
            if (ch==')'){
                a[i]=-1;
                st.insert(i);
            }
            else a[i]=1;
            s[i]=s[i-1]+a[i];
        }
        build(1,1,n);
        rep(i,1,m){
            cin>>x;
            if (a[x]==1){
                a[x]=-1;
                st.insert(x);
                ins(1,1,n,x,n,-2);
                x=*st.begin();
                st.erase(x);
                cout<<x<<endl;
                a[x]=1;
                ins(1,1,n,x,n,2);
            }
            else{
                a[x]=1;
                st.erase(x);
                ins(1,1,n,x,n,2);
                x=fnd(1,1,n)+1;
                a[x]=-1;
                st.insert(x);
                cout<<x<<endl;
                ins(1,1,n,x,n,-2);
            }
        }
    }
}
