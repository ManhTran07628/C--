#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 2000+7;
int m,k;
int a[MM][MM];

void readinput()
{
    cin >> m >> k;
    for(int i = 1;i <= m;i++) {
        for(int j = 1;j <= i;j++) {
            cin >> a[i][j];
        }
    }
}

// namespace subtask1
// {
//     void solve()
//     {
//         ll ans = 0;
//         for(int r1 = 1;r1+k-1 <= m;r1++) {
//             for(int c1 = 1;c1 <= r1;c1++) {
//                 int r2 = r1+k-1,c2 = c1+k-1;
//                 ll cnt = 0;
//                 int d = 1;
//                 for(int i = r1;i <= r2;i++) {
//                     for(int j = c1;j <= c1+d-1;j++) {
//                         cnt = max(cnt,a[i][j]);
//                     }
//                     d++;
//                 } 
//                 ans += cnt;
//             }
//         }
//         cout << ans;
//     }
// }

// namespace subtask2
// {
//     ll ma[MM][MM],maxarr[MM][MM],ans = 0;
//     deque<ll> dq;
//     vector<int> chk;
//     bool checksub2()
//     {
//         for(int i = 1;i <= m;i++) {
//             ll cnt = oo;
//             for(int j = 1;j <= i;j++) {
//                 cnt = min(cnt,a[i][j]);
//             }
//             chk.push_back(cnt);
//         }
//         for(int i = 1;i < chk.size();i++) {
//             if(chk[i] < chk[i-1]) return 0;
//         }
//         return 1;
//     }
//     void max_row(int row)
//     {
//         dq.clear();
//         for(int i = 1;i <= m;i++) {
//             while(!dq.empty() && i-k+1 > dq.front()) dq.pop_front();
//             while(!dq.empty() && a[row][dq.back()] < a[row][i]) dq.pop_back();
//             dq.push_back(i);
//             if(i >= k) {
//                 maxarr[row][i-k+1] = a[row][dq.front()];
//             }
//         }
//     }
//     void solve()
//     {
//         for(int i = 1;i <= m;i++) {
//             max_row(i);
//         }
//         for(int r1 = 1;r1+k-1 <= m;r1++) {
//             for(int c1 = 1;c1 <= r1;c1++) {
//                 int r2 = r1+k-1,c2 = c1+k-1;
//                 ans += maxarr[r2][c1];
//             }
//         }
//         cout << ans;
//     }
// }

namespace subtask3
{
    const int LOG = 12;
    int stS[MM][MM][LOG],stT[MM][MM][LOG];
    //stS : hinh vuong
    // stT : hinh tam giac


    void process()
    {
        for(int i = 1;i <= m;i++) {
            for(int j = 1;j <= i;j++) {
                stS[i][j][0] = a[i][j];
                stT[i][j][0] = a[i][j];
            }
        }

        for(int t = 1;(1 << t) <= m;t++) {
            for(int i = 1;i+(1 << t)-1 <= m;i++) {
                for(int j = 1;j+(1 << t)-1 <= m;j++) {
                    stS[i][j][t] = max({stS[i][j][t-1],stS[i + (1 << (t-1))][j][t-1],
                        stS[i][j + (1 << (t-1))][t-1],stS[i + (1 << (t-1))][j + (1 << (t-1))][t-1]});

                    stT[i][j][t] = max({stT[i][j][t-1],stS[i + (1 << (t-1))][j][t-1],
                        stT[i + (1 << (t-1))][j + (1 << (t-1))][t-1]});
                }
            }
        }
    }   

    int get_Sq(int i,int j,int sz)
    {
        int k = __lg(sz);
        return max({stS[i][j][k],stS[i+sz - (1 << k)][j][k],stS[i][j+sz - (1 << k)][k],
            stS[i+sz - (1 << k)][j+sz - (1 << k)][k]});
    }

    int get_Tr(int i,int j,int sz)
    {
        int k = __lg(sz);
        if(sz == k) return stT[i][j][k];
        return max({stT[i][j][k],stT[i+sz - (1 << k)][j+sz - (1 << k)][k],
            get_Sq(i + (1 << k),j,sz - (1 << k))
        });
    }

    void solve()
    {
        process();
        ll ans = 0;
        for(int i = 1;i+k-1 <= m;i++) {
            for(int j = 1;j <= i;j++) {
                ans += get_Tr(i,j,k);
                // cout << get_Tr(i,j,k) << ' ';
            }
            // cout << '\n';
        }
        cout << ans;
    }

}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    readinput();
    subtask3::solve();
    return 0;
}