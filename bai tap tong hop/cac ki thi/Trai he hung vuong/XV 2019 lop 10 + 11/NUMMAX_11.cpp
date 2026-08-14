#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7;
const int LOG = 17;
int n,b,a[MM],st[MM][LOG + 1];

int get(int l,int r)
{
    int k = __lg(r - l + 1);
    return max(st[l][k],st[r - (1 << k) + 1][k]);
}

ll f(int k)
{
    ll cnt = 0;
    for(int i = 1, j = 1; j <= n; j++) {
        while(i <= j && get(i,j) > k) i++;
        if(i <= j) 
            cnt += j - i + 1;
    }
    return cnt;
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
    cin >> n >> b;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        st[i][0] = a[i];
    }

    for(int j = 1;j <= LOG;j++) {
        for(int i = 1;i + (1 << j) - 1 <= n;i++) {
            st[i][j] = max(st[i][j - 1],st[i + (1 << (j - 1))][j - 1]);
        }
    }

    // cout << get(3,3);
    cout << f(b) - f(b - 1);

    return 0;
}