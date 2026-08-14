#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6;
int n,m;
ll a[MM];
vector<ll> getL,getR;
void Try(int L,int R,int id,ll sum,vector<ll> &c)
{
    if(id == R+1) {
        c.push_back(sum);
        return;
    }
    Try(L,R,id+1,(sum + a[id]) % m,c);
    Try(L,R,id+1,sum % m,c);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        a[i] %= m;
    }
    Try(1,n/2,1,0,getL);
    Try(n/2+1,n,n/2+1,0,getR);

    sort(getR.begin(),getR.end());
    ll sum = 0;
    ll res = -oo;
    for(auto x:getL) {
        auto it = lower_bound(getR.begin(),getR.end(),m - x);
        res = max(res,(ll) (*it + x) % m);
        if(it != getR.begin()) {
            --it;
            res = max(res,(ll) (*it + x) % m);
        }
    }
    cout << res;
    return 0;
}