#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int lim = 16;
ll cnt9[lim + 7],total9[lim + 7];

ll cntnums(ll x)
{
    ll near = 1e15,f = x;
    ll res = 0;

    while(x > 0) {
        while(1) {
            if(near <= x) break;
            near /= 10;
        }
        int sz = to_string(near).size();
        string s = to_string(x);
        
        
        // if(s[0] == '9') res += total9[sz];
        res += (cnt9[sz] / 8 * (s[0] - '0') );
        
        // cout << x << '\n';

        x -= near * (s[0] - '0');
        
    }

    return f - res;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll a,b,p = 1;
    cin >> a >> b;
    for(int i = 1;i <= lim;i++) {
        total9[i] = (total9[i-1] * 8) + p;
        cnt9[i] = (total9[i-1] * 8);
        p *= 10;
        // cout << cnt9[i] << ' ';
    }
    // cout << cntnums(b);
    cout << cntnums(b) - cntnums(a-1);
    return 0;
}