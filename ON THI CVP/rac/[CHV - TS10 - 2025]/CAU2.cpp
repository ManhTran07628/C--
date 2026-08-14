#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int divs[MAXN],a[MAXN];

void build()
{
    for(int i = 1;i < MAXN;i++) 
        for(int j = i;j < MAXN;j+=i)
            divs[j]++;

}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    build();
    int n,q;
    cin >> n >> q;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        a[i] = divs[a[i]] + a[i-1];
    }
    while(q--) {
        int l,r;
        cin >> l >> r;
        cout << a[r]-a[l-1] << '\n';
    }
    return 0;
}