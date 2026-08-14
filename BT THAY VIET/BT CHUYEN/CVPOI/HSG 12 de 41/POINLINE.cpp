#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6 + 7;
int n,m,x[MM],dif[MM];
int a[MM],b[MM];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i] >> b[i];
    for(int i = 1;i <= m;i++) cin >> x[i];
    sort(x+1,x+m+1);
    

    for(int i = 1;i <= n;i++) {
        int L = lower_bound(x+1,x+m+1,a[i]) - x;
        int R = upper_bound(x+1,x+m+1,b[i]) - x - 1;
        if(L <= R) {
            dif[L]++;
            dif[R+1]--;
        }
        // cout << L << ' ' << R << '\n';
    }
    for(int i = 1;i <= m;i++) {
        dif[i] += dif[i-1];
        cout << dif[i] << ' ';
    }
    return 0;
}