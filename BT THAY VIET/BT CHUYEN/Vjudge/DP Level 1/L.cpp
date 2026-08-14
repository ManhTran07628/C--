#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MM = 1e6+7;


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a,b;
    cin >> a >> b;
    int cnt = 0;
    while(a != b) {
        if(a > b) a -= b;
        else b -= a;
        cnt++;
    }
    cout << cnt;
    return 0;
}