#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int n;
struct rec{int x,h,type;};
vector<rec> events;

struct Node{int cnt,len;} st[MM * 4];

void fix(int id,int l,int r)
{
    if(st[id].cnt > 0) st[id].len = r - l + 1;
    else st[id].len = st[id*2].len + st[id*2+1].len;
}

void update(int id,int l,int r,int u,int v,int val)
{
    if(l > v || r < u) return;
    if(u <= l && r <= v) {
        st[id].cnt += val;
        fix(id,l,r);
        return;
    }
    int mid = (l + r) / 2;
    update(id*2,l,mid,u,v,val);
    update(id*2+1,mid+1,r,u,v,val);
    fix(id,l,r);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    for(int i = 1;i <= n;i++) {
        int X1,X2,h; cin >> X1 >> X2 >> h;
        events.push_back({X1,h,1});
        events.push_back({X2,h,-1});
    }
    sort(events.begin(),events.end(), [] (rec a,rec b){return a.x < b.x;});
    int last_pos = events[0].x;
    ll res = 0;
    for(auto id:events) {
        res += 1ll * (id.x - last_pos) * 1ll * st[1].len;
        update(1,0,MM - 1,0,id.h - 1,id.type);
        last_pos = id.x;
    }
    cout << res;
    return 0;
}