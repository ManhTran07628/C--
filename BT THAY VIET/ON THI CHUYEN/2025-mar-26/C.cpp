#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;

pair<ll,ll> s[100];
ll dd1[100];
ll ans = LLONG_MAX;
int n;

void backtracking(ll dc,ll dd)
{
    for(int i = 1;i <= n;i++) {
        if(dd1[i] == 0) {
            ans = min(ans,abs(dc*s[i].fi - (dd+s[i].se)));
            dd1[i] = 1;
            backtracking(dc*s[i].fi,dd+s[i].se);
            dd1[i] = 0;
        }
    }
}




int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> s[i].fi >> s[i].se;
    }
    backtracking(1,0);
    cout << ans;
    return 0;
}