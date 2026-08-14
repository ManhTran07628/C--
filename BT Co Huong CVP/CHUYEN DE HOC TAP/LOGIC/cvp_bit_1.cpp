#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
int t;
int a[MM],cur[MM],nxt[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        int z,n;
        cin >> z >> n;
        for(int i = 1;i <= n;i++) cin >> a[i];

        bool ok = 0;
        for(int i = 1;i <= n;i++) {
            z = z & a[i];
        }
        if(!z) ok = 1;


        cout << (ok ? "Yes" : "No") << '\n';


    }
    return 0;
}