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
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 1;i <= n-3;i++) {
        ans += i*(n-2-i);
    }
    cout << ans * n / 4;
    return 0;
}