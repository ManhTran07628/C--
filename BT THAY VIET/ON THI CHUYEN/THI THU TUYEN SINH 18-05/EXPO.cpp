#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;

int binpow(int a,int b,int MM) {
    int ans = 1;
    while(b > 0) {
        if(b % 2 == 1) ans = ans * a % MM;
        a = a * a % MM;
        b /= 2;
    }
    return ans;
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int ans = binpow(2,binpow(3,n,4),5);
    cout << ans;
    return 0;
}