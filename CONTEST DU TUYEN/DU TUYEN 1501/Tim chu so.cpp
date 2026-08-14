#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6 + 7;

ll cnt_sz(ll a)
{
    ll cnt = 0;
    while(a > 0) {
        cnt++;
        a /= 10;
    }
    return cnt;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll a,b,k; cin >> a >> b >> k;
    a = a % b; 
    ll cnt = 0;
    while(cnt < k) {
        while(a < b) a *= 10;
        cnt++; 
        if(cnt == k) {
            cout << a / b;
            break;
        }
        a %= b;
    }
    return 0;
}