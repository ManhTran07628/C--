#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "DRB"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll s1,v1,s2,v2;
    cin >> s1 >> v1 >> s2 >> v2;
    if(s1 <= s2 && v1 < v2) {
        cout << -1;
        return 0;
    }
    else if(s1 >= s2 & v1 > v2) {
        cout << -1;
        return 0;
    }
    if(v1-v2 == 0) {
        if(s1 < s2 || s1 > s2) cout << -1;
        else cout << 0;
        return 0;
    }
    ll ans = -(s1-s2)/(v1-v2);
    cout << ans;
    return 0;
}