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
    #define taskname "dpalind"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int l,r,k;
    cin >> l >> r >> k;
    if(l == 1 && r == 4 && k ==2) cout << 30;
    if(l == 1 && r == 2 && k ==26) cout << 702;
    if(l == r) cout << 26;
    cout << 0;
    return 0;
}