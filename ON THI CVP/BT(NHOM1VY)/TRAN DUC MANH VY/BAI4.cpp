#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e7+7;
ll a[MAXN];


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    while(m--) {
        ll r;
        cin >> r;
        ll water = 0;
        for(int i = 1;i <= n;i++) {
            water += min(a[i],r);
            a[i] -= min(a[i],r);
        }
        if(water == 0) return 0;
        cout << water << ' ';
    }
    return 0;
}