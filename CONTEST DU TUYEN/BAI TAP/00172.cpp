#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e5 + 7;
int n,x;
vector<int> s,ps;
pii qr[MM];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    s.push_back(0);
    for(int i = 1;i <= n;i++) {
        int a; cin >> a;
        s.push_back(a >= x);
    }
    int q; cin >> q;
    for(int i = 1;i <= q;i++) {
        cin >> qr[i].fi;
        if(qr[i].fi == 1) {
            cin >> qr[i].se; 
            s.push_back(qr[i].se >= x);
        }
        if(qr[i].fi == 3) cin >> qr[i].se;
    }
    ps.resize(s.size() + 5);
    int m = s.size() - 1;
    for(int i = 1;i <= m;i++) {
        ps[i] = ps[i-1] + s[i];
        // cout << i << ' ' << ps[i] << '\n';
    }
    int del = 0;
    for(int t = 1, i = 0;t <= q;t++) {
        if(qr[t].fi == 2){
            del++;
            i++;
        }
        if(qr[t].fi == 3) {
            // cout << t << ' ';
            cout << ps[ qr[t].se + i ] - del << '\n';
        }
    }

    return 0;
}