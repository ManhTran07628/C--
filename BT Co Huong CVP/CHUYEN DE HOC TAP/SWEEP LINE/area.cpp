#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9
const int MM = 1e5 + 7;
int n;
struct Rectangle{int x,min_y,max_y,type;};
vector<Rectangle> events;

struct Node{int len,cnt;} st[MM * 4];

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
        int X1,Y1,X2,Y2; cin >> X1 >> Y1 >> X2 >> Y2;
        events.push_back({X1,Y1,Y2,1});
        events.push_back({X2,Y1,Y2,2});
    }
    // update(1,0,MM - 1,10,20,1);
    // cout << st[1].cnt;
    sort(events.begin(),events.end(),[] (Rectangle a,Rectangle b){return a.x < b.x;});
    int last_x = events[0].x;
    ll res = 0;
    for(auto id:events) {
        res += 1ll * (id.x - last_x) * st[1].len;
        // cout << id.x << ' ' << last_x << ' ' << st[1].len << '\n';
        // cout << id.x << ' ' << id.min_y << ' ' << id.max_y << ' ' << id.type << '\n';

        if(id.type == 1) update(1,0,MM - 1,id.min_y,id.max_y - 1,1);
        else update(1,0,MM - 1,id.min_y,id.max_y - 1,-1);

        last_x = id.x;
    }
    cout << res;
    return 0;
}