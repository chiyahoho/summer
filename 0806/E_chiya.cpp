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

string s;
const ll N=2200000;
const ll mo=1000000007;
ll n,cas,top,pre,match[N],stk[N],a[N],b[N],ans[N],up[N];
ll sum;

int main(){
//freopen("E.in","r",stdin);
//freopen("E.out","w",stdout);
ios::sync_with_stdio(false);
    cin>>cas;
    while(cas--){
        cin>>s;
        n=s.size();
        top=pre=0;
        rep(i,0,n+10) match[i]=up[i]=a[i]=b[i]=ans[i]=0;
        For(i,n){
            if (s[i]=='(') stk[++top]=i+1;
            else if (top){
                match[stk[top]]=i+1;
                match[i+1]=stk[top--];
                if (top) up[match[i+1]]=stk[top];
            }
        }
        rep(i,1,n) if (!match[up[i]]) up[i]=0;
        per(i,n,1) if(s[i-1]=='(' && match[i]) a[i]=a[match[i]+1]+1;
        rep(i,1,n) if(s[i-1]==')' && match[i]) b[i]=b[match[i]-1]+1;
        rep(i,1,n) if(s[i-1]=='(' && match[i]) ans[i]=ans[match[i]]=((a[i]*b[match[i]])%mo+ans[up[i]])%mo;
        sum=0;
        rep(i,1,n) sum+=(ans[i]*i)%mo;
        cout<<sum<<endl;
    }
}
