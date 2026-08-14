#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
set<pair<ll,ll>> s;

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
    int q;
    cin >> q;
    while(q--) {
        ll x,a,b;
        cin >> x;
        if(x == 1) {
            cin >> a >> b;
            s.insert({b,a});
        }
        else if(x == 2) {
            cin >> a >> b;
            auto it = s.find({0ll,a});
            if(it != s.end()) {
                s.erase(it);
                if(it.fi <= b) continue;
                ll tmp = it.fi - b;
                s.insert({tmp,a});
            }
        }
        else {
            cout << s.rbegin().se << '\n';
        }
    }
    return 0;
}