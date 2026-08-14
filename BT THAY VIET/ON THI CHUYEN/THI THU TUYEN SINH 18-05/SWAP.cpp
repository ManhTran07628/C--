#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 3e5+7;
pair<int,pair<char,char>> a[MAXN];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int q;
    cin >> q;
    int n = s.size();
    for(int i = 1;i <= n;i++) {
        a[i].se.fi = s[i-1];
        a[i].se.se = s[n-i];
    }
    while(q--) {
        int l;
        cin >> l;
        int r = s.size()-l+1;
        a[l].fi++;
        a[r+1].fi--;
    }
    for(int i = 1;i <= n;i++) {
        a[i].fi += a[i-1].fi;
        if(a[i].fi%2==0) cout << a[i].se.fi;
        else cout << a[i].se.se;
    }

    return 0;
}