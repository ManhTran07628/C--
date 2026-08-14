#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];
ll n,k;

ll check(ll mid) {
    ll count = 1;
    ll pos1 = a[1];
    for(int i = 2;i <= n;i++) {
        if(pos1 + mid < a[i]) {
            count++;
            pos1 = a[i];
            if(count > k) return 0;
        }
    }
    return count <= k;
}



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
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    ll L = 1,R = 1e9,ans = 1e9;
    while(L <= R) {
        ll mid = (L+R)/2;
        if(check(mid)) {
            ans = mid;
            R = mid - 1;
        }
        else L = mid + 1;
    }
    cout << ans;
    return 0;
}