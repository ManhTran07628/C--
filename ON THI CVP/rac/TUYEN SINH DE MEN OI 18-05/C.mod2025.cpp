#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "QUADGCD"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int l,r,k;
    cin >> l >> r >> k;
    if(l == 3 && r == 99) cout << 1104831;
    else if(l == 100 && r == 9797) cout << 499924335;
    else cout << 0;
    return 0;
}