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

int cas,n,m,flag,p;
ll sum,f[20];
vector<int> ans[20];

int main(){
//freopen("C.in","r",stdin);
    cin>>cas;
    while (cas--){
        cin>>n>>m;
        sum=(ll)n*(n+1)/2;
        flag=sum%m;
        sum/=m;
        rep(i,1,m) f[i]=sum;
        rep(i,1,m) ans[i].clear();
        p=0;
        per(i,n,1){
            rep(j,1,m)
                /*if (f[j]==i){
                    p=j;
                    break;
                }
                else */if (f[j]>f[p]) p=j;
            if (f[p]<i) flag=1;
            f[p]-=i;
            ans[p].push_back(i);
        }

        if (flag) cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            rep(i,1,m){
                cout<<ans[i].size();
                For(j,ans[i].size()) cout<<' '<<ans[i][j];
                cout<<endl;
            }
        }
    }
}
