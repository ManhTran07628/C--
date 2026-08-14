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
    int n,m,k;
    cin >> n >> m >> k;
    int toida = min(n/2,m);
    int d1 = m+n-toida*3;
    // cout << toida << ' ' << d1;
    if(d1 < k) {
        int x = ceil((k-d1)/3.0);
        toida -= x;
    }
    cout << toida;
    return 0;
}