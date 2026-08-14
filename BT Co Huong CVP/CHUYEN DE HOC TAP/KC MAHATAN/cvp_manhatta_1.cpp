#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6 + 7;
ll p[MM],n;
vector<ll> a;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for(int i = 1;i <= n;i++) {
        ll x; cin >> x; 
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    // for(int i = 0;i < a.size();i++) cout << a[i] << ' ';
    int m = n;
    if(m % 2 == 1) cout << 1;
    else {
        int mid = m / 2;
        cout << a[mid] - a[mid - 1] + 1;
    }



    return 0;
}