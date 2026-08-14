#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 3e6+7;
int n,m,par[MM],nextnum[MM],ans[MM];

void make_sets()
{
    for(int i = 1;i <= MM;i++) 
        par[i] = i;
}

int find_set(int a)
{
    if(a == par[a]) return a;
    return par[a] = find_set(par[a]);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    make_sets();
    for(int i = 1;i <= m;i++) {
        int l,r,x;
        cin >> l >> r >> x;
        int j = l,prev = -1,cur = -1;
        for(int j = find_set(l);j <= r;j = find_set(j+1)) {
            if(j == x) continue;
            ans[j] = x;
            par[j] = j + 1;
        }

    }

    for(int i = 1;i <= n;i++) cout << ans[i] << ' ';
    return 0;
}