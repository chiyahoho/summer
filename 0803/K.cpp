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

int n,m,l,r,t,tt,ans,cnt,a[1200],b[1200];

int main(){
freopen("knockout.in","r",stdin);
//freopen("knockout.out","w",stdout);
    cin>>n>>m;
    rep(i,1,n) cin>>a[i]>>b[i];
    rep(i,1,m){
        cin>>l>>r>>t;
        cnt=0;
        rep(j,1,n){
            tt=t%(2*abs(a[j]-b[j]));
            if (a[j]<b[j]){
                if (tt<=b[j]-a[j]) ans=a[j]+tt;
                else{
                    tt-=b[j]-a[j];
                    ans=b[j]-tt;
                }
            }
            else{
                if (tt<=a[j]-b[j]) ans=a[j]-tt;
                else{
                    tt-=a[j]-b[j];
                    ans=a[j]+tt;
                }
            }
            if (ans>=l && ans<=r) cnt++;
        }
        cout<<cnt<<endl;
    }
}
