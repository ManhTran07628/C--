#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6 + 7;


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,t; cin >> n >> t;
    if(t <= 9) {
        for(int i = 1;i <= n;i++) cout << t;
    }
    else if(t == 10) {
        if(n == 1) cout << -1;
        else {
            cout << 1;
            for(int i = 2;i <= n;i++) {
                cout << 0;
            }
        }
    }
    return 0;
}