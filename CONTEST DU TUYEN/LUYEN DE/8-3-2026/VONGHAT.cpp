#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 2e3 + 7;
int n;
vector<ll> a;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    for(int i = 0;i < n;i++) {
        int d; cin >> d;
        a.push_back(d);
    }
    // a.push_back(a[0]);
    while(a.size() > 1) {
        deque<ll> dq;
        for(int i = 0;i < a.size();i++) {
            ll val = a[i];
            while(!dq.empty() && dq.back() == val) {
                dq.pop_back();
                val += val;
            }
            dq.push_back(val);
        }

        while(dq.size() > 1 && dq.front() == dq.back()) {
            ll val = dq.front();
            dq.pop_back();
            dq.pop_front();
            dq.push_back(val + val);
        }

        vector<ll> v;
        while(!dq.empty()) {
            v.push_back(dq.front());
            dq.pop_front();
        }
        a = v;
        if(a.size() == v.size()) break;
    }
    ll res = 0;
    for(auto e:a) res = max(res,e);
    cout << res;
    // for(auto e:a) cout << e << ' ';
    return 0;
}