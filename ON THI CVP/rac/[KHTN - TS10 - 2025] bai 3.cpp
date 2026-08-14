#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
pair<int,int> a[MAXN];

bool cmp(pair<int,int> a,pair<int,int> b)
{
    if(a.fi != b.fi) return a.fi > b.fi;
    return a.se > b.se;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].se >> a[i].fi;
        a[i].fi = a[i].fi*a[i].se;
    }
    sort(a+1,a+n+1,cmp);
    
    return 0;
}
