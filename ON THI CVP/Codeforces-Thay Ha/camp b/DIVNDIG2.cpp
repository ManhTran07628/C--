#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e7+7;
vector<ll> f;
ll tongcs(ll k)
{
    ll ans = 0;
    while(k > 0) {
        ans += k % 10;
        k /= 10;
    }
    return ans;
}

ll scs(ll k)
{
    ll cnt = 0;
    while(k > 0) {
        cnt++;
        k/=10;
    }
    return cnt;
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
    for(int i = 1;i <= N;i++) {
        if(tongcs(i) % scs(i) == 0) {
            f.push_back(i);
        }
    }
    ll k;
    while(cin >> k) {
        cout << f[k-1] << '\n';
    }
    return 0;
}