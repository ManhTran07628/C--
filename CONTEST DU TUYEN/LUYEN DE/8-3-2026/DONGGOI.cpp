#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int n;
ll B,K,a[MM];

int prime[MM],mp[MM];
vector<int> primes;
void sieve()
{
    for(int i = 2;i < MM;i++) prime[i] = 1;
    for(ll i = 2;i * i < MM;i++)
        if(prime[i])
            for(ll j = i * i;j < MM;j += i)
                prime[j] = 0;

    for(int i = 2;i < MM;i++)
        primes.push_back(i);

    for(ll i = 2;i * i < MM;i++) 
        if(mp[i] == 0)  
            for(ll j = i * i;j < MM;j += i)
                if(mp[j] == 0)
                    mp[j] = i;
    for(int i = 2;i < MM;i++)
        if(mp[i] == 0)
            mp[i] = i;
}

namespace subtask1
{
    int cntB[MM],cnt[MM];
    vector<int> fac;
    void solve()
    {
        sieve();
        while(B > 1) {
            int p = mp[B];
            while(B % p == 0) {
                cntB[p]++;
                B /= p;
                fac.push_back(p);
            }
        }

        int res = 0;
        for(int i = 1;i <= n;i++) {
            
            for(int j = i;j <= n;j++) {
                int x = a[j];
                while(x > 1) {
                    int p = mp[x];
                    while(x % p == 0) {
                        cnt[p]++;
                        x /= p;
                    }
                }
                
                int flag = 0;
                for(auto p:fac) {
                    if(cnt[p] >= cntB[p] * K) flag++;
                }
                if(flag == fac.size()) res++;
            }

            for(auto p:fac) cnt[p] = 0;
        }

        cout << res;
    }
}

namespace subtask2
{
    unordered_map<int,int> cntB;
    void solve()
    {   
        vector<int> fac;
        sieve();
        for(auto p:primes) {
            if(B % p == 0) {
                fac.push_back(p);
                while(B % p == 0) {
                    B /= p;
                    cntB[p]++;
                }
            }
        }
        if(B > 1) {
            fac.push_back(B);
            cntB[B]++;
        }

        // for(auto e:fac) cout << e << ' ';
        // cout << cntB.size();
        int res = 0;
        for(int i = 1;i <= n;i++) {
            unordered_map<int,int> cnt,vis;
            int cntvalid = 0;
            for(int j = i;j <= n;j++) {
                if(cntvalid == (int) fac.size()) {
                    res++;
                    // cout << i << ' ' << j << '\n';
                    continue;
                }
                
                ll x = a[j];
                for(auto p:primes) {
                    if(vis.find(p) != vis.end()) continue;
                    while(x % p == 0) {
                        cnt[p]++;
                        x /= p;
                        if(cnt[p] >= cntB[p] * K) {
                            cntvalid++;
                            vis[p] = 1;
                            break;
                        }
                    } 
                    if(cntvalid >= (int) fac.size()) {
                        res++;
                        // cout << i << ' ' << j << '\n';
                        break;
                    }
                }

            }
        }

        cout << res;
    }
}

namespace subtask3
{
    ll C(int lim)
    {
        ll ans = 0;
        for(int i = 1;i <= n;i++) {
            int j = lower_bound(a+1,a+n+1,a[i - 1] + lim) - a;
            if(n >= j)
                ans += n - j + 1; 
        }
        return ans;
    }

    void solve()
    {
        for(int i = 1;i <= n;i++) {
            int cnt = 0;
            while(a[i] % B == 0) {
                a[i] /= B;
                cnt++;
            }
            a[i] = a[i - 1] + cnt;
        }

        ll res = 0;
        cout << C(K);
    }
}

namespace sol
{
    ll cntB[MM],cntA[MM],bprime = -1, cnt_bprime = 0;
    vector<int> fac;
    bool isvalid()
    {
        for(int i = 0;i < fac.size() - (bprime != -1);i++) {
            if(cntA[ fac[i] ] / K < cntB[ fac[i] ]) return 0;
        }
        if(bprime != -1) {
            if(cnt_bprime >= K) return 1;
            return 0;
        }
        return 1;
    }

    void solve()
    {
        sieve();
        for(auto p:primes) {
            int cntff = 0;
            if(B % p == 0) {
                fac.push_back(p);
                while(B % p == 0) {
                    B /= p;
                    cntff++;
                }
                cntB[p] = cntff;
            }
        }
        if(B > 1) {
            fac.push_back(B);
            bprime = B;
        }

        a[0] = 1;

        ll res = 0;

        for(int i = 1, j = 1; i <= n; i++) {

            while(j <= n && !isvalid()) {
                ll x = a[j];
                for(auto p:fac) {
                    if(p == bprime && x % p == 0) {
                        cnt_bprime++;
                        continue;
                    }
                    while(x % p == 0) {
                        cntA[p]++;
                        x /= p;
                    }
                }
                j++;
            }

            if(n >= (j - 1) && isvalid())
                res += (n - (j - 1) + 1);

            ll x = a[i];
            for(auto p:fac) {
                if(p == bprime && x % p == 0) {
                    cnt_bprime--;
                    continue;
                }
                while(x % p == 0) {
                    cntA[p]--;
                    x /= p;
                }
            }

        }

        cout << res;
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
    cin >> n >> B >> K;
    for(int i = 1;i <= n;i++) cin >> a[i];
    // if(n <= 200) subtask1::solve();
    // else subtask3::solve();
    sol::solve();
    return 0;
}