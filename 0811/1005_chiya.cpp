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

int n,m,top,ans,ca,sum,tot,q[120000],s[1200000];

int main(){
//freopen("E.in","r",stdin);
    while(1){
        scanf("%d%d",&n,&m);
        if (n==-1 && m==-1) break;
        m++; tot=0; sum=0;
        while(m--){
            for(top=0;n;n/=10) q[++top]=n%10;
            while(top){
                s[++tot]=q[top];
                sum+=q[top];
                top--;
            }
            n=sum;
        }
        ans=0;
        rep(i,1,tot) (i&1)?ans+=s[i]:ans-=s[i];
        ans=abs(ans);
        printf("Case #%d: ",++ca);
        if (ans%11==0) printf("Yes\n");
        else printf("No\n");
    }
}
