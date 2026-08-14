#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
map<char,pair<ll,ll>> st;
ll n,m;
string s;
ll f[2001][2001];

ll dq(ll i,ll j)
{
    if(i >= j) return 0;
    if(s[i] == s[j]) {
        f[i][j] = f[i+1][j-1];
        return f[i][j];
    }
    else {
        f[i][j] = min(f[i][j],st[s[i]].se) + dq(i+1,j);
        f[i][j] = min(f[i][j],st[s[j]].fi) + dq(i,j-1);
    }
    return f[i][j];

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
    for(int i = 1;i <= m;i++) {
        for(int j = 1;j <= m;j++) {
            f[i][j] = -1;
        }
    }
    cin >> n >> m >> s;
    for(int i = 1;i <= n;i++) {
        char a;
        ll b,c;
        cin >> a >> b >> c;
        st[a].fi = b;
        st[a].se = c;
    }
    // for(auto i:st) {
    //     cout << i.fi << ' ' << i.se.fi << ' ' << i.se.se << '\n';
    // }
    cout << dq(0,m-1);
    return 0;
}

