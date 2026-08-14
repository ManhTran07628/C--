#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 3e5 + 7;
int n,a[MM],L_lower[MM],R_lower[MM],L_upper[MM],R_upper[MM];
int equal_L[MM],equal_R[MM],lim = 0;

void coordcompress()
{
    vector<int> v;
    for(int i = 1;i <= n;i++) v.push_back(a[i]);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    lim = max(lim,(int) v.size());
    for(int i = 1;i <= n;i++) {
        a[i] = lower_bound(v.begin(),v.end(),a[i]) - v.begin() + 1;
    }
}

int st[MM * 4];

void build(int id,int l,int r)
{
    if(l == r) {
        st[id] = 0;
        return;
    }
    int mid = (l + r) / 2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id] = 0;
}

void update(int id,int l,int r,int pos,int val)
{
    if(l > pos || r < pos) return;
    if(l == r) {
        st[id] += val;
        return;
    }
    int mid = (l + r) / 2;
    update(id*2,l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);
    st[id] = st[id*2] + st[id*2+1];
}

int get(int id,int l,int r,int u,int v)
{
    if(u > v) return 0;
    if(l > v || r < u) return 0;
    if(u <= l && r <= v) return st[id];
    int mid = (l + r) / 2;
    return get(id*2,l,mid,u,v) + get(id*2+1,mid+1,r,u,v);
}

namespace subtask12
{
    void solve()
    {
        ll res = 0;
        for(int j = 1;j <= n;j++) {
            for(int i = 1;i < j;i++)
                for(int k = j + 1;k <= n;k++) {
                    if((a[i] <= a[j] && a[j] >= a[k]) || (a[i] >= a[j] && a[j] <= a[k])) res++;

                }
        }
        cout << res;
    }
}

namespace subtask4
{
    void solve()
    {
        coordcompress();
        for(int i = 1;i <= n;i++) {
            L_lower[i] = get(1,1,lim,1,a[i] - 1);
            equal_L[i] = get(1,1,lim,a[i],a[i]);
            update(1,1,lim,a[i],1);
        }
        build(1,1,lim);
        for(int i = 1;i <= n;i++) {
            L_upper[i] = get(1,1,lim,a[i] + 1,lim);
            update(1,1,lim,a[i],1);
        }
        build(1,1,lim);
        for(int i = n;i >= 1;i--) {
            // cout << i << ' ' << R_lower[i] << '\n';
            R_lower[i] = get(1,1,lim,1,a[i] - 1);
            equal_R[i] = get(1,1,lim,a[i],a[i]);
            update(1,1,lim,a[i],1);
        }
        build(1,1,lim);
        for(int i = n;i >= 1;i--) {
            R_upper[i] = get(1,1,lim,a[i] + 1,lim);
            update(1,1,lim,a[i],1);
        }

        ll res = 0;
        for(int i = 1;i <= n;i++) {
            res += 1ll * L_lower[i] * R_lower[i];
            res += 1ll * L_upper[i] * R_upper[i];
            res += 1ll * equal_L[i] * equal_R[i];
            res += 1ll * equal_L[i] * R_lower[i];
            res += 1ll * equal_L[i] * R_upper[i];
            res += 1ll * L_lower[i] * equal_R[i];
            res += 1ll * L_upper[i] * equal_R[i];
        }
        cout << res;
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
    for(int i = 1;i <= n;i++) cin >> a[i];
    subtask4::solve();
    return 0;
}