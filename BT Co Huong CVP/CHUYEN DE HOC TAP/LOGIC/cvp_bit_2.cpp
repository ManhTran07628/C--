#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
const int LOG = 31;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a;
    cin >> a;
    int pos = LOG;
    for(;pos >= 0;pos--)
        if(a >> pos & 1) break;
    // pos++;
    // cout << pos;
    int b = 0,c = 0;
    for(int i = pos;i >= 0;i--) {
        if(a >> i & 1) b += (1 << i);
        else c += (1 << i);
    }
    cout << b << ' ' << c;
    return 0;   
}