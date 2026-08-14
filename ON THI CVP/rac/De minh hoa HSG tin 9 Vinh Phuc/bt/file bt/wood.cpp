#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "WOOD"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++) 
        cin >> a[i];
    ll tong = 1e9;
    ll L = 1,R = 1e9;
    while(L <= R){
        ll mid = (L+R)/2;
        ll ans = 0;
        for(int i = 1;i <= n;i++) {
            if(mid <= a[i])
                ans += a[i] - mid;
        }
        if(ans > m) {
            tong = mid;
            L = mid + 1;
        }
        else if(ans < m){
            R = mid - 1;
        }
        else if(ans == m) {
            cout << mid;
            return 0;
        }
    }
    return 0;
}