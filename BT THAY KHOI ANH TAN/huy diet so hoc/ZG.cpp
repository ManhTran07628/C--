#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
string p;
bool check(ll d) {
    string s = to_string(d);
    for(int i = 0;i < s.size();i++) {
        string s1 = s.substr(i,p.size());
        if(s1 == p) return 1;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll k,l,r;
    cin >> k >> l >> r;
    p = to_string(k);
    int ans = 0;
    for(ll i = l;i <= r;i++) {
        if(check(i)) ans++;
    }
    cout << ans;
    return 0;   
}