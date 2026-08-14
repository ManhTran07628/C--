#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define oo 1e18
const int MM = 1e5+7;
int n,m,x[MM],L[MM],R[MM];
pair<int,int> a[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a+1,a+n+1);
    for(int i = 1;i <= n;i++) {
        L[i] = a[i].first;
        R[i] = a[i].second;
    }
    cin >> m;
    for(int i = 1;i <= m;i++) {
        cin >> x[i];
    }
    int low = x[1],high = x[1],id = 1,cnt = 0;
    for(int i = 1; i <= m;i++) {
        bool ok = 0;
        int r = lower_bound(R+1,R+n+1,x[i])-R;
        if(L[r] > x[i] || r == n+1) {
            cout << -1;
            return 0;
        }
        if(x[i] > high) {
            if(id == r) high = max(high,R[r]);
            else ok = 1;
        }
        else if(x[i] < low) {
            if(id == r) low = min(low,L[r]);
            else ok = 1;
        }
        if(ok) {
            low = L[r],high = R[r];
            id = r;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}