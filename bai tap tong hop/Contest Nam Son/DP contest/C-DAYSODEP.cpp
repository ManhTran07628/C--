#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N],p[N],minp[N];


void min_prime()
{
    for(int i = 2;i < sqrt(N);i++) {
        if(minp[i] == 0) {
            for(int j = i*2;j < N;j+=i)
                if(minp[j] == 0) minp[j] = i;
        }
    }
    for(int i = 2;i < N;i++) if(minp[i] == 0) minp[i] = i;
}

ll cntdiv1(ll a)
{
    ll ans = 1,cnt = 0,las = -1;
    while(a > 1) {
        if(las != minp[a]) {
            ans *= (cnt+1);
            cnt = 0;
        }
        las = minp[a];
        a /= minp[a];
        cnt++;
    }
    return ans;
}
 
ll cntdiv(ll a)
{
    ll ans = 1;
    ll n = a;
    for(int i = 2;i <= n;i++) {
        ll cnt = 0;
        while(a % i == 0) {
            cnt++;
            a /= i;
        }
        ans = ans * (cnt+1);
    }
    if(a > 1) ans = ans * 2;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "DAYSODEP"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    min_prime();
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        if(n > int(1e4)) p[i] = cntdiv1(a[i]);
        else p[i] = cntdiv(a[i]);
    }
    vector<ll> f;
    for(int i = 1;i <= n;i++) {
        ll it = lower_bound(f.begin(),f.end(),p[i]) - f.begin();
        if(it == f.size()) f.push_back(p[i]);
        else f[it] = p[i];
    }
    cout << f.size();
    return 0;
}