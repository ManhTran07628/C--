#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e7+7;
ll a[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "phieu"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    ll cnt = 0,res = 0,crr = 1;
    while(cnt < n) {
        for(int i = 1;i <= n;i++) {
            if(a[i] == crr) {
                cnt++;
                crr++;
            }
        }
        res++;
    }
    cout << res;
    return 0;
}