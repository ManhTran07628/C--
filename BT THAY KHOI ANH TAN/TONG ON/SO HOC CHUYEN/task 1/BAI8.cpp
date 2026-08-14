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
    int a;
    cin >> a;
    for(int x = 1;x <= a;x++) {
        if(a*a % x == 0) {
            int y = a*a/x;
            if((x+y)%2==0 && (y-x)%2==0 && x < y) {
                cout << a << ' ' << (y-x)/2 << ' ' << (x+y)/2 << '\n';
            }
        }
    }
    return 0;
}