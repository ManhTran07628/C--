#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N];

void sub1(ll n)
{
    multiset<ll> s;
    vector<ll> st;
    for(int i = 1;i <= n;i++) {
        s.insert(i);
    }
    while(s.size() != 1) {
        ll i = 1;
        for(auto c:s) {
            if(i % 3 != 2) st.push_back(c);
            i++;
        }
        for(auto c:st) s.erase(c);
        st.clear();
    }
    for(auto c:s) cout << c;
}

void sub2(ll n)
{
    ll x = 2,f = 3;
    while(x <= n) {
        x += f;
        f = f * 3;
    }
    x -= f / 3;
    cout << x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "LUCK"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    sub2(n);
    return 0;
}