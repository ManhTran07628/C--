#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll p[N];
vector<ll> f;
void sieve()
{
    fill(p+1,p+N,1);
    p[1] = p[0] = 0;
    for(int i = 1;i < sqrt(N);i++)
        if(p[i])
            for(int j = i*2;j < N;j+=i)
                p[j] = 0;
    for(int i = 1;i < N;i++) if(p[i]) f.push_back(i);
}


ll solve(ll L,ll R)
{
    vector<ll> demuoc(R-L+1,1);
    vector<ll> so(R-L+1);
    for(int i = 0;i <= R-L;i++) so[i] = L+i;
    for(auto i:f) {
        if(i*i > R) break;
        for(ll j = max(i*i,(L+i-1)/i*i);j <= R;j+=i) {
            ll cnt = 0;
            while(so[j-L] % i == 0) {
                so[j-L] /= i;
                cnt++;
            }
            demuoc[j-L] *= (cnt+1);
        }
    }
    for(ll i = 0;i <= R-L;i++) {
        if(so[i] > 1) demuoc[i] *= 2;
    }
    int ans = 0;
    for(auto i:demuoc) {
        if(p[i]) ans++;
    }
    return ans;
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    sieve();
    int t;
    cin >> t;
    while(t--) {
        ll l,r;
        cin >> l >> r;
        cout << solve(l,r) << '\n';
    }
    return 0;
}