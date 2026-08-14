#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
int n,k,q,l[MM];
map<int,int> ds;
void subtask12()
{
    while(q--) {
        int a,b;
        cin >> a >> b;
        if(a > b) swap(a,b);
        if(a == 1) a++;
        if(b == n) b--;
        int ans = 1e7;
        for(int t = 1;t <= k;t++) {
            int cnt = 0;
            for(int i = a;i <= b;i++) {
                if(l[i] >= t) cnt++;
            }
            ans = min(ans,cnt);
        }
        if(b != n) ans++;
        cout << ans << '\n';
        ds.clear();
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> q;
    for(int i = 1;i <= n;i++) {
        cin >> l[i];
    }
    subtask12();
    return 0;
}