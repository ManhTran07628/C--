#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
int n,m,a[MM];
map<int,int> lt;
void readinput()
{
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        lt[a[i]]++;
    }
}

namespace subtask1
{
    bool check()
    {
        return m <= 3;
    }

    void solve()
    {
        if(m == 1) cout << 1;
        else if(m == 2) {
            bool ok = 1;
            for(auto v:lt) if(v.se % 3 != 0) ok = 0;
            if(ok) cout << 1;
            else cout << 0;
        }
        else if(m == 3) {
            if(lt[1] == lt[2] && lt[2] == lt[3]) cout << 2;
            else if(lt[1] % 3 == lt[2] % 3 && lt[2] % 3 == lt[3] % 3) cout << 1;
            else cout << 0;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    readinput();
    if(subtask1::check()) subtask1::solve();
    else cout << 0;
    return 0;
}