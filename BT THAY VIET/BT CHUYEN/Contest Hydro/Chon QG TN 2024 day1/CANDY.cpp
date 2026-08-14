#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 500+7;
ll m,T,d[MM],N[MM];

void readinput()
{
    cin >> m >> T;
    for(int i = 1;i <= m;i++) cin >> d[i];
    for(int i = 1;i <= T;i++) cin >> N[i];
}

namespace subtask1
{
    bool checksub1()
    {
        for(int i = 1;i <= m;i++) {
            if(d[i] != 1) return 0;
        }
        return (m <= 5 && T <= 3);
    }

    void solve()
    {
        for(int q = 1;q <= T;q++) {
            int mini = N[q] % m;
            cout << mini << ' ';
        }
    }
}

namespace subtask23
{

    vector<int> qr;
    ll res = 0,ans = oo;

    bool checksub2()
    {
        return (m <= 5 && T <= 3);
    }

    void Try(int id,int candy_left)
    {
        if(id > m) {
            if(candy_left > 0) return;
            ll total_p = 0;
            for(int i = 0;i < qr.size();i++) {
                ll mx = 0;
                if(qr[i]) continue;
                for(int j = 0;j < qr.size();j++) {
                    if(i == j) continue;
                    if(qr[j]) mx += qr[j];
                }
                total_p += mx * d[i+1];
            }
            ans = min(ans,total_p);
            return;
        }
        if(candy_left > 0) {
            qr.push_back(1);
            Try(id+1,candy_left-1);
            qr.pop_back();
        }
        qr.push_back(0);
        Try(id+1,candy_left);
        qr.pop_back();
    }

    void solve()
    {
        for(int q = 1;q <= T;q++) {
            int mini = N[q] % m;
            if(!mini) {
                cout << 0 << ' ';
                continue;
            }
            Try(1,mini);
            cout << ans << ' ';
            ans = oo;
            qr.clear();
        }
    }
}



signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    readinput();
    // if(subtask1::checksub1()) subtask1::solve();
    subtask23::solve();
    return 0;
}