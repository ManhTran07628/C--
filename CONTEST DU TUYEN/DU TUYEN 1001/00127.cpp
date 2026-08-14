#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9
#define pii pair<int,int>
const int MM = 1e5;
int n,t;
struct dl{int a,b,times;} f[MM + 7];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> t;
    ll res = 0;
    ll cur_dec = 0;
    for(int i = 1;i <= n;i++) {
        cin >> f[i].a >> f[i].b;
        if(f[i].b == 0) f[i].times = oo;
        else f[i].times = (f[i].a + f[i].b - 1) / f[i].b;
        res += f[i].a;
        cur_dec += f[i].b;
    }
    sort(f+1,f+n+1,[] (dl a,dl b){
        return a.times < b.times;
    });
    for(int i = 1,j = 1;i <= t+1;i++) {
        cout << res << '\n';
        while(j <= n && i * f[j].b >= f[j].a) {
            cur_dec -= f[j].b;
            res -= (f[j].a - f[j].b * (i - 1));
            j++;
        }
        res -= cur_dec;
    }
    return 0;
}