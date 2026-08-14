#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 3e5+7;
const int LOG = 31;
int n,a[MM],cur[MM],nxt[MM];


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];

    for(int i = 1;i <= n;i++) cur[i] = a[i];

    ll res = 0,sz = n;
    for(int j = LOG;j >= 0;j--) {
        int cnt = 0;
        for(int i = 1;i <= sz;i++) 
            if(cur[i] >> j & 1) 
                nxt[++cnt] = cur[i];
            

        if(cnt >= 2) {
            res += (1 << j);
            sz = cnt;
            for(int i = 1;i <= cnt;i++) cur[i] = nxt[i];
        }
    }
    cout << res;
    return 0;
}