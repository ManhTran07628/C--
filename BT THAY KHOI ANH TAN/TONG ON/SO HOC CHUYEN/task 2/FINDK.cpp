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
    int n;
    cin >> n;
    int k = sqrt(n*2);
    while(1) {
        int sum = k*(k+1)/2;
        if(sum <= n) break;
        k--;
    }
    cout << k;
    return 0;
}