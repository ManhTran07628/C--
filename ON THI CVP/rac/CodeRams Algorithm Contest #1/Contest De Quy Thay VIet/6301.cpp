#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N];
ll n,k,cnt = 0;
vector<ll> f;
int Isprime(ll k)
{
    if(k < 2) return 0;
    for(int i = 2;i*i <= k;i++) {
        if(k % i == 0) return 0;
    }
    return 1;
}

void solve(ll c)
{
    if(f.size() == k) {
        ll sum = 0;
        for(auto i:f) sum += i;
        if(Isprime(sum)) cnt++;
        return;
    }
    for(int i = c;i <= n;i++) {
        f.push_back(a[i]);
        solve(i+1);
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
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    solve(1);
    cout << cnt;
    return 0;
}