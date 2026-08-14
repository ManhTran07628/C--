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
    int n,a,b;
    cin >> n >> a >> b;
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        if(i % a == 0 && i % b != 0) ans++;
        if(i % b == 0 && i % a != 0) ans++;
    }
    cout << ans;
    return 0;
}