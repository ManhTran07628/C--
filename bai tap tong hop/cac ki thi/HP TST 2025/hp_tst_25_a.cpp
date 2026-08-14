#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 3e5 + 7;
int n,m,ans[MM];
pii coord[MM];
struct SQ{int x,y,u,v,id;} sq[MM];

void process()
{
    vector<int> vec;
    for(int i = 1;i <= n;i++) vec.push_back(coord[i].se);
    for(int i = 1;i <= m;i++) {
        vec.push_back(sq[i].y);
        vec.push_back(sq[i].v);
    }
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    for(int i = 1;i <= n;i++) {
        coord[i].se = lower_bound(vec.begin(),vec.end(),coord[i].se) - vec.begin() + 1;
    }
    for(int i = 1;i <= m;i++) {
        sq[i].y = lower_bound(vec.begin(),vec.end(),sq[i].y) - vec.begin() + 1;
        sq[i].v = lower_bound(vec.begin(),vec.end(),sq[i].v) - vec.begin() + 1;
    }
}

void solve1()
{
    unordered_map<int,vector<int>> List;
    for(int i = 1;i <= n;i++) {
        int x = coord[i].fi, y = coord[i].se;
        List[x].push_back(y);
    }

    // for(auto y:List[4]) cout << y << ' ';
    for(auto &x:List) {
        sort(x.se.begin(),x.se.end());
    }

    for(int i = 1;i <= m;i++) {
        int x = sq[i].x, y = sq[i].y, u = sq[i].u, v = sq[i].v;
        ans[i] += upper_bound(List[x].begin(),List[x].end(),v)
            - lower_bound(List[x].begin(),List[x].end(),y);
            
        if(x != u) {
            ans[i] += upper_bound(List[u].begin(),List[u].end(),v)
                - lower_bound(List[u].begin(),List[u].end(),y);
        }
    }
}

struct Event{int x,y,id,type;};
vector<Event> events;

// type == 1 : start
// type == 2 : end
// type == 3 : point

bool cmp(Event a,Event b)
{
    if(a.x != b.x) return a.x < b.x;
    return a.type < b.type;
}


const int MMAX = 1e6 + 7;
int bit[MMAX];

void update(int x,int val)
{
    for(;x < MMAX;x += (x & -x)) bit[x] += val;
}

int get(int x)
{
    int res = 0;
    for(;x > 0;x -= (x & -x)) res += bit[x];
    return res;
}

void solve2()
{
    for(int i = 1;i <= n;i++) {
        int x = coord[i].fi , y = coord[i].se;
        events.push_back({x,y,-1,3});
    }
    for(int i = 1;i <= m;i++) {
        int x = sq[i].x, y = sq[i].y, u = sq[i].u, v = sq[i].v;
        
        if(x + 1 > u) continue;

        events.push_back({x + 1,y,i,1});
        events.push_back({u,y,i,2});
        
        if(y != v) {
            events.push_back({x + 1,v,i,1});
            events.push_back({u,v,i,2});
        }
    }

    sort(events.begin(),events.end(),cmp);
    for(auto E:events) {
        int x = E.x, y = E.y, type = E.type, id = E.id;
        if(type == 3) update(y,1);
        else {
            int val = get(y) - get(y - 1);
            if(type == 1) ans[id] -= val;
            else ans[id] += val;
        }
    }
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
    for(int i = 1;i <= n;i++) cin >> coord[i].fi >> coord[i].se;
    cin >> m;
    for(int i = 1;i <= m;i++) {
        cin >> sq[i].x >> sq[i].y >> sq[i].u >> sq[i].v;
        sq[i].id = i;
    }
    process();
    solve1();
    solve2();
    for(int i = 1;i <= m;i++) cout << ans[i] << '\n';

    return 0;
}
