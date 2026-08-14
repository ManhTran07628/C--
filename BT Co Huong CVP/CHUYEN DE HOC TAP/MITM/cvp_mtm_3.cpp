#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<ll,int>
const int MM = 31;
int n;
ll a[MM],M;
vector<ll> A[MM],B[MM];

void Try(int l,int r,int id,ll sum,vector<ll> f[],int cnt)
{
    if(id == r + 1) {
        if(cnt == 0) return;
        f[cnt].push_back(sum);
        return;
    }
    Try(l,r,id + 1,sum + a[id],f,cnt+1);
    Try(l,r,id + 1,sum,f,cnt);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> M; 
    ll sum = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        sum += a[i];
    }
    Try(1, n/2+1, 1, 0, A, 0);
    Try(n/2+1, n, n/2+1, 0, B, 0);
    int lim = (n + 1) / 2;
    A[0].push_back(0);
    B[0].push_back(0);
    ll res = oo;
    for(int i = 0;i <= lim;i++) {
        for(auto x: A[i]) {
            for(auto y : B[lim - i]) {
                ll u = x + y;
                ll v = sum - (x + y);
                // cout << i << ' ' << lim - i << ' ' << u << ' ' << v << '\n';
                res = min(res,abs(u - v - M));
                res = min(res,abs(v - u - M));
            }
        }
    }
    cout << res;
    return 0;
}
