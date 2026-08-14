#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;
int n;
multiset<int> ms;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while(n--) {
        int type,x;
        cin >> type >> x;
        if(type == 1) ms.insert(x);
        else {
            auto nums = ms.lower_bound(x);
            cout << *nums << '\n';
        }
    }
    return 0;
}