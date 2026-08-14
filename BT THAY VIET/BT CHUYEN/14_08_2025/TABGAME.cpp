#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 17;
int h,w;
ll a[MM][MM],s;

void readinput()
{
    cin >> h >> w;
    for(int i = 1;i <= h;i++) {
        for(int j = 1;j <= w;j++) {
            cin >> a[i][j];
        }
    }
    cin >> s;
}

namespace subtask1
{
    bool ok = 0;
    ll totals = 0;
    vector<int> row,ans;
    bool check()
    {
        return h == 1;
    }

    void Try(int id,ll mn)
    {
        if(id > w) {
            if(ok) return;
            if(totals - mn == s) {
                for(auto i:row) ans.push_back(i);
                ok = 1;
            }
            return;
        }

        for(int i = id;i <= w;i++) {
            row.push_back(i);
            Try(i+1,mn + a[h][i]);
            row.pop_back();
        }
    }

    void solve()
    {
        for(int i = 1;i <= h;i++) {
            for(int j = 1;j <= w;j++) {
                totals += a[i][j];
            }
        }
        Try(1,0);
        if(ok) {
            cout << "YES" << '\n';
            cout << ans.size() << '\n';
            for(auto i:ans) {
                cout << 2 << ' ' << i << '\n';
            }
        }
        else cout << "NO";
    }
}

namespace solb
{
    int row[MM],col[MM],ans[MM];
    vector<int> rowA,colA;
    bool ok = 0;

    void Try(int id)
    {
        if(id > w) {
            if(ok) return;
            ll sum = 0;
            for(int i = 1;i <= h;i++) {
                for(int j = 1;j <= w;j++) {
                    if(row[i] || col[j]) continue;
                    sum += a[i][j];
                }
            }
            if(sum == s) {
                for(int i = 1;i <= h;i++) if(row[i]) rowA.push_back(i);
                for(int i = 1;i <= w;i++) if(col[i]) colA.push_back(i);
                ok = 1;
            }
            return;
        }

        for(int i = id;i <= w;i++) {
            col[i] = 1;
            Try(i+1);
            col[i] = 0;
        }
    }


    void solve()
    {
        for(int mask = 0;mask < (1 << h);mask++) {
            for(int i = 0;i < h;i++) {
                if(mask >> i & 1) row[i+1] = 1;
            }
            Try(1);
            for(int i = 0;i < h;i++) row[i+1] = 0;
            if(ok == 1) break;
        }
        if(ok) {
            cout << "YES" << '\n';
            cout << rowA.size() + colA.size() << '\n';
            for(auto i:rowA) {
                cout << 1 << ' ' << i << '\n';
            }
            for(auto i:colA) {
                cout << 2 << ' ' << i << '\n';
            }
        }
        else cout << "NO";
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    readinput();
    // if(subtask1::check()) subtask1::solve();
    solb::solve();
    return 0;
}