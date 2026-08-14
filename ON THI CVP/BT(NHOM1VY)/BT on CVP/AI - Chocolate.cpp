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
    int n;
    cin >> n;
    vector<ll> a;
    for(int i = 1;i <= n;i++) {
        int x;
        cin >> x;
        if(x == 1) a.push_back(i);
    }
    if(a.size() == 0) {
        cout << 0;
        return 0;
    }
    ll ans = 1;
    for(int i = 0;i < a.size();i++) {
        if(i + 1 < a.size()) ans *= (a[i+1]-a[i]);
    }
    cout << ans;
    return 0;
}