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
    #define taskname "ff"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int n,k; cin >> n >> k;
    if(n < k) {
        cout << 2;
        return 0;
    }
    int half = 0, done = 0, raw = n, step = 0;

    step += raw / k; raw -= step * k;
    half += step * k;

    done += (k - raw);
    half += raw; half -= done;
    raw = 0;

    // cout << done << ' ' << half << ' ' << raw << '\n';
    step++;

    step += half / k + (half % k > 0);

    cout << step;
    return 0;
}