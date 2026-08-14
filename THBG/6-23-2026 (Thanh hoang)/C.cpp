#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int n,k,q,a[MM];

namespace subtask1
{
    int dp[101][101],f[101][101];
    void solve()
    {
        memset(f,-1,sizeof(f));
        for(int i = 2;i <= n;i++) {
            if(a[i-1] + a[i] == k) { 
                dp[i-1][i] = 1;
                f[i-1][i] = 0;
            }
        }

        for(int i = 1;i <= n;i++) f[i][i] = a[i];

        for(int len = 3;len <= n;len++)
            for(int L = 1;L + len - 1 <= n;L++) {
                int R = L + len - 1;
                for(int i = L;i < R;i++) {
                    if(f[L][i] == -1 || f[i+1][R] == -1) continue;

                    if(f[L][i] == 0 && f[i+1][R] != 0) f[L][R] = f[i+1][R];
                    else if(f[i+1][R] == 0 && f[L][i] != 0) f[L][R] = f[L][i];
                    
                    if(f[L][i] != 0 && f[i+1][R] != 0) {
                        if(f[L][i] + f[i+1][R] == k) {
                            dp[L][R] = 1;
                            f[L][R] = 0;
                        }
                    }
                }
            }
        
        while(q--) {
            int l,r; cin >> l >> r;
            cout << (dp[l][r] == 1 ? "YES" : "NO") << '\n';
        }
    }
}

namespace subtask2
{
    void solve()
    {
        while(q--) {
            int l,r; cin >> l >> r;
            stack<int> st;
            for(int i = l;i <= r;i++) {
                if(st.empty()) {
                    st.push(a[i]);
                }
                else {
                    if(st.top() + a[i] == k) st.pop();
                    else st.push(a[i]);
                }
            }
            if(st.empty()) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
    }
}


const int base = 1e6;
const int MOD[] = {(int) 1e9 + 2277,(int) 1e9 + 5577};
namespace subtask3
{
    ll S[MM][2],Pow[MM][2];
    void solve()
    {
        stack<int> st;
        for(int i = 1;i <= n;i++) {
            if(st.empty()) {
                st.push(i);
                S[i][0] = (S[i-1][0] * base + a[i]) % MOD[0];
                S[i][1] = (S[i-1][1] * base + a[i]) % MOD[1];
            }
            else {
                if(a[st.top()] + a[i] == k) {
                    int pos = st.top();

                    S[i][0] = S[pos - 1][0];
                    S[i][1] = S[pos - 1][1];

                    st.pop();
                }
                else {
                    st.push(i);
                    S[i][0] = (S[i-1][0] * base + a[i]) % MOD[0];
                    S[i][1] = (S[i-1][1] * base + a[i]) % MOD[1];
                }
            }
        }

        while(q--) {
            int l,r; cin >> l >> r;
            if(S[r][0] == S[l-1][0] && S[r][1] == S[l-1][1]) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "sol"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> a[i];
    cin >> q;
    subtask3::solve();
    return 0;
}