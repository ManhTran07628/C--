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
const int N = 1e4 + 1;
const int MOD = 1e9 + 7;
int s[N],n,p,h,r,a[N];
map<int,int> g[N];
int main()
{
#define TASKNAME "*"
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(TASKNAME".inp","r" ))
    {
        freopen(TASKNAME".inp","r",stdin);
        freopen(TASKNAME".out","w",stdout);
    }
    cin>>n>>p>>h>>r;
    fill(a+1,a+n+1,h);
    while (r--)
    {
        int l,r;cin>>l>>r;
        if (l>r) swap(l,r);
        if (g[l][r]) continue;
        g[l][r]++;
        s[l+1]--;s[r]++;
    }
    for (int i=1;i<=n;i++)
    {
        s[i]+=s[i-1];
        cout<<a[i]+s[i]<<'\n';
    }
    return 0;
}