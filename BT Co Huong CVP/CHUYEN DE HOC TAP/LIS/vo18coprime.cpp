#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<ll,ll>
const int MM = 1e5 + 7;
ll n,a[MM],b[MM],vis[MM];
vector<int> primes{2,3,5,7,11};
vector<pii> subset;

void coordcompress()
{
    vector<ll> v;
    for(auto x:subset) v.push_back(x.fi);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i = 0;i < subset.size();i++) {
        subset[i].se = lower_bound(v.begin(),v.end(),subset[i].fi) - v.begin();
        vis[ subset[i].fi ] = subset[i].se;
    }
    
    v.clear();

    for(int i = 1;i <= n;i++) v.push_back(a[i]);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i = 1;i <= n;i++)
        b[i] = lower_bound(v.begin(),v.end(),a[i]) - v.begin() + 1;

}

void process()
{
    int sz = primes.size();
    subset.push_back({1,0});
    for(int mask = 1;mask < (1 << sz);mask++) {
        int mul = 1;
        for(int i = 0;i < sz;i++)
            if(mask >> i & 1) mul *= primes[i];
        subset.push_back({mul,0});
    }
}

int st[50][MM * 4];

void update(int id,int l,int r,int pos,int val,int type)
{
    if(l > pos || r < pos) return;
    if(l == r) {
        st[type][id] = max(st[type][id],val);
        return;
    }
    int mid = (l + r) / 2;
    update(id*2,l,mid,pos,val,type);
    update(id*2+1,mid+1,r,pos,val,type);
    st[type][id] = max(st[type][id*2],st[type][id*2+1]);
}

int get(int id,int l,int r,int u,int v,int type)
{
    if(l > v || r < u) return 0;
    if(u <= l && r <= v) return st[type][id];
    int mid = (l + r) / 2;
    return max(get(id*2,l,mid,u,v,type), get(id*2+1,mid+1,r,u,v,type));
}

namespace sol
{
    void solve()
    {
        coordcompress();
        int ans = 0;
        for(int i = 1;i <= n;i++) {
            // get
            int res = 0;
            for(auto p:subset) {
                if(__gcd(a[i],p.fi) == 1) {
                    int cur = get(1,1,n,1,b[i] - 1,p.se);
                    res = max(res,cur + 1);   
                    ans = max(ans,res); 
                }
            }

            // update
            int mul = 1;
            for(auto p:primes) if(a[i] % p == 0) mul *= p;
            update(1,1,n,b[i],res,vis[mul]);
        }
        cout << ans;
    }
}

namespace brute
{
    ll f[MM];
    void solve()
    {
        ll max1 = 1;
        for(int i = 1;i <= n;i++) {
            f[i] = 1;
            for(int j = 1;j < i;j++) {
                if(a[i] > a[j] && __gcd(a[i],a[j]) == 1) {
                    f[i] = max(f[i],f[j]+1);
                    max1 = max(max1,f[i]);
                }
            }
        }
        cout << max1;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "sol"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    process();
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sol::solve();
    return 0;
}