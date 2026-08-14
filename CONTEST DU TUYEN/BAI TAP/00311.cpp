#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9
#define pii pair<int,int>
const int MM = 2e5 + 7;
int n, max_sz = 0;
struct Items
{
    int h,w,id;
} items[MM];

bool cmp(Items a,Items b)
{
    if(a.h != b.h) return a.h < b.h;
    return a.w < b.w;
}

void compress()
{
    vector<int> vec;
    for(int i = 1;i <= n;i++) {
        vec.push_back(items[i].h);
        vec.push_back(items[i].w);
    }
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()));
    for(int i = 1;i <= n;i++) {
        items[i].h = lower_bound(vec.begin(),vec.end(),items[i].h) - vec.begin() + 1;
        items[i].w = lower_bound(vec.begin(),vec.end(),items[i].w) - vec.begin() + 1;
    }
    max_sz = vec.size() + 5;
}

pii st[MM * 4];

pii Merge(pii a,pii b)
{
    if(a.fi > b.fi) return a;
    return b;
}

void update(int id,int l,int r,int pos,int val,int new_id)
{
    if(l > pos || r < pos) return;
    if(l == r) {
        if(st[id].fi < val) {
            st[id].fi = val;
            st[id].se = new_id;
        }
        return;
    }
    int mid = (l + r) / 2;
    update(id*2,l,mid,pos,val,new_id);
    update(id*2+1,mid+1,r,pos,val,new_id);
    st[id] = Merge(st[id*2],st[id*2+1]);
}

pii get(int id,int l,int r,int u,int v)
{
    if(l > v || r < u) return {};
    if(u <= l && r <= v) return st[id];
    int mid = (l + r) / 2;
    return Merge(get(id*2,l,mid,u,v), get(id*2+1,mid+1,r,u,v));
}

int trace[MM];

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
        cin >> items[i].h >> items[i].w;
        if(items[i].h > items[i].w) swap(items[i].h,items[i].w);
        items[i].id = i;
    }
    compress();
    sort(items+1,items+n+1,cmp);
    int best_val = 0;
    for(int i = 1;i <= n;i++) {
        int w = items[i].w, h = items[i].h;
        pii cur = get(1,0,max_sz,1,w);
        int new_val = cur.fi + 1;
        trace[i] = cur.se;
        best_val = max(best_val,new_val);
        update(1,0,max_sz,w,new_val,i);
    }

    pii cur = get(1,0,max_sz,1,max_sz);
    int pos = cur.se;

    // for(int i = 1;i <= n;i++) cout << trace[i] << ' ';
    // cout << pos << ' ' << trace[pos] << ' ' << trace[ trace[pos] ];

    vector<int> vec;

    while(pos != 0) {
        vec.push_back(pos);
        pos = trace[pos];
    }

    reverse(vec.begin(),vec.end());
    cout << best_val << '\n';
    for(auto e:vec) cout << items[e].id << ' ';
    return 0;
}