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
ll ans,n;
ii a[N];
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
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        ll x;
        cin>>x;
        ans+=x/100;
        a[i]={x%100,i};
    }
    sort(a+1,a+n+1);
    int j=n;
    vector<ii> g;
    for (int i=1;i<=n && j>i;i++)
        if (a[i].I+a[j].I>=100) ans++,g.pb({a[i].II,a[j].II}),j--;
    cout<<ans<<'\n';
    cout<<g.size()<<'\n';
    for (auto u : g) cout<<u.I<<' '<<u.II<<'\n';
    return 0;
}