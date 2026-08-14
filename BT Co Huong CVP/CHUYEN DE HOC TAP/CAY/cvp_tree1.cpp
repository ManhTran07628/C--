#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int n,a[MM],h[MM],leaf = 0,high = 0;


void dfs(int node,int parent) // 1
{
    if(node > n) return;
    cout << a[node] << ' ';
    h[node] = h[parent] + 1;
    if(node * 2 <= n) dfs(node * 2,node); 
    if(node * 2 + 1 <= n) dfs(node * 2 + 1,node);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];

    for(int i = 1;i <= n;i++) {
        int left = i * 2;
        int right = i * 2 + 1;
        if(left > n && right > n) leaf++;
    }

    dfs(1,0); 
    cout << '\n';
    cout << leaf << '\n';
    for(int i = 1;i <= n;i++) 
        high = max(high,h[i]);
    
    cout << high;

    return 0;
}