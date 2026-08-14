#include <bits/stdc++.h>
 using namespace std;
const int N=1e3+1;
long long n,a[N],k,d=0;
long long mo(long long k)
{
    long long t = a[1] % k;
    for(long long i=2;i<=n;i++)
    {
        if(a[i] % k != t)
            return 0;
    }
    return 1;
}
int main()
{
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
      cin>>a[i];
    }
    sort(a+1,a+n+1);
 
    for(long long i=2;i<=a[1];i++)
    {
        if(mo(i)==1)
            cout<<i<<" ";
    }
 
    return 0;
}