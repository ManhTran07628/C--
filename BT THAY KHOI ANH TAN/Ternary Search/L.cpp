#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define i128 __int128
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;
ll n,h[MM],c[MM];
i128 ps_cost[MM],ps_ci[MM];

i128 get(int k,i128 x)
{
    ll d = upper_bound(h+1,h+n+1,x) - h;
    if(d > n) d = n;
    i128 x_ = x;
    i128 ans =  (ps_cost[k] - ps_cost[d]) - (ps_ci[k] - ps_ci[d]) * x;
    ans += ps_ci[d] * x - ps_cost[d];
    return ans;
}

string to_string128(i128 x) {
    if (x == 0) return "0";
    string s;
    while (x > 0) {
        s.push_back('0' + x % 10);
        x /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}

void bins(int L,int R)
{
    i128 fans = 0;
    int i = R;
    while(L <= R) {
        int m1 = L + (R - L) / 3, m2 = R - (R - L) / 3;
        i128 v1 = get(i,m1), v2 = get(i,m2);
        if(v1 > v2) {
            fans = m1;
            R = m2 - 1;
        }
        else {
            fans = m2;
            L = m1 + 1;
        }
    }
    cout << to_string128(get(i,fans)) << ' ';
    
}



signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> h[i];
    for(int i = 1;i <= n;i++) {
        cin >> c[i];
        ps_cost[i] = ps_cost[i-1] + c[i] * h[i];
        ps_ci[i] = ps_ci[i-1] + c[i];
    }

    for(int i = 1;i <= n;i++) {
        bins(1,i);
    }

    return 0;
}