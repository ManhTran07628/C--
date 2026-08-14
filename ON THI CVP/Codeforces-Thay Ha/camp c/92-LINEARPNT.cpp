#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
map<pair<int,int>,int> lt;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int t = 0;
    for(int i = 1;i <= n;i++) {
        int x,y;
        cin >> x >> y;
        int c = __gcd(x,y);
        if(x == 0 && y == 0) t = 1;
        if(c != 0) {
            x /= c;y /= c;
        }
        lt[{x,y}]++;
    }
    int ans = 0;
    for(auto p:lt) {
        ans = max(ans,p.se+t);
    }
    cout << ans;
    return 0;
}