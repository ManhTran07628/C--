#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
int t,s,d;


namespace solb
{
    bool check(int S)
    {
        int sum = 0,total_dig = 0;
        while(S > 0) {
            sum += S % 10;
            total_dig++;
            S /= 10;
        }
        return (total_dig == d && s == sum);
    }

    void solve()
    {
        for(int i = 1;i <=  (int)1e6;i++) 
            if(check(i)) {
                cout << i << '\n';
                return;
            }
        cout << -1 << '\n';
        // cout << i << '\n';
    }
}

void solve()
{
    if(s/9 + (s % 9 != 0) > d) {
        cout << -1 << '\n';
        return;
    }
    int cnt9 = s / 9;
    for(int i = 1;i <= d;i++) {

        for(int digit = 0;digit <= 9;digit++) {
            if(i == 1 && digit == 0) continue;
            int sum_left = s - digit;
            int dig_left = sum_left / 9 + (sum_left % 9 != 0);
            if(dig_left <= d-i) {
                cout << digit;
                s -= digit;
                break;
            }
        }

    }
    cout << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "sol"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> t;
    for(int i = 1;i <= t;i++) {
        cin >> s >> d;
        // solb::solve();
        solve();
    }
    return 0;
}