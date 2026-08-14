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
    int x = n / 1.08;
    for(int i = max(0LL,x-10);i <= x+10;i++) {
        int p = i*1.08;
        if(p == n) {
            cout << i;
            return 0;
        }
    }
    cout << ":(";
    return 0;
}