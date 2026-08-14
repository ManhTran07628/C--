#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
const int LOG = 20;
int n,k,a[MM],posL[MM];
ll ps[MM];
int st[MM][LOG + 1];

int get(int L,int R)
{
    int k = __lg(R - L + 1);
    return __gcd(st[L][k],st[R - (1 << k) + 1][k]);
}

int binsL(int l,int r,int id)
{
    int pos = 0;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(get(mid,id) >= a[id]) {
            pos = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return pos;
}

namespace subtask1
{
    void solve()
    {
        ll res = 0;
        for(int i = 1;i <= n;i++) {
            int x = a[i];
            ll sum = 0;
            for(int j = i;j <= n;j++) {
                sum += a[j];
                x = __gcd(x,a[j]);
                if(j - i + 1 >= k) 
                    res = max(res,(ll) sum * x);
            }
        }
        cout << res << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        st[i][0] = a[i];
        ps[i] = ps[i-1] + a[i];
    }
    for(int j = 1;j <= LOG;j++)
        for(int i = 1;i + (1 << j) - 1 <= n;i++)
            st[i][j] = __gcd(st[i][j-1],st[i + (1 << (j - 1))][j-1]);

    ll res = k;
    for(int i = 1;i <= n;i++) {
        int L = binsL(1,i,i);
        posL[i] = L;
    }
    posL[1] = 0;
    for(int R = 1;R <= n;R++) {
        int L = R;
        while(posL[L] > 0 && get(posL[L],R) > 1) {
            if(R - posL[L] + 1 >= k)
                res = max(res,1ll * (ps[R] - ps[ posL[L] - 1 ]) * get(posL[L],R));
            L = posL[L] - 1;
        }
    }
    cout << max(res,ps[n]);
    return 0;
}
