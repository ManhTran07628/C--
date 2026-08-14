#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e5+7;
void solve()
{
    int n;
    cin >> n;
    for(int i = n;i >= 6;i--) {
        int p = i,cnt = 1;
        for(int j = 2;j*j <= p;j++) {
            int d = 0;
            while(p % j == 0) {
                p /= j;
                d++;
            }
            cnt *= (d+1);
        }
        if(p > 1) cnt *= 2;
        if(cnt == 4) {
            cout << i;
            return;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}