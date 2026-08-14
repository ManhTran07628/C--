#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int n,a[MM],h[MM],leaf = 0,cnt = 0;


void dfs(int node,int parent) // 1
{
    if(node > n) return;

    if(node * 2 <= n) dfs(node * 2,node); 
    if(node * 2 + 1 <= n) dfs(node * 2 + 1,node);

    if(node * 2 > n && node * 2 + 1 > n) leaf++;
    if(node * 2 > n || node * 2 + 1 > n) cnt++;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    dfs(1,0);
    cout << leaf << '\n' << cnt - leaf;
    return 0;
}