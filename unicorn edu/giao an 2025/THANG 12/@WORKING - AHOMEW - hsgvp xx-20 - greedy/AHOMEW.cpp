#include<bits/stdc++.h>
using namespace std;
long long n,i,a[100005],ma,dem[100005];
int main(){
cin>>n;
ma=1;
for(i=1;i<=n;i++){
    cin>>a[i];
    dem[i]++;
    if(a[i]>=a[i-1]) dem[i]+=dem[i-1];
    ma=max(ma,dem[i]);
    }
cout<<ma;
return 0;
}