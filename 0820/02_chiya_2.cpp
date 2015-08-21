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

const int mo=1000000007;
vector<int> a;
int cas,n,maxa,up[100000],low[100000],now[100000],f[1200000],po[1200000];
ll ans;

void predo(){
    int n=1000002;
    rep(i,1,n) f[i]=i;
    rep(i,2,n){
        if (f[i]==i) {
            a.push_back(i);
            po[i]=a.size()-1;
        }
        For(j,a.size())
            if (a[j]*i<=n){
                f[a[j]*i]=a[j];
                if (i%a[j]==0) break;
            }
            else break;
    }
}

inline void jia(int x){
    for(;x>1;x/=f[x]) {
        now[po[f[x]]]++;
        upmax(maxa,po[f[x]]);
    }
}
inline void jian(int x){
    for(;x>1;x/=f[x]){
        now[po[f[x]]]--;
        upmin(low[po[f[x]]],now[po[f[x]]]);
    }
}

int main(){
freopen("02.in","r",stdin);
//freopen("02.out","w",stdout);
    predo();
    scanf("%d",&cas);
    while(cas--){
        scanf("%d",&n);
    //for(n=1;n<=100;n++){
        //cout<<n<<":  ";
        ans=1; maxa=0;
        rep(i,1,n) jia(i);
        maxa++;
        For(i,maxa) up[i]=low[i]=now[i];
        rep(i,0,n/2){
            jia(i+1);
            jian(n-i);
        }
        /*For(i,maxa) if (low[i]){
            cout<<a[i]<<'^'<<low[i]<<'*';
        }
        cout<<endl;*/
        For(i,maxa) {
            up[i]-=low[i];
            while(up[i]--) ans=(ans*a[i])%mo;
        }
        printf("%lld\n",ans);
        For(i,maxa) now[i]=0;
    }
}
