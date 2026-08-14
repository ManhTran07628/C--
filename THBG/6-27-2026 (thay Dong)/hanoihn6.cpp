#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6 + 7;
char num[] = {'A','B','C','D'};
vector<pii> res;

void dfs3(int n,int start,int end,int mid)
{
    if(n == 1) {
        res.push_back({start,end});
        return;
    }
    dfs3(n - 1,start,mid,end);
    dfs3(1,start,end,mid);
    dfs3(n - 1,mid,end,start);
}

void dfs(int n,int start,int end,int m1,int m2)
{
    if(n == 1) {
        res.push_back({start,end});
        return;
    }

    ll k = max(1,n - 10);
    dfs(k,start,m1,end,m2);
    dfs3(n - k,start,end,m2);
    dfs(k,m1,end,start,m2);
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
    ll n; cin >> n;
    // cout << (1 << n) - 1 << '\n';
    dfs(n,0,3,1,2);
    cout << res.size() << '\n';
    for(auto E:res) cout << num[E.fi] << num[E.se] << '\n';
    return 0;
}


















// dfs(n,a,b)
// c = 3 - a - b  
// dfs(n - 1,a,c) 
// dfs(1,a,b)
// dfs(n - 1,c,b)