#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
ll n,m,P,C,a[MM],s[7],Qmax[MM][7],Qmin[MM][7],dp[1 << 6][MM];
deque<ll> dq;
void Query(int len,int id,int t)
{
    while(!dq.empty()) dq.pop_back();
    if(!t) {
        for(int i = 1;i <= n;i++) {
            while(!dq.empty() && dq.front() < i-len+1) dq.pop_front();
            while(!dq.empty() && a[i] > a[dq.back()]) dq.pop_back();
            dq.push_back(i); if(i >= len)  Qmax[i][id] = a[dq.front()];
        }
    }
    else {
        for(int i = 1;i <= n;i++) {
            while(!dq.empty() && dq.front() < i-len+1) dq.pop_front();
            while(!dq.empty() && a[i] < a[dq.back()]) dq.pop_back();
            dq.push_back(i); if(i >= len) Qmin[i][id] = a[dq.front()];
        }
    }
}

void process()
{
    cin >> n >> m >> P >> C;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    for(int i = 1;i <= m;i++) {
        cin >> s[i];
        Query(s[i],i,0);
        Query(s[i],i,1);
    }
}
// dp[mask][i] : loi nhuan lon nhat xet den nhung ngoi nha dc thi cong
// trong trang thai mask xet den i

void solve()
{
    for(int mask = 0;mask < (1 << m);mask++) {
        for(int i = 0;i <= n;i++) {
            dp[mask][i] = -oo;
        }
    }
    dp[0][0] = 0;
    for(int i = 1;i <= n;i++) {
        for(int mask = 0;mask < (1 << m);mask++) {
            dp[mask][i] = max(dp[mask][i],dp[mask][i-1]);
            for(int j = 0;j < m;j++) {
                if(mask >> j & 1) {
                    int p_mask = mask ^ (1 << j);
                    if(i >= s[j+1]) {
                        ll d = Qmax[i][j+1]-Qmin[i][j+1],pos = i-s[j+1];
                        ll profit = P-d*d*C;
                        if(dp[mask][pos] != -oo)
                            dp[mask][i] = max(dp[mask][i],dp[mask][pos]+profit);

                        if(dp[p_mask][pos] != -oo)
                            dp[mask][i] = max(dp[mask][i],dp[p_mask][pos]+profit);
                    }

                }
            }
        }
    }
    cout << dp[(1 << m)-1][n];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "WHOME"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    process();
    solve();
    return 0;   
}