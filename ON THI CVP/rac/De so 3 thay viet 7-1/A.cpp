#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[5][5];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll cnt = 0;
    ll n = 4,sum = -1;
    for(int i = 1;i <= n;i++) {
        ll s = 0;
        for(int j = 1;j <= n;j++) {
            cin >> a[i][j];
            s += a[i][j];
        }
        if(sum == -1) {
            cnt++;
            sum = s;
        }
        else {
            if(sum == s) cnt++;
            else {
                sum = -1;
            }
        }
    }
    for(int i = 1;i <= n;i++) {
        ll s = 0;
        for(int j = 1;j <= n;j++) {
            s += a[j][i];
        }
        if(sum == s) {
            cnt++;
        }
        else {
            sum = -1;
            break;
        }
    }
    if(sum != -1 && cnt == 8) cout << "magic";
    else cout << "not magic";
    cout << '\n';
    return 0;
}