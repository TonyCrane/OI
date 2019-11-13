#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    //freopen("triangle.in","r",stdin);
    //freopen("triangle.out","w",stdout);
    
    long long ans,n,i;
    cin>>n;
    ans=1;
    for (i=n-5;i<=n;++i)
        ans=ans*i;
    ans=ans/720;
    cout<<ans<<endl;
}
