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
    int a,b;
    cin >> a >> b;
    for(int i = 1;i <= 1000000000;i++) {
        if((a+i)%b ==0 && (b+i)%a == 0) {
            cout << a << ' ' << b << ' ' << i;
            return 0;
        }
    }
    return 0;
}