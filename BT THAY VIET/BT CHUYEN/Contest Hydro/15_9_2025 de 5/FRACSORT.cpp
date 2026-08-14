#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
int n,q;
ll a[MM],b[MM],c[MM];

void readinput()
{
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> b[i];
    for(int i = 1;i <= q;i++) cin >> c[i];
}

struct Frac
{
    double frac;
    ll a,b;
};
vector<Frac> res;

namespace subtask12
{

    void solve()
    {
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                ll usc = __gcd(a[i],b[j]);
                ll A = a[i] / usc, B = b[j] / usc;
                double tmp = B;
                double fr = A / tmp;
                res.push_back({fr,A,B});
            }
        }

        sort(res.begin(),res.end(), [] (Frac &A, Frac &B){
            return A.frac < B.frac;
        });

        for(int i = 1;i <= q;i++) {
            cout << res[c[i]-1].a << ' ' << res[c[i]-1].b << '\n';
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    readinput();
    subtask12::solve();
    return 0;
}