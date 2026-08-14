#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
pair<int,int> p[51];
int d[51];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        cin >> p[i].fi >> p[i].se;
    }
    int ans = 0;
    sort(p+1,p+n+1);
    for(int i = 1;i <= n;i++) {
        if(d[a[i].fi] == 0 && d[a[i].se] == 0) {
            d[a[i].fi] = 0;
            d[a[i].se] = 0;
            ans++;
            continue;
        }
        if(d[a[i].fi] == 0)
    }
    return 0;
}