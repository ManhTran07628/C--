#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
vector<pair<ll,ll>> a;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "DRAGON"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,s;
    cin >> s >> n;
    for(int i = 1;i <= n;i++) {
        ll x,y;
        cin >> x >> y;
        a.push_back({x,y});
    }
    sort(a.begin(),a.end());
    ll i = 0;
    for(auto c:a) {
        if(s > c.first) s += c.second;
        else {
            cout << "NO" << '\n' << n-i;
            return 0;
        }
        i++;
    }
    cout << "YES";
    return 0;
}