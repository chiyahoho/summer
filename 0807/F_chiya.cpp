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

string S;
int cas,n,x,y,ans,a[120000],s[120000];
priority_queue<int> q;

int main(){
//freopen(".in","r",stdin);
    cin>>cas;
    rep(ca,1,cas){
        cin>>S;
        n=S.size();
        if (n==1){
            if (S=="a") cout<<"Case "<<ca<<": "<<0<<endl;
            else cout<<"Case "<<ca<<": "<<2<<endl;
            continue;
        }
        For(i,n) a[i+1]=(S[i]=='a'?1:-1);
        s[0]=-1; rep(i,1,n) s[i]=s[i-1]+a[i];
        ans=abs(s[n]);
        if (s[n]<0) rep(i,1,n) s[i]-=s[n];
        while (!q.empty()) q.pop();
        rep(i,1,n) q.push(-s[i]);
        while(1){
            x=q.top(); q.pop();
            y=q.top(); q.pop();
            if (x==0 || x==y) break;
            ans++;
            q.push(y); q.push(x-2);
        }
        ans+=x*2;
        cout<<"Case "<<ca<<": "<<ans<<endl;
    }
}
