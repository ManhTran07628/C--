#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
int n,par[MM],sz[MM],vis[MM];
pii x[MM];

void make_set()
{
    for(int i = 1;i <= n;i++) {
        par[i] = i;
        sz[i] = 1;
    }
}

int find_set(int a)
{
    if(a == par[a]) return a;
    return par[a] = find_set(par[a]);
}

void Unite(int a,int b)
{
    a = find_set(a);
    b = find_set(b);
    if(a == b) return;
    if(a < b) swap(a,b);
    par[b] = a;
    sz[a] += sz[b];
    return;
}



signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "BEARS"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    make_set();
    for(int i = 1;i <= n;i++) {
        cin >> x[i].fi;
        x[i].se = i;
    }
    sort(x+1,x+n+1,greater<pii>());
    for(int i = 1,j = 1;i <= n;i++) {
        vis[ x[i].se ] = 1;
        if(vis[ x[i].se - 1 ]) Unite(x[i].se - 1,x[i].se);
        if(vis[ x[i].se + 1 ]) Unite(x[i].se + 1,x[i].se);
        while(sz[ find_set(x[i].se) ] >= j) {
            cout << x[i].fi << ' ';
            j++;
        }
    }
    return 0;
}