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

int n,d1,d2,i,l,r,ans,a[120000];

int main(){
freopen("05.in","r",stdin);
    while(cin>>n>>d1>>d2){
        rep(i,1,n) cin>>a[i];
        l=1; ans=0;
        while(l<=n){
            i=l;
            while (i<n && a[i+1]-a[i]==d1) i++;
            while (i<n && a[i+1]-a[i]==d2) i++;
            r=i;
            ans+=(r-l+2)*(r-l+1)/2;
            cout<<l<<' '<<r<<endl;
            if (l==r) l=r+1;
            else l=r;
            ans--;
        }
        cout<<ans<<endl;
    }
}
