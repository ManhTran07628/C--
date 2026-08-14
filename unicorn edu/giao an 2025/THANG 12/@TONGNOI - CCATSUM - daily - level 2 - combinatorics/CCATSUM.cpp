#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e5+7;
const int MOD = 1e9 + 7;
int n,cnt[MM];
ll a[MM];

ll cntnums(int k)
{
    int res = 0;
    while(k > 0) {
        res++;
        k /= 10;
    }
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "CCATSUM"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    ll res = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        res += a[i] * (n - 1);
        cnt[ cntnums(a[i]) ]++;
        res %= MOD;
    }
    for(int i = 1;i <= n;i++) {
        ll k = a[i];
        for(int j = 1;j <= 10;j++) {
            k *= 10; k %= MOD;
            if(cntnums(a[i]) == j) res += k *(cnt[j] - 1) ;
            else res += k * cnt[j];
            res %= MOD;
        }
    }
    cout << res;

    return 0;
}