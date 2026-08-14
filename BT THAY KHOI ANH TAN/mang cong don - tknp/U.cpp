#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
ll p[MAXN],dd[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> p[i];
    }
    ll q;
    cin >> q;
    while(q--) {
        ll l,r,x;
        cin >> l >> r >> x;
        p[l] += x*2;
        p[r+1] -= x*2;
        dd[l]++;
        dd[r+1]--;
    }
    
    return 0;
}