#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6 + 7;
ll x,y; 
ll A,B,C,D; 
vector<string> v;



signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> x >> y;
    A = x, B = y, C = 0, D = 1;
    if(x == x * y) {
        cout << 0 << '\n' << "A";
        return 0;
    }
    if(y == x * y) {
        cout << 0 << '\n' << "B";
        return 0;
    }
    if(x < y) {
        // cout << __lg(x) << '\n';
        while(x > 0) {
            if(x % 2 == 1) v.push_back("B C C");
            x /= 2;
            if(x > 0)
                v.push_back("B B B");
        }
    }
    else {
        // cout << __lg(y) << '\n';
        while(y > 0) {
            if(y % 2 == 1) v.push_back("A C C");
            y /= 2;
            if(y > 0)
                v.push_back("A A A");
        }
    }
    // for(auto x:v) cout << x << '\n';
    cout << v.size() << '\n';
    for(int i = 0;i < v.size();i++) cout << v[i] << '\n';
    if(x == 0) cout << "B";
    else cout << "A";
    return 0;
}