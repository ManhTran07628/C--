#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
ll a[MAXN],b[MAXN];
ll n,v;
ll check(ll k,ll f)
{
    ll sum = 0;
    for(int i = 1;i <= n;i++) {
        ll c = abs(a[i]+k-b[i]);
        sum += c;
        if(sum > f) return 1e18;
    }
    return sum;
}

ll check1(ll k)
{
    ll sum = 0;
    vector<ll> vt;
    for(int i = 1;i <= n;i++) {
        ll c = abs(a[i]+k-b[i]);
        if(c != 0) vt.push_back(c);
        sum += c;
    }
    sort(vt.begin(),vt.end());
    ll n1 = vt.size();
    for(int i = vt.size()-1;i >= max(0ll,n1-v);i--) {
        sum -= vt[i];
    }
    return sum;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> v;
    ll m = 0,ans = 1e18;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> b[i];
    if(v == 0) {
        for(int j = 0;j <= 1000;j++) {
            if(check(j,ans) < ans) ans = check(j,ans);
            if(check(-j,ans) < ans) ans = check(-j,ans);
        }
        cout << ans;
        return 0;
    }
    for(int j = 0;j <= 1000;j++) {
        if(check1(j) < ans) ans = check1(j);
        if(check1(-j) < ans) ans = check1(-j);
    }
    cout << ans;
    return 0;
}

