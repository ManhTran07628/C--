#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
ll a[MAXN],d[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];    
    }
    int q;
    cin >> q;
    while(q--) {
        int l,r,x;
        cin >> l >> r >> x;
        d[l] += x;
        d[r+1] -= x;
    }
    for(int i = 1;i <= n;i++) {
        d[i] += d[i-1];
        cout << d[i]+a[i] << ' ';
    }
    return 0;
}