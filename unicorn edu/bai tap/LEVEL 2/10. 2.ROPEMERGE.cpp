#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e5+7;
int n,L[MM];

struct cmp{
    bool operator() (ll a,ll b)
    {
        return a > b;
    }
};

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    priority_queue<ll,vector<ll>,cmp> q;
    for(int i = 1;i <= n;i++) {
        cin >> L[i];
        q.push(L[i]);
    }
    ll res = 0;
    while(q.size() > 1) {
        ll x = q.top(); q.pop();
        ll y = q.top(); q.pop();
        res += x + y;
        q.push(x+y);
    }
    cout << res;

    return 0;
}