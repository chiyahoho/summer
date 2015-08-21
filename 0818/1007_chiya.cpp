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

const int N=120;
const int oo=100000;
string ANS,ANS1;
int n,m,a[N][N],aa[N][N],sum,ans,ans1,vis[N][N];

void work(){
    int mini=0,minj=0;
    ANS="";
    a[0][0]=oo;
    rep(i,1,n) rep(j,1,m) if ((i+j)%2){
        if (a[i][j]<a[mini][minj]){
            mini=i;
            minj=j;
        }
    }
    ans=sum-a[mini][minj];

    rep(i,1,(mini-1)/2){
        rep(j,1,m-1) ANS+='R';
        ANS+='D';
        rep(j,1,m-1) ANS+='L';
        ANS+='D';
    }

    int i=((mini-1)/2)*2+1;
    rep(j,1,m) vis[i][j]=vis[i+1][j]=0;
    int j=1,edi=i+1;
    vis[mini][minj]=1;

    while (i!=edi || j!=m){
        vis[i][j]=1;
        if (i%2==0 && !vis[i-1][j]){
            i--;
            ANS+='U';
        }
        else if (i%2==1 && !vis[i+1][j]){
            i++;
            ANS+='D';
        }
        else{
            j++;
            ANS+='R';
        }
    }
    if (n-mini>=2){
        ANS+='D';
        rep(i,1,(n-mini)/2){
            rep(j,1,m-1) ANS+='L';
            ANS+='D';
            rep(j,1,m-1) ANS+='R';
            if (i!=(n-mini)/2) ANS+='D';
        }
    }
}

int main(){
//freopen("1007.in","r",stdin);

ios::sync_with_stdio(false);
    while(cin>>n>>m){
    sum=0;
        rep(i,1,n) rep(j,1,m) {cin>>a[i][j]; sum+=a[i][j];}
        if (n%2){
            cout<<sum<<endl;
            rep(i,1,n){
                if (i%2) rep(j,1,m-1) cout<<'R';
                else rep(j,1,m-1) cout<<'L';
                if (i!=n) cout<<'D';
            }
            cout<<endl;
        }
        else if (m%2){
            cout<<sum<<endl;
            rep(j,1,m){
                if (j%2) rep(i,1,n-1) cout<<'D';
                else rep(i,1,n-1) cout<<'U';
                if (j!=m) cout<<'R';
            }
            cout<<endl;
        }
        else{
            work();
            cout<<ans<<endl;
            cout<<ANS<<endl;
        }
    }
}
