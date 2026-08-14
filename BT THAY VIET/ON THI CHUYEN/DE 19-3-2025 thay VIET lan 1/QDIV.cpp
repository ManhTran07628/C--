#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;


bool check(ll l,ll r,ll k)
{
    ll L = ceil(l/double(k));
    ll R = r/k;
    if(L > R) return 0;
    if(L == R) {
        if(L == 1) return 1;
        else return 0;
    }
    if(L < R) return 1;
    return 0;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll q;
    cin >> q;
    while(q--) {
        ll l,r,k;
        cin >> l >> r >> k;
        if(k == 1) {
            cout << 1 << ' ';
            continue;
        }
        if(check(l,r,k)) cout << 1 << ' ';
        else cout << 0 << ' ';
    }
    return 0;
}