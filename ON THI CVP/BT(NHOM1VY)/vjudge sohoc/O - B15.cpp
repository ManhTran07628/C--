#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int r;
    cin >> r;
    int t;
    cin >> t;
    while(t--) {
        int n,a,b,c;
        cin >> n >> a >> b >> c;
        if(r == 1) {
            int p = 1e9;
            p = min({a,b,c});
            cout << p << '\n';
        }
        else {
            int p = 0;
            p = max({a,b,c});
            cout << p << '\n';
        }
    }
    return 0;
}