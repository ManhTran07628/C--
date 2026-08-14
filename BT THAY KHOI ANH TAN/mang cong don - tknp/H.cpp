    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define fi first
    #define se second
    const int MAXN = 1e6+7;
    ll a[MAXN],vt[MAXN];

    int main()
    {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int n;
        cin >> n;
        for(int i = 1;i <= n;i++) {
            cin >> a[i];
            vt[i] = a[i-1] + 1;
            a[i] += a[i-1];
        }
        int q;
        cin >> q;
        while(q--) {
            ll x;
            cin >> x;
            ll s = lower_bound(a+1,a+n+1,x)-a;
            if(s == n+1) cout << -1 << ' ';
            else cout << s << ' ';
        }
        return 0;
    }