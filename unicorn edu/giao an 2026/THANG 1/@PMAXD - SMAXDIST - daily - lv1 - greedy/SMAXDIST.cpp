#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a*b / __gcd(a,b)
#define I first
#define II second
#define pb push_back
#define ii pair<int,int>
const int INF = 2 * 1e9;
const int N = 3e3 + 1;
const int MOD = 1e9 + 7;
int l[N],r[N],n,a[N];
int main()
{
#define TASKNAME " "
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(TASKNAME".inp","r" ))
    {
        freopen(TASKNAME".inp","r",stdin);
        freopen(TASKNAME".out","w",stdout);
    }
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++) if (a[j]<a[i]) r[i]++;
    //for (int i=1;i<=n;i++) cout<<l[i]<<' '<<r[i]<<'\n';
    for (int i=1;i<=n;i++)
        for (int j=i;j>=1;j--) if (a[j]>a[i]) l[i]++;
    ll ans=0;
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
    {
        int mx=abs(a[j]-a[i]);
        int v=j+r[j],u=i-l[i];
        //cout<<i<<' '<<j<<' '<<mx<<' '<<u<<' '<<v<<'\n';
        mx=max(max(v-i,mx),j-u);
        //cout<<i<<' '<<j<<' '<<mx<<'\n';
        ans+=1ll*mx;
    }
    cout<<ans;
    return 0;
}