#include <bits/stdc++.h>
using namespace std;
const int N=30;
long long k,n,i,j,a[N][N],res,sum,z,x;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
cin >>k >>n;
for(i=1;i<=k;i++)
    for(j=1;j<=n;j++){
        cin >>x;
     a[x][i]=j;
    }
res=0;
for(i=1;i<n;i++)
    for(j=i+1;j<=n;j++){
        sum=0;
        for(z=1;z<=k;z++)
        if(a[i][z]>a[j][z]) sum++;
        if(sum%k==0) res++;
    }
    cout <<res;
    return 0;
}