#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9
const int MM = 5e5 + 7;
int n,a[MM],lastpos[MM],ans[MM];
vector<ll> dval;
vector<int> queries_id[MM];

namespace sol
{
    int st[MM * 4];
    void update(int id,int l,int r,int pos,int val)
    {
        if(l > pos || r < pos) return;
        if(l == r) {
            st[id] = val;
            return;
        }
        int mid = (l + r) / 2;
        update(id*2,l,mid,pos,val);
        update(id*2+1,mid+1,r,pos,val);
        st[id] = st[id*2] + st[id*2+1];
    }

    int get(int id,int l,int r,int u,int v)
    {
        if(l > v || r < u) return 0;
        if(u <= l && r <= v) return st[id];
        int mid = (l + r) / 2;
        return get(id*2,l,mid,u,v) + get(id*2+1,mid+1,r,u,v);
    }

    void compress()
    {
        vector<int> vec;
        for(int i = 1;i <= n;i++) vec.push_back(a[i]);
        sort(vec.begin(),vec.end());
        vec.erase(unique(vec.begin(),vec.end()));
        for(int i = 1;i <= n;i++) a[i] = lower_bound(vec.begin(),vec.end(),a[i]) - vec.begin() + 1;
    }

    void solve()
    {
        compress();
        for(ll i = 1;i * i <= n;i++) {
            if(n % i == 0) {
                dval.push_back(i);
                if(n / i != i) dval.push_back(n / i);
            }
        }

        sort(dval.begin(),dval.end());
        for(auto x:dval) ans[x] = oo;

        for(int i = 1;i <= n;i++) {
            for(auto v:dval) if(i % v == 0) queries_id[i].push_back(v);
        }

        for(int r = 1;r <= n;r++) {
            if(lastpos[ a[r] ] != 0) update(1,1,n,lastpos[ a[r] ],0);
            lastpos[ a[r] ] = r;
            update(1,1,n,lastpos[ a[r] ],1);

            for(auto len:queries_id[r]) {
                int l = r - len + 1;
                ans[len] = min(ans[len],get(1,1,n,l,r));
            }
        }
        cout << dval.size() << '\n';
        for(auto x:dval) cout << x << ' ' << ans[x] << '\n';

    }
}

namespace subtask1
{
    void solve()
    {
        for(ll i = 1;i * i <= n;i++) {
            if(n % i == 0) {
                dval.push_back(i);
                if(n / i != i) dval.push_back(n / i);
            }
        }

        sort(dval.begin(),dval.end());
        for(auto x:dval) ans[x] = oo;


        cout << dval.size() << '\n';
        for(auto x:dval) {
            int cur_res = oo;
            for(int l = 1;l <= n;l += x) {
                int r = l + x - 1;
                map<int,int> mp;
                int cnt = 0;
                for(int i = l;i <= r;i++) 
                    if(mp.find(a[i]) == mp.end()) {
                        mp[ a[i] ] = 1;
                        cnt++;
                    }
                cur_res = min(cur_res,cnt);
            }

            cout << x << ' ' << cur_res << '\n';
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "PEARL"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sol::solve();
    return 0;
}