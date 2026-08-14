#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 50;
int n,x;
ll a[MM];
vector<ll> L,R;

void Try(int l,int r,int id,ll sum,vector<ll> &f)
{
    if(id == r+1) {
        // cout << sum << ' ';
        f.push_back(sum);
        return;
    }
    Try(l,r,id+1,sum + a[id],f);
    Try(l,r,id+1,sum,f);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    for(int i = 1;i <= n;i++) cin >> a[i];
    Try(1,n/2,1,0,L);
    Try(n/2+1,n,n/2+1,0,R);
    sort(R.begin(),R.end());
    ll cnt = 0;
    for(auto val:L) {
        int l = lower_bound(R.begin(),R.end(),x - val) - R.begin();
        int r = upper_bound(R.begin(),R.end(),x - val) - R.begin();
        cnt += r - l;
    }
    cout << cnt;
    return 0;
}