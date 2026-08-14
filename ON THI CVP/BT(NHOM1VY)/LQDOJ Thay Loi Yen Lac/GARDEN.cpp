#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
pair<ll,ll> a[N];
ll n,k;

bool check(ll mid)
{
    ll tmp = 0, kt = 1;
    for(int i = 1;i <= n;i++) {
        if(a[i].first < mid) {
            ll cmp = ceil(double(mid - a[i].first) / a[i].second);
            tmp += cmp;
        }
    }
    return tmp<=k;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].first >> a[i].second;
    }
    ll L = 0,R = 1e14,fans = 0;
    while(L <= R) {
        ll mid = (L+R)/2;
        if(check(mid)) {
            fans = mid;
            L = mid + 1;
        }
        else R = mid - 1;
    }
    cout << fans;
    return 0;
}