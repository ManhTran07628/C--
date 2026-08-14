#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 2e6+7;
int a[MAXN];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,s;
    cin >> n >> s;
    int d = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        a[n+i] = a[i];
        d += a[i];
    }
    if(d < s) {
        cout << -1;
        return 0;
    }
    n+=n;
    int i = 1,j = 1,length = n,sum = 0;
    while(i <= n && j <= n) {
        sum += a[j];
        while(sum - a[i] >= s) {
            sum -= a[i];
            i++;
        }
        if(sum >= s) length = min(length,j-i+1);
        j++;
    }
    cout << (length == n ? -1:length);
    return 0;
}