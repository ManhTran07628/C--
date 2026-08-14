    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    const int N = 1e6 + 7;
    ll a[N],b[N];
    map<ll,ll> c;
    int main() {
        freopen("SELESHIRT.inp","r",stdin);
        freopen("SELESHIRT.out","w",stdout);
        ll n,m,x,y;
        cin >> n >> m >> x >> y;
        for(int i = 1;i <= n;i++) {
            cin >> a[i];
        }
        for(int i = 1;i <= m;i++) {
            cin >> b[i];
        }
        ll dem = 0;
        sort(b+1,b+m+1);
        for(int i = 1;i <= n;i++) {
            ll L = 1,R = m;
            ll u = -1,v = -1;
            while(L <= R) {
                ll mid = (L+R)/2;
                ll vtd = b[mid] - x,vtc = b[mid] + y;
                if(a[i] >= vtd && a[i] <= vtc && c[b[mid]] == 0) {
                    c[b[mid]]++;
                    dem++;
                    R = mid - 1;
                }
                else {
                    L = mid + 1;
                }
            }
            if(u != -1) {
                cout << u << " " << v;
            }
        }
        cout << dem;
        return 0;
    }
