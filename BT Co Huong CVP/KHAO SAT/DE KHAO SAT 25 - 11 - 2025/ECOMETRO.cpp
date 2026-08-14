#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e5+7;
int n,m,q,id[MM],ps[MM],big[MM],vl[MM];

void solve(ll a,ll b)
{
    if(a > b) swap(a,b);
    ll res = b - a;

    vector<ll> T1;
    int posA = lower_bound(big+1,big+m+1,a) - big;
    if(posA <= m) T1.push_back(big[ posA ]);
    if(posA > 1) T1.push_back(big[ posA - 1 ]);

    vector<ll> T2;
    int posB = lower_bound(big+1,big+m+1,b) - big;
    if(posB <= m) T2.push_back(big[ posB ]);
    if(posB > 1) T2.push_back(big[ posB - 1 ]);

    for(auto L1 :T1) 
        for(auto L2 :T2) {
            int p1 = lower_bound(big+1,big+m+1,L1) - big;
            int p2 = lower_bound(big+1,big+m+1,L2) - big;
            ll mid = ps[p2] - ps[p1];
            ll cost = abs(a - L1) + mid + abs(b - L2);
            res = min(res,cost);
        }

    cout << res << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        cin >> big[i];
    }

    for(int i = 1;i < m;i++) {
        ps[i+1] = ps[i] + min(2,big[i+1] - big[i]);  
    }

    cin >> q;
    while(q--) {
        int a,b;
        cin >> a >> b;
        solve(a,b);
    }

    return 0;
}