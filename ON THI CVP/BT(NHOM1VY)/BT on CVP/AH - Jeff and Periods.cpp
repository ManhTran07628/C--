#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e5+7;
int a[MAXN];
vector<int> v[MAXN];
map<int,int> d;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        v[a[i]].push_back(i);
        d[a[i]]++;
    }
    int ans = 0;
    for(auto p:d) {
        if(p.se == 1) {
            ans++;
            continue;
        }
        int c = 0,kt = 1;
        for(int i = 0;i < v[p.fi].size();i++) {
            if(i == 0) {    
                c = v[p.fi][i+1] - v[p.fi][i];
                continue;
            }
            if(v[p.fi][i] - c != v[p.fi][i-1]) kt = 0;
        }
        if(kt) ans++;
    }
    cout << ans << '\n';
    for(auto p:d) {
        if(p.se == 1) {
            cout << p.fi << ' ' << 0 << '\n';
            continue;
        }
        int c = 0,kt = 1;
        for(int i = 0;i < v[p.fi].size();i++) {
            if(i == 0) {    
                c = v[p.fi][i+1] - v[p.fi][i];
                continue;
            }
            if(v[p.fi][i] - c != v[p.fi][i-1]) kt = 0;
        }
        if(kt) cout << p.fi << ' ' << c << '\n';
    }
    return 0;
}