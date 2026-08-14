#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6;
int a[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,cnt = 0,add = 0;
    cin >> n;
    int mm = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        mm = max(mm,a[i]);
    }
    for(int i = 1;i <= n;i++) {
        if(a[i] < mm) {
            cnt += mm - a[i];
            add++;
        }
    }
    cout << cnt << ' ' << add;
    return 0;
}