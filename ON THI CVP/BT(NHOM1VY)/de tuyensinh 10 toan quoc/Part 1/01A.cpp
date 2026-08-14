#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll ans = 0;
    cin >> n;
    while(n--) {
        string p;
        cin >> p;
        ll so = 0;
        for(int i = 0;i < p.size()-1;i++) so = so*10+(p[i]-'0');
        ll mu = p[p.size()-1]-'0';
        so = pow(so,mu);
        ans += so;
    }
    cout << ans;
    return 0;
}