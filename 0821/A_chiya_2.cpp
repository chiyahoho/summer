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

ll x0,x1,Y0,Y1,n,m,ans;

int main(){
//freopen("A.in","r",stdin);
    while(cin>>n>>m,n&&m){
        ans=abs(n-m);
        x0=0; x1=1;
        while(n*2>m){
            if (n&1){
                Y0=min(x0+2,x1+2);
                Y1=min(x0+2,x1+1);
            }
            else{
                Y0=min(x0+1,x1+2);
                Y1=min(x0+2,x1+2);
            }
            n>>=1;
            x0=Y0,x1=Y1;
            upmin(ans,abs(n-m)+Y0);
            upmin(ans,abs(n+1-m)+Y1);
        }
        cout<<ans<<endl;
    }
}
