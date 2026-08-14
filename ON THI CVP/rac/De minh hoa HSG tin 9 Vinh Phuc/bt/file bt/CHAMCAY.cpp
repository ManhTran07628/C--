#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];
vector<pair<ll,ll>> b,c;
ll tmp = 1e7;

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
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    ll m;
    cin >> m;
    for(int i = 1;i <= m;i++) {
        ll a1,b1;
        cin >> a1 >> b1;
        b.push_back({a1,b1});
    }
    sort(b.begin(),b.end());
    ll min1 = 1e9;
    for(int i = m-1;i >= 0;i--) {
        min1 = min(min1,b[i].second);
        c.push_back({b[i].first,min1});
    }
    sort(c.begin(),c.end());
    ll dem = 0;
    for(int i = 1;i <= n;i++) {
        ll L = 1,R = m,sotien = 1e9;
        while(L <= R) {
            ll mid = (L+R) / 2;
            if(c[mid].first >= a[i]) {
                if(c[mid].second < sotien)
                    sotien = c[mid].second;
                R = mid - 1;
            }
            else L = mid + 1;
        }
        dem += sotien;
    }
    cout << dem;
    return 0;
}

