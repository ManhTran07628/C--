#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 2e9
#define pii pair<int,int>
const int MM = 1e6+7;
int a[MM],n,q;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> a[i];
    while(q--) {
        int type; cin >> type;
        if(type == 1) {
            int l,val;
            cin >> l >> val;
            a[l] = val;
        }
        else {
            int l,r,res = oo;
            cin >> l >> r;
            for(int i = l;i <= r;i++) {
                res = min(res,a[i]);
            }
            cout << res << '\n';
        }
    }
    return 0;
}