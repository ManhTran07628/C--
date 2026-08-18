#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9
const int MM = 1e5 + 7;
int n;
string s;

namespace subtask1
{
    int ps[MM] = {},dp[MM] = {};
    void solve()
    {
        for(int i = 1;i <= n;i++) ps[i] = ps[i - 1] + (s[i] == '1');
        
        for(int len = 1;len <= n;len++) {

            for(int i = 1;i <= n;i++) dp[i] = oo;

            dp[0] = 0;
            for(int i = 1;i <= n;i++) {

                for(int j = i;j >= max(1,i - len + 1);j--) {
                    int sum = ps[i] - ps[j - 1];
                    if(sum % 2 == 1) 
                        dp[i] = min(dp[i],dp[j - 1] + 1);
                }

            }

            if(dp[n] == oo) cout << -1 << ' ';
            else cout << dp[n] << ' ';
        }

    }
}

// namespace subtask23
// {
//     int st[1007 * 4][2] = {};

//     void build(int id,int l,int r,int type)
//     {
//         st[id][type] = -1;
//         if(l == r) return;
//         int mid = (l + r) / 2;
//         build(id*2,l,mid,type);
//         build(id*2+1,mid+1,r,type);
//     }

//     void update(int id,int l,int r,int pos,int val,int type)
//     {
//         if(l > pos || r < pos) return;
//         if(l == r) {
//             st[id][type] = val;
//             return;
//         }
//         int mid = (l + r) / 2;
//         update(id*2,l,mid,pos,val,type);
//         update(id*2+1,mid+1,r,pos,val,type);
//         st[id][type] = max(st[id*2][type],st[id*2+1][type]);
//     }

//     int get(int id,int l,int r,int u,int v,int type)
//     {
//         if(u > v) return -1;
//         if(l > v || r < u) return -1;
//         if(u <= l && r <= v) return st[id][type];
//         int mid = (l + r) / 2;
//         return max(get(id*2,l,mid,u,v,type), get(id*2+1,mid+1,r,u,v,type));
//     }

//     int ps[MM] = {};
    

//     void solve()
//     {
//         for(int i = 1;i <= n;i++) ps[i] = ps[i - 1] + (s[i] == '1');

//         for(int len = 5;len <= 5;len++) {

//             build(1,0,n,0);
//             build(1,0,n,1);

//             update(1,0,n,0,0,0);

//             // if(ps[1] % 2 == 1) update(1,0,n,0,1,1);
//             // else update(1,0,n,0,0,0);

//             for(int r = 1;r <= n;r++) {
//                 int val;
//                 int l = max(0,r - len);
//                 if(ps[r] % 2 == 0) {
//                     val = get(1,0,n,l,r - 1,1);
//                     if(val != -1) update(1,0,n,r,val + 1,0);
//                     else update(1,0,n,r,0,0);

//                     cout << r << ' ' << val + 1 << ' ' << ps[r] % 2 << '\n';
//                 }
//                 else {
//                     val = get(1,0,n,l,r - 1,0);
//                     if(val != -1) update(1,0,n,r,val + 1,1);
//                     else update(1,0,n,r,0,1);

//                     cout << r << ' ' << val + 1 << ' ' << ps[r] % 2 << '\n';
//                 }
//                 // if(ps[r] % 2 == 0) update(1,1,n,r,)
//             }

//             int val = get(1,0,n,n - len,n,ps[n] % 2);

//             if(val == -1) cout << -1 << ' ';
//             else cout << val << ' ';
//         }
//     }
// }

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    cin >> s;
    s = ' ' + s;
    subtask1::solve();
    return 0;
}