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
#include<bitset>
#define rep(i,a,b) for(int i=a,_b=b;i<=_b;i++)
#define per(i,a,b) for(int i=a,_b=b;i>=_b;i--)
#define For(i,b) for(int i=0,_b=b;i<_b;i++)
#define upmax(a,b) if ((a)<(b)) (a)=(b)
#define upmin(a,b) if ((a)>(b)) (a)=(b)
using namespace std;

int n,tot,q[1200];
bitset<105> bt[1200];
char ch;
struct node{
    int op,to[3];
}a[1200],b[120000];

void dfs(int p,int u){
    q[p]=u;
    rep(i,1,n) if (bt[p][i]){
        b[u].op=(a[i].op+1)%3;
        break;
    }

    For(j,3){
        bt[p+1].reset();
        rep(i,1,n) if (bt[p][i] && a[i].op==j){
            bt[p+1][a[i].to[b[u].op]]=1;
        }
        if (bt[p+1].count()){
            int flag=0;
            rep(i,1,p) if (bt[p+1]==bt[i]){
                flag=1;
                b[u].to[j]=q[i];
                break;
            }
            if (!flag){
                b[u].to[j]=++tot;
                dfs(p+1,tot);
            }
        }
        else b[u].to[j]=1;
    }
}

int main(){
freopen("epic.in","r",stdin);
freopen("epic.out","w",stdout);
    cin>>n;
    tot=1;
    rep(i,1,n){
        cin>>ch;
        a[i].op= ch=='R'?0:(ch=='P'?1:2);
        For(j,3) cin>>a[i].to[j];
    }
    rep(i,1,n) bt[1][i]=1;
    dfs(1,1);
    cout<<tot<<endl;
    rep(i,1,tot) cout<<(b[i].op==0?'R':(b[i].op==1?'P':'S'))<<' '<<b[i].to[0]<<' '<<b[i].to[1]<<' '<<b[i].to[2]<<endl;
}
