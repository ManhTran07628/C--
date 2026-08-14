#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e5+7;
ll m,n,mp[MM];

struct dl{ll nums,cost,id;} a[MM];


void init()
{
    cin >> m >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].nums >> a[i].cost;
        a[i].id = i;
    }
}

void solve()
{
    sort(a+1,a+n+1,[] (dl &a,dl &b){
        if(a.cost != b.cost) return a.cost < b.cost;
        return a.nums > b.nums;
    });

    
    ll cost = 0,total = 0;
    for(int i = 1;i <= n;i++) {
        if(total + a[i].nums <= m) {
            total += a[i].nums;
            cost += 1ll * a[i].nums * a[i].cost;
            mp[ a[i].id ] = a[i].nums;
        }
        else {
            cost += 1ll * (m - total) * a[i].cost;
            mp[ a[i].id ] = (m - total);
            break;
        }

    }
    cout << cost << '\n';
    for(int i = 1;i <= n;i++) cout << mp[i] << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    solve();
    return 0;
}