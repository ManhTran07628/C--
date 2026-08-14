#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9
const int MM = 1e3 + 7;
int n,a[MM];


ll DnC(ll L,ll R)
{
    if(L > R) return 0;
    if(L == R) {
        if(a[L] > 0) {
            a[L] = 0;
            return 1;
        }
        return 0;
    }

    // cout << R - L + 1 << ": ";
    // for(int i = L;i <= R;i++) cout << a[i] << ' '; cout << '\n';

    int Min = oo, pos = L;

    for(int i = L;i <= R;i++) {
        Min = min(Min,a[i]);
        if(a[i] == 0) {
            pos = i;
            break;
        }
    }
    
    if(Min == 0) return DnC(L,pos - 1) + DnC(pos + 1,R);

    for(int i = L;i <= R;i++) {
        a[i] -= Min;
        if(a[i] == 0) pos = i;
    }
    return DnC(L,pos - 1) + DnC(pos + 1,R) + 1;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    ll res = 0;
    cout << DnC(1,n);
    return 0;
}