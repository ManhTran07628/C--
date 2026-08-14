#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll n,l,r,x,ans = 0;
ll c[N];
vector<ll> f;
void backtrack(ll id)
{
    ll max1 = 0,min1 = 1e9,s = 0;
    for(auto i:f) {
        max1 = max(max1,i);
        min1 = min(min1,i);
        s += i;
    }
    if(max1 - min1 >= x && s >= l && s <= r) ans++;

    for(int i = id;i <= n;i++) {
        f.push_back(c[i]);
        backtrack(i+1);
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
    cin >> n >> l >> r >> x;
    for(int i = 1;i <= n;i++) {
        cin >> c[i];
    }
    backtrack(1);
    cout << ans;
    return 0;
}