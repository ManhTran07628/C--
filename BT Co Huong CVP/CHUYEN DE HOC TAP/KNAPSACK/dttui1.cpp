#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 40 + 7;
ll n,M,w[MM],v[MM];
vector<pair<ll,ll>> A,B;
vector<ll> f;

void Try(int L,int R,int id,ll sum,ll weight,vector<pair<ll,ll>> &x)
{
    if(id == R + 1) {   
        if(weight <= M) x.push_back({weight,sum});
        return;
    }
    Try(L,R,id + 1,sum,weight,x);
    Try(L,R,id + 1,sum + v[id],weight + w[id],x);
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> M;
    for(int i = 1;i <= n;i++) cin >> w[i] >> v[i];
    Try(1,n / 2,1,0,0,A);
    Try(n / 2 + 1,n,n / 2 + 1,0,0,B);
    sort(B.begin(),B.end());
    f.push_back(B[0].fi);
    for(int i = 1;i < B.size();i++) {
        f.push_back(B[i].fi);
        B[i].se = max(B[i].se,B[i-1].se);
    }
    ll res = 0;
    for(auto x:A) {
        int pos = upper_bound(f.begin(),f.end(),M - x.fi) - f.begin() - 1;
        res = max(res,B[pos].se + x.se);
    }
    cout << res;
    return 0;
}