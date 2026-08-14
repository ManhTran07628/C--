#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e3;
const int lim = 1e4;
int n;
struct Node{ll weight,lim,val;} a[lim + 5];
ll dp[(int) 2e7 + 7];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int maxcap = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].weight >> a[i].lim >> a[i].val;
        maxcap += a[i].weight;
    }
    sort(a+1,a+n+1,[] (Node a,Node b){
        return a.lim + a.weight < b.lim + b.weight;
    });
    for(int i = 1;i <= n;i++) {
        for(int cur_weight = lim;cur_weight >= 0;cur_weight--) {
            if(a[i].lim >= cur_weight) {
                ll nxt = cur_weight + a[i].weight;
                dp[nxt] = max(dp[nxt],dp[cur_weight] + a[i].val);
            } 
        }
    }
    ll res = 0;
    for(int i = 0;i <= maxcap;i++) {
        res = max(res,dp[i]);
    }
    cout << res;
    return 0;
}
