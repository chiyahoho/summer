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

int s[120000];
int len[240000],n,T,ans,l,lll,p,a[240000];

void manacher(int str[],int len[],int n){
    len[0]=1;
    for(int i=1,j=0;i<(n<<1)-1;++i){
        int p=i>>1, q=i-p,r=((j+1)>>1)+len[j]-1;
        len[i]=r<q?0:min(r-q+1,len[(j<<1)-i]);
        while(p>len[i]-1 && q+len[i]<n && str[p-len[i]]==str[q+len[i]]) ++len[i];
        if (q+len[i]-1>r) j=i;
    }
}
set<int> b;
set<int>::iterator it;
vector<int> c[240000];
int main(){
//freopen(".in","r",stdin);
    scanf("%d",&T);
    for(int tt=1;tt<=T;tt++)
    {
        scanf("%d",&n);
        memset(len,0,sizeof(len));
        for(int i=0;i<=n-1;i++)
            scanf("%d",&s[i]);
        manacher(s,len,n);
        //for(int i=0;i<=2*n;i++)
        //    cout<<len[i]<<' ';
        //cout<<endl;
        for(int i=0;i<=n-1;i++)
            a[i+1]=len[2*(i+1)-1];
        b.clear();
        b.insert(0);
        ans=0;
        for(int i=1;i<=n-1;i++)
            c[i].clear();
        for(int i=n-1;i>=1;i--)
        {
            int leng=c[i].size();
            for (int j=0;j<leng;j++)
                b.erase(c[i][j]);
            it = b.upper_bound(i+a[i]);
            it--;
            if ((*it)!=0) {
                ans=max((*it)-i,ans);
            }
            if (a[i]>0)
                {
                    b.insert(i);
                    p=i-a[i]-1;
                    if (p>0)
                        c[p].push_back(i);
                }
        }
        /*ans=0;
        for(int i=0;i<=n-1;i++)
        {
            l=2*(i+1)-1;
            p=i+len[l];
            if (p<=n-1)
            {
            lll=2*(p+1)-1;
            if (len[lll]>=len[l])
                ans=max(len[l],ans);
            }
        }
        for(int i=0;i<=n-1;i++)
        {
            l=2*(i+1)-1;
            p=i-len[l];
            if (p>=0)
            {
            lll=2*(p+1)-1;
            if (len[lll]>=len[l])
                ans=max(len[l],ans);
            }
        }*/
        printf("Case #%d: %d\n",tt,ans*3);
    }

}
