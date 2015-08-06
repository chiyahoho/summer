#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
//#include<iostream>
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

int cas,a[120000],n,flag,tmp,now,now2,top,v,tot,u,q[120000],ru[120000],q1[120000],q2[120000];
long long sum;
vector<int> e[120000];

int main(){
freopen("A.in","r",stdin);
//ios::sync_with_stdio(false);
    scanf("%d",&cas);
    while(cas--){
        scanf("%d",&n);
        sum=0;
        rep(i,1,n){
            scanf("%d",&a[i]);
            sum=sum+a[i];
        }
        if (sum%n){
            printf("NO\n");
            continue;
        }
        sum=sum/n; flag=0;
        rep(i,1,n){
            a[i]=a[i]-sum;
            if (a[i]>2 || a[i]<-2) flag=1;
        }
        if (flag){
            printf("NO\n");
            continue;
        }

        rep(j,-1,1){
            now=j;
            tmp=0;
            rep(i,1,n-1){
                now+=a[i];
                if (now>1 || now<-1) tmp=1;
            }
            if (!tmp) flag=1,now2=j;
        }
        if (flag){
            printf("YES\n");
            now=now2;
            top=0;
            rep(i,1,n){
                if (now!=0){
                    q1[++top]=i;
                    q2[top]=now;
                }
                now+=a[i];
            }
            //printf("%d\n",top);
            rep(i,1,n) e[i].clear();
            rep(i,1,n) ru[i]=0;
            rep(i,1,top){
                u=q1[i]-1;
                if (!u) u=n;
                if (q2[i]>0) e[u].push_back(q1[i]),ru[q1[i]]++;
                else e[q1[i]].push_back(u),ru[u]++;
            }

            tot=0;
            rep(i,1,n) if (!ru[i]) q[++tot]=i;
            if (tot==0) printf("0\n");
            else printf("%d\n",top);

            while (tot){
                u=q[tot--];
                For(i,e[u].size()) {
                    v=e[u][i];
                    printf("%d %d\n",u,v);
                    ru[v]--;
                    if (!ru[v]) q[++tot]=v;
                }
            }
        }
        else printf("NO\n");
    }
    return 0;
}