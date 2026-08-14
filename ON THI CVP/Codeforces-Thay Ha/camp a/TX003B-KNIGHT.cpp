#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
map<int,int> a[10001];
vector<pair<int,int>> pos{{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
int n,m,u,v,ans = 0;
void backtracking(int x,int y)
{
    if(a[x][y] != 0) return;
    a[x][y] = 1;
    ans++;
    for(int i = 0;i < pos.size();i++) {
        int p1=x+pos[i].fi;
        int p2=y+pos[i].se;
        if(p1 >= 1 && p1 <= n && p2 >= 1 && p2 <= m && a[p1][p2] == 0) {
            backtracking(p1,p2);    
            return;
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> u >> v;
    backtracking(u,v);
    cout << ans;
    return 0;
}