#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,m,k; cin >> n >> m >> k;

    if(n == m) {
        cout << 2 << ' ' << k;
        return 0;
    }

    if(n < m) swap(n,m);
    ll step_left = n - m;

    if(step_left >= k * 2) {
        cout << 0 << ' ' << 0;
        return 0;
    }



    // int delta = 0;

    // if(step_left % 2 == 1) {
    //     cout << k - (step_left + 1) / 2 << ' ' << k - step_left / 2;
    // }
    if(step_left % 2 == 0) {
        k -= step_left / 2;
        cout << 2 << ' ' << k;
        return 0; 
    }
    else cout << 0 << ' ' << 0;

    return 0;
}