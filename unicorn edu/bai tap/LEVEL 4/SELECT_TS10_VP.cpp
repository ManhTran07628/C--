#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<ll,ll>
const int MM = 2e5+7;
int n;
ll a[MM];
priority_queue<pii> q;
set<int> alive;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "SELECT"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        q.push({a[i],i});
        alive.insert(i);
    }
    ll res = 0;
    for(int i = 1;i <= (n + 1) / 2;i++) {

        while(1) {
            ll val = q.top().fi, pos = q.top().se;
            q.pop();

            auto it = alive.find(pos);
            if(it == alive.end()) continue;

            res += val;
            // nen vi tri L va R
            auto L = (it == alive.begin() ? alive.end() : prev(it) );
            auto R = next(it);

            if(L != alive.end() && R != alive.end()) {
                ll newval = -a[pos] + a[*L] + a[*R];

                alive.erase(L);
                alive.erase(R);

                a[pos] = newval;
                q.push({newval,pos});
            }
            else {
                if (L != alive.end()) alive.erase(L);
                if (R != alive.end()) alive.erase(R);
                alive.erase(it);
            }

            break;
        }
        cout << res << '\n';

    }
    return 0;
}