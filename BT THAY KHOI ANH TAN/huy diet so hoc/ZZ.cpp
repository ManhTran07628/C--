#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
int M = 2310;
int n;

void solve()
{
    cin >> n;
    if(n < 4) cout << -1;
    else if(n == 4) cout << M;
    else {
        int p = 1;
        for(int i = 1;i <= n-1;i++) {
            p = (p*10)%M;
        }
        p = M-p;
        cout << 1;
        for(int i = 2;i <= n-4;i++) cout << 0;
        if(p < 10) cout << "00";
        else if(p < 100) cout << "0";
        cout << p;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}