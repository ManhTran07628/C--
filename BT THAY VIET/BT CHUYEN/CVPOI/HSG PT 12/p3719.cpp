#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e4;
int n,m,a[MM],b[MM],resb[MM];

namespace subtask1
{
    void solve()
    {
        int s = 2, t = 1, res = 0;
        if(b[1] == 0) resb[1] = 2;
        else resb[1] = 1;
        for(int i = 2;i <= m;i++) {
            if(b[i] == 1) {
                if(b[i-1] == 1) resb[i] = resb[i-1] + 2;
                else resb[i] = resb[i-1] + 1;
            }
            else {
                if(b[i-1] == 0) resb[i] = resb[i-1] + 2;
                else resb[i] = resb[i-1] + 1;
            }
            res = max(res,resb[i]);
        }
        // for(int i = 1;i <= m;i++) cout << resb[i] << ' '; cout << '\n';
        cout << res;
    }
}

namespace subtask2
{
    void solve()
    {
        int s = 2, t = 1, res = 0;
        if(b[1] == 0) resb[1] = 2;
        else resb[1] = 1;
        for(int i = 2;i <= m;i++) {
            if(b[i] == 1) {
                if(b[i-1] == 1) resb[i] = resb[i-1] + 2;
                else resb[i] = resb[i-1] + 1;
            }
            else {
                if(b[i-1] == 0) resb[i] = resb[i-1] + 2;
                else resb[i] = resb[i-1] + 1;
            }
            if(b[i] == 0) res = resb[i];
            // res = max(res,resb[i]);
        }
        for(int i = 1;i <= n;i++) {
            res += 2;
        }
        cout << res;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    cin >> m;
    for(int i = 1;i <= m;i++) cin >> b[i];
    if(n == 0) subtask1::solve();
    else subtask2::solve();
    return 0;
}