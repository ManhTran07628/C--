#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e4 + 7;
int n,q,w[MM],c[MM];

namespace subtask1
{
    ll dp[101];
    void solve()
    {
        while(q--) {
            int l,r,W; cin >> l >> r >> W;
            ll res = 0;
            for(int i = l;i <= r;i++) {
                for(int j = W;j >= w[i];j--) {
                    dp[j] = max(dp[j],dp[j - w[i]] + c[i]);
                    res = max(res,dp[j]);
                }
            }
            memset(dp,0,sizeof(dp));
            cout << res << '\n';
        }
    }
}

const int block_Size = 2;
namespace subtask2
{
    ll dp[MM / block_Size + 1][101],f[MM];

    ll get(int l,int r,int W)
    {
        int block_L = (l + block_Size - 1) / block_Size;
        int block_R = (r + block_Size - 1) / block_Size;
        
        ll res = 0;
        if(block_L == block_R) {
            // cout << 36 << ' ';
            for(int i = l;i <= r;i++) {
                for(int j = W;j >= w[i];j--) {
                    f[j] = max(f[j],f[j - w[i]] + c[i]);
                    res = max(res,f[j]);
                }
            }
            return res;
        }

        for(int i = block_L + 1;i < block_R;i++) {
            for(int weight = 1;weight <= W;weight++) 
                for(int j = W;j >= weight;j--) {
                    f[j] = max(f[j],f[j - weight] + dp[i][weight]);
                // res = max(res,f[j]);
            }
        }

        cout << "AAA" << ' ' << res << '\n';

        for(int i = l;i <= block_L * block_Size;i++) {
            for(int j = W;j >= w[i];j--) {
                f[j] = max(f[j],f[j - w[i]] + c[i]);
                res = max(res,f[j]);
            }
        }

        for(int i = (block_R - 1) * block_Size + 1;i <= r;i++) {
            for(int j = W;j >= w[i];j--) {
                f[j] = max(f[j],f[j - w[i]] + c[i]);
                res = max(res,f[j]);
            }
        }
        

        return res;
    }

    void solve()
    {
        for(int i = 1;i <= n;i++) {
            int cur_block = (i + block_Size - 1) / block_Size;
            cout << i << ' ' << cur_block << '\n';
            for(int j = 100;j >= w[i];j--) {
                dp[cur_block][j] = max(dp[cur_block][j],dp[cur_block][j - w[i]] + c[i]);
            }
        }

        while(q--) {
            int l,r,w; cin >> l >> r >> w;
            cout << get(l,r,w) << '\n';
            // for(int i = 1;i <= 4;i++) cout << f[i] << ' ';
            for(int i = 1;i <= 100;i++) f[i] = 0;
        }
    }
}


struct Query{int l,r,w;} qr[MM];

namespace sol
{
    int ans[(int) 1e5 + 7],dpL[MM][101],dpR[MM][101];

    void dnc(int L,int R,vector<int> queries)
    {
        if(L > R) return;
        if(L == R) {
            for(auto id:queries) {
                int l = qr[id].l, r = qr[id].r, W = qr[id].w;
                if(w[l] <= W) ans[id] = c[l];
            }
            return;
        }
        vector<int> left,right,cur;

        int mid = (L + R) / 2;

        for(auto id:queries) {
            int l = qr[id].l, r = qr[id].r, W = qr[id].w;
            if(L <= l && r <= mid) left.push_back(id);
            else if(mid + 1 <= l && r <= R) right.push_back(id);
            else if(l <= mid && mid <= r) cur.push_back(id);
        }
        
        for(int i = 0;i <= 100;i++) dpL[mid + 1][i] = dpR[mid][i] = 0;

        for(int i = mid;i >= L;i--) {
            for(int j = 100;j >= 0;j--) {
                dpL[i][j] = dpL[i + 1][j];
                if(j >= w[i])
                    dpL[i][j] = max(dpL[i][j],dpL[i + 1][j - w[i]] + c[i]);
            }
        }

        for(int i = mid+1;i <= R;i++) {
            for(int j = 100;j >= 0;j--) {
                dpR[i][j] = dpR[i - 1][j];
                if(j >= w[i])
                    dpR[i][j] = max(dpR[i][j],dpR[i - 1][j - w[i]] + c[i]);
            }
        }

        for(auto id:cur) {
            int l = qr[id].l, r = qr[id].r, W = qr[id].w;
            for(int i = 0;i <= W;i++) {
                ans[id] = max(ans[id],dpL[l][i] + dpR[r][W - i]);
            }
        }

        dnc(L,mid,left);
        dnc(mid+1,R,right);
    }


    void solve()
    {
        vector<int> cur;
        for(int i = 0;i < q;i++) cur.push_back(i);
        dnc(1,n,cur);
        for(int i = 0;i < q;i++) {
            cout << ans[i] << '\n';
        }
    }
}

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
    for(int i = 1;i <= n;i++) cin >> w[i] >> c[i];
    int max_sz = 100;
    cin >> q;
    for(int i = 0;i < q;i++) {
        cin >> qr[i].l >> qr[i].r >> qr[i].w;
    }
    sol::solve();
    return 0;
}