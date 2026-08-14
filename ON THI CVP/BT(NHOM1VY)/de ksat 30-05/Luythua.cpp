#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
set<int> d;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0;i <= 12;i++) {
        for(int j = 0;j <= 12;j++) {
            for(int k = 0;k <= 12;k++) {
                int d1 = pow(2,i),d2 = pow(3,j),d3 = pow(5,k);
                d.insert(d1*d2*d3);
            }
        }
    }
    int cnt = 0;
    for(auto i:d) {
        if(cnt == n) break;
        cout << i << '\n';
        cnt++;
    }
    return 0;
}   