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

int ans,M,L,pre,top,num[120000];
string s;

int main(){
//freopen("B.in","r",stdin);
ios::sync_with_stdio(false);
    while(cin>>s){
        top=0;
        For(i,s.size()){
            if (isdigit(s[i])){
                num[++top]=s[i]-'0';
            }
            else if (s[i]=='*'){
                num[top]*=s[++i]-'0';
            }
        }
        rep(i,2,top) num[1]+=num[i];
        M=num[1];
        pre=L=0;
        For(i,s.size()){
            if (isdigit(s[i])){
                if (!pre) L+=s[i]-'0';
                else L*=s[i]-'0';
            }
            else if (s[i]=='*') pre=1;
            else if (s[i]=='+') pre=0;
        }
        cin>>ans;
        if (M==ans && L==ans) cout<<'U'<<endl;
        else if (M==ans) cout<<'M'<<endl;
        else if (L==ans) cout<<'L'<<endl;
        else cout<<'I'<<endl;
    }
}
