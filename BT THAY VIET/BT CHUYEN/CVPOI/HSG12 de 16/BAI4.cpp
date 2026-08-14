#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
int n,m,c[MM];
pii pic[MM];

namespace subtask1
{
    vector<int> comps[15];
    int ans = 1;
    void solve()
    {

        for(int mask = 1;mask < (1 << m);mask++) {
            int sz = __builtin_popcount(mask);
            comps[sz].push_back(mask);
        }
        
        for(int mask = 1;mask < (1 << n);mask++) {
            vector<int> valid;
            for(int i = 0;i < n;i++)
                if(mask >> i & 1) valid.push_back(i+1);
            
            int sz = __builtin_popcount(mask);

            for(auto ma : comps[sz]) {
                vector<int> a;
                vector<pii> v;
                
                bool ok = 1;
                for(int i = 0;i < m;i++) 
                if(ma >> i & 1) a.push_back( c[i+1] );
                
                
                for(int i = 0;i < sz;i++) {

                    if(pic[ valid[i] ].fi <= a[ i ]) {  
                        v.push_back({a[i],pic[ valid[i] ].se});
                    }

                }
                if(v.size() != sz) {continue;};

                sort(v.begin(),v.end(), [] (pii a,pii b){
                    return a.se < b.se;
                });

                for(int i = 1;i < sz;i++) {
                    if(v[i-1].fi > v[i].fi) ok = 0;
                }

                if(ok) {ans = sz; break;};
            }
        }

        cout << ans;
    }

}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        cin >> pic[i].fi >> pic[i].se;
    }
    sort(pic+1,pic+n+1);
    for(int i = 1;i <= m;i++) cin >> c[i];
    subtask1::solve();
    return 0;
}