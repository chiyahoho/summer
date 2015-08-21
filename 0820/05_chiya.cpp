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

int cas,l,r,m,s,A,B,c,n,t,f[10000],a[10000],b[10000];

void ins(int x,int y){
    while(l<=r && b[r]<=y) r--;
    a[++r]=x; b[r]=y;
}

void work(int m,int s,int c){
    if (c==0 || t/m<c) c=t/m;
    For(d,m){
        l=1; r=0;
        rep(j,0,(t-d)/m){
            ins(j,f[j*m+d]-j*s);
            if (a[l]<j-c) l++;
            f[j*m+d]=b[l]+j*s;
        }
    }
}

int main(){
//freopen("05.in","r",stdin);
ios::sync_with_stdio(false);
    cin>>cas;
    while(cas--){
        cin>>t>>n;
        rep(i,0,t+10) a[i]=b[i]=f[i]=0;
        rep(i,1,n){
            cin>>m>>A>>B;
            work(m,A+B,1);
            work(m,A,0);
        }
        cout<<f[t]<<endl;
    }
}
