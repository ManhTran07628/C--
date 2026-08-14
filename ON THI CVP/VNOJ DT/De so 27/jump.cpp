#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first  
#define se second
const int N = 1e6+7;
ll a[N],b[N];
vector<pair<ll,ll>> maxl;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "jump"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,p;
    cin >> n >> p;
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    for(int i = n-1;i >= 0;i--) {
        b[i] = max(b[i+1],a[i]);
        maxl.push_back({b[i],i});
    }
    // for(auto c:maxl) {
    //     cout << c.fi << " " << c.se << '\n';
    // }
    ll cnt = 0;
    for(int i = 0;i < n;i++) {
        auto pos = lower_bound(maxl.begin(),maxl.end(),make_pair(a[i]+p,0ll));
        if(pos->se > i && pos != maxl.end()) {
            cnt = max(cnt,pos->se-i);
        }
    }
    cout << cnt;
    return 0;
}