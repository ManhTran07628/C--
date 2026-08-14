#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
int n,k;
int a[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int j = 1;j <= k;j++) {
        for(int i = 2;i <= n;i++) 
            a[i] |= a[i-1];
    }
    for(int i = 1;i <= n;i++) cout << a[i] << ' ';
    return 0;
}