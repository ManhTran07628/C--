#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s,t;
    cin >> s;
    ll sum = 0, ok = 0;
    for(auto x:s) {
        if(isdigit(x)) {
            sum += x - '0';
        }
        else {
            t.push_back(x);
            ok = 1;
        }
    }
    cout << sum << '\n';
    if(ok) {
        reverse(t.begin(),t.end());
        cout << t;
    }
    else cout << -1;
    return 0;
}