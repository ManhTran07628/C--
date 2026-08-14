#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
ll a[MAXN];
ll prefix[MAXN];
ll n,k;
ll ans = 0;
vector<ll> vt;
void backtracking(ll id)
{
    if(vt.size() == k) {
        for(int i = 0;i < vt.size();i++) {
            for(int j = i+1;j < vt.size();j++) {
                ans = max(ans,abs(vt[i]-vt[j]));
            }
        }
        return;
    }
    for(int i = id+1;i <= n;i++) {
        vt.push_back(a[i]-a[id]);
        backtracking(i);
        vt.pop_back();
    }

}

void sub1()
{
    for(int i = 1;i <= n;i++) a[i] += a[i-1];
    backtracking(0);
    cout << ans;
}

void sub2()
{
    for(int i = 1;i <= n;i++) a[i] += a[i-1];
    ll ans = 0;
    for(int i = 1;i < n;i++) {
        ll l = a[i],r = a[n] - a[i];
        ans = max(ans,abs(r-l));
    }
    cout << ans;
}

void sub3()
{
    for(int i = 1;i <= n;i++) a[i] += a[i-1];
    ll ans = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = i+1;j <= n;j++) {
            ll d1 = a[i];
            ll d2 = a[j]-a[i];
            for(int k = j+1;j < n;k++) {
                ll d3 = a[n]-a[k];
                ans = max({ans,abs(d1-d2),abs(d3-d2)});
            }
        }
    }
    cout << ans;
}

void sub3456()
{
    for(int i = 1;i <= n;i++) a[i] += a[i-1];
    p[1] = a[1];
    for(int i = 2;i <= n;i++) {
        ll p = min(a[i],p[i-1]);
        p[i] = p+p[i-1];
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    // if(n <= 15) sub1();
    // else if(k == 2) sub2();
    // else sub3();
    for(int i = 1;i <= n;i++) a[i] += a[i-1];
    p[1] = a[1];
    for(int i = 2;i <= n;i++) {
        ll p = min(a[i],p[i-1]);
        p[i] = p+p[i-1];
    }
    cout << p[4]-p[2];
    return 0;
}