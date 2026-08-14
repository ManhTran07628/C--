#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
int t;


void solve(int n,int a,int b) {
    bool ok = 0;
    if(b == n) ok = 1;
    else if((n - b) % 2 == 0) {
        if(a <= b) ok = 1;
        else if((a - b) % 2 == 0) ok = 1;
    }
    cout << (ok ? "YES" : "NO") << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        int n,a,b;
        cin >> n >> a >> b;
        solve(n,a,b);
    }
    return 0;
}