#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 3e5 + 7;
int numItem;
ll d,r;
struct Item
{
    ll l = 0,w = 0,b = 0;
    int id = 0;
    
    void Rotate()
    {
        swap(l,w); id = -id;
    }
} items[MM];

bool cmp(Item a,Item b)
{
    return a.l < b.l;
}

ll dp[MM];
int trace[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "envelopes"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> numItem >> d >> r;
    for(int i = 1;i <= numItem;i++) cin >> items[i].l;
    for(int i = 1;i <= numItem;i++) cin >> items[i].w;
    for(int i = 1;i <= numItem;i++) cin >> items[i].b;

    for(int i = 1;i <= numItem;i++) {
        items[i].id = i;
        if(d < r && items[i].l > items[i].w) items[i].Rotate();
        if(d > r && items[i].l < items[i].w) items[i].Rotate();
    }

    sort(items+1,items+numItem+1,cmp);
    
    ll res = -oo, last_id = 0;
    for(int i = 1;i <= numItem;i++) {
        dp[i] = -oo;
        if(d < items[i].l && r < items[i].w) dp[i] = items[i].b;
        if(dp[i] == -oo) continue;
        for(int j = 1;j < i;j++) {
            if(dp[j] == -oo) continue;
            if(items[i].w > items[j].w && items[i].l > items[j].l) {
                if(dp[j] + items[i].b > dp[i]) {
                    dp[i] = max(dp[i],dp[j] + items[i].b);
                    trace[i] = j;
                }
            }
        }
        if(res < dp[i]) {
            res = dp[i];
            last_id = i;
        }
    }
    if(res != -oo) {
        cout << res << '\n';
        vector<int> vec;
        while(last_id != 0) {
            vec.push_back(items[last_id].id);
            last_id = trace[last_id];
        }
        reverse(vec.begin(),vec.end());
        cout << vec.size() << '\n';
        for(auto e:vec) cout << e << ' ';
    }
    else cout << 0 << '\n' << 0;
    return 0;
}