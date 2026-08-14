#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int t,n,a[MM],bitL[MM],bitR[MM],sz,l[MM],r[MM];

void update(int x,int val,int bit[])
{
    for(;x <= sz;x += (x & -x)) bit[x] += val;
}

int get(int x,int bit[])
{
    int res = 0;
    for(;x > 0;x -= (x & -x)) res += bit[x];
    return res;
}

void solve()
{
    cin >> n;
    vector<int> vec;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        vec.push_back(a[i]);
    }
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    sz = vec.size();
    for(int i = 1;i <= n;i++) a[i] = lower_bound(vec.begin(),vec.end(),a[i]) - vec.begin() + 1;
    for(int i = 1;i <= n;i++) {
        l[i] = get(a[i] - 1,bitL);
        update(a[i],1,bitL);
    }
    for(int i = n;i >= 1;i--) {
        r[i] = get(a[i] - 1,bitR);
        update(a[i],1,bitR);
    }
    ll res = 0;
    for(int i = 1;i <= n;i++) res += min(l[i],r[i]);
    cout << res << '\n';
    for(int i = 1;i <= sz;i++) bitL[i] = bitR[i] = 0;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}