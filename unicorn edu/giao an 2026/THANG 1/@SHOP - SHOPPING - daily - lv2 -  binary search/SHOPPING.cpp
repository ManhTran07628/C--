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
const int N = 2e5 + 1;
const int MOD = 1e9 + 7;
int n,s,r,a[N];
int main()
{
#define TASKNAME "SHOPPING"
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(TASKNAME".inp","r" ))
    {
        freopen(TASKNAME".inp","r",stdin);
        freopen(TASKNAME".out","w",stdout);
    }
    cin>>n>>s;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    if (a[1]!=1)
    {
        cout<<-1;return 0;
    }
    int ans=0;
    while (r<s)
    {
        int vt=upper_bound(a+1,a+n+1,r+1)-a-1;
        r+=a[vt];
        ans++;
    }
    cout<<ans;
    return 0;
}