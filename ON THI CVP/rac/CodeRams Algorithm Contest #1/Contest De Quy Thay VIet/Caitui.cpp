#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll w[N],v[N];
ll n,s,ans = 0;
vector<ll> f;

void solve(ll crr,ll c)
{
    if(crr > s) return;
    if(crr <= s) {
        ll sum = 0;
        for(auto c:f) {
            sum += c;
        }
        ans = max(ans,sum);
    }
    for(int i = c;i <= n;i++) {
        f.push_back(v[i]);
        solve(crr + w[i],i+1);
        f.pop_back();
    }
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
    cin >> n >> s;
    for(int i = 1;i <= n;i++) {
        cin >> w[i] >> v[i];
    }
    solve(0,1);
    cout << ans;
    return 0;
}