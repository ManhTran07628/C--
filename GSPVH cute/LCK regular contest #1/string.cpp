#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 26 + 7;
int x,y,k,c[MM],exist[MM];
vector<string> vec;

void dfs(int id, int sz, string s)
{
    if(k == 0) return;
    if(id > sz) {
        if(k > 0) {
            vec.push_back(s);
            k--;
        }
        return;
    }


    for(int i = 1;i <= 26;i++) {
        char ch = 'a' + i - 1;
        if(exist[i] + 1 <= c[i]) {
            exist[i]++;
            dfs(id + 1,sz,s + ch);
            exist[i]--;
        }
        if(k == 0) return;
    }
}

void solve()
{
    cin >> y >> k;
    for(int i = 1;i <= 26;i++) cin >> c[i];
    for(int i = y;i >= x;i--) {
        dfs(1,i,"");
        if(k == 0) break;
    }

    
    if(k == 0) {
        cout << "YES" << '\n';
        for(auto str:vec) cout << str << ' ';
        cout << '\n';
    }
    else cout << "NO" << '\n';

    vec.clear();
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "string"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    while(cin >> x) {
        solve();
    }
    
    // cout << k;
    return 0;
}