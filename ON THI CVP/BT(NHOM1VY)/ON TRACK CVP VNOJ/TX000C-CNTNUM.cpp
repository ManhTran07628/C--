#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e5+7;
int a[MAXN];
vector<ll> d[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        d[a[i]].push_back(i);
    }
    while(k--) {
        int x;
        cin >> x;
        int l = lower_bound(d[a[x]].begin(),d[a[x]].end(),x) - d[a[x]].begin();
        int r = d[a[x]].size()-l-1;
        cout << l << ' ' << r << '\n';
    }
    return 0;
}