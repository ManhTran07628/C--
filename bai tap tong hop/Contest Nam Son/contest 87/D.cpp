#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int l[MAXN],r[MAXN],x[MAXN],v[MAXN],a[MAXN];
int ans[MAXN];
map<int,vector<int>> query,dif;
vector<int> pos[MAXN];
int n,q;

void init()
{
    cin >> n >> q;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    for(int i = 1;i <= q;i++) {
        cin >> l[i] >> r[i] >> x[i] >> v[i];
    }
}

void build()
{
    init();
    for(int i = 1;i <= q;i++) {
        if(query.count(x[i])) continue;
        for(int j = x[i];j <= 500000;j += x[i]) {
            for(int idx : pos[j]) {
                query[x[i]].push_back(idx);
                dif[x[i]].push_back(0);
            }
        }
        sort(query[x[i]].begin(),query[x[i]].end());
    }
    for(int i = 1;i <= q;i++) {
        int left = lower_bound(query[x[i]].begin(),query[x[i]].end(),l[i])-query[x[i]].begin();
        int right = upper_bound(query[x[i]].begin(),query[x[i]].end(),r[i])-query[x[i]].begin();
        
        if(left < query[x[i]].size()) dif[x[i]][left] += v[i];
        if(right < query[x[i]].size()) dif[x[i]][right] -= v[i];
    }
    
    for(auto [val,d]:query) {
        int sum = 0;
        for(int i = 0;i < d.size();i++) {
            sum += dif[val][i];
            ans[d[i]] += sum;
        }
    }
}


void solve()
{
    build();
    for(int i = 1;i <= n;i++) {
        cout << ans[i] << ' ';
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}