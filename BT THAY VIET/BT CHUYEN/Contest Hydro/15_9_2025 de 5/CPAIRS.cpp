#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 2e5+7;
int t,a[MM],b[MM],n[MM];

void readinput()
{
    cin >> t;
    for(int i = 1;i <= t;i++) {
        cin >> n[i] >> a[i] >> b[i];
    }
}

namespace subtask1
{
    bool check()
    {
        return (t == 1 && a[1] <= 1000 && b[1] <= 1000);
    }
    
    void solve()
    {
        for(int q = 1;q <= t;q++) {
            ll cnt = 0;

            for(int i = 0;i <= a[q];i++) {
                for(int j = 0;j <= b[q];j++) {
                    if(i+j != 0  && (i+j) % n[q] == 0) {
                        cnt++;
                    }
                }
            }

            cout << cnt << '\n';
        }

    }
}

namespace subtask2
{
    bool check()
    {
        for(int i = 1;i <= t;i++) {
            if(a[i] != 0) return 0;
        }
        return 1;
    }

    void solve()
    {
        for(int i = 1;i <= t;i++) {
            cout << b[i] / n[i] << '\n';
        }
    }
}

namespace solb
{
    ll cntA[MM],cntB[MM];

    void solve()
    {
        for(int q = 1;q <= t;q++) {
            ll cnt = 0;

            int m = n[q];
            for(int i = 0;i < m;i++) {
                if(a[q] >= i) cntA[i] += (a[q]-i)/m+1;
                if(b[q] >= i) cntB[i] += (b[q]-i)/m+1;
            }
            cnt += (cntA[0] * cntB[0]) - 1;
            for(int i = 1;i < m;i++) {
                cnt += 1ll * cntA[i] * cntB[m-i];
            }
            memset(cntA,0,sizeof(cntA));
            memset(cntB,0,sizeof(cntB));
            cout << cnt << '\n';
        }

    }
}



// 13 mod 8 = 5
// 17 mod 8 = 1

namespace sol
{
    void solve()
    {
        for(int q = 1;q <= t;q++) {
            ll A = a[q], B = b[q], N = n[q];
            ll res = 0;
            ll nA = A / N, nB = B / N;
            res += nA * nB * N;
            A %= N;
            B %= N;
            res += (B+1) * nA;
            res += (A+1) * nB;
            ll stt = N - B;
            // res++;
            res += max(0LL,A - stt + 1);
            cout << res << '\n';
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    readinput();
    sol::solve();
    // if(subtask1::check()) subtask1::solve();
    // else if(subtask2::check()) subtask2::solve();
    // else solb::solve();
    return 0;
}