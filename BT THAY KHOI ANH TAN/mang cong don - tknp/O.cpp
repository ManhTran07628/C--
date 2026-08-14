#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN],l[MAXN];
pair<int,int> r[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,p;
    cin >> n >> p;
    int min1 = 1e9;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        min1 = min(min1,a[i]);
        l[i] = min1;
    }
    for(int i = n;i >= 1;i--) {
        r[i].fi = max(a[i],r[i+1].fi);
        r[i].se = i;
    }
    reverse(r+1,r+n+1);
    int L = 0,R = 0,ans = 0;
    for(int i = 1;i <= n;i++) {
        int j = lower_bound(r+1,r+n+1,make_pair(l[i]+p,-1))-r;
        if(i < r[j].se) {
            if(r[j].se-i+1 > ans) {
                ans = r[j].se-i+1;
                L = i;R = r[j].se;
            }
        }
    }
    if(ans != 0) cout << L << ' ' << R;
    else cout << 0;
    return 0;
}