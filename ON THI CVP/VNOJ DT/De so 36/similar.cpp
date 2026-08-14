#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e7+7;
ll a[N],b[N];

ll tongpt(ll k)
{
    ll tmp = 0;
    while(k > 0) {
        tmp += k % 10;
        k /= 10;
    }
    return tmp;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "similar"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll l,r;
    cin >> l >> r;
    for(int i = l;i <= r;i++) {
        a[i] = tongpt(i);
        cout << a[i] << " ";
    }
    for(int i = l;i <= r;i++) {
        if(b[a[i]] == 0) {
            b[a[i]] = i;
        }
    }
    ll ans = 0;
    for(int i = r;i >= l;i--) {
        if(b[a[i]] != 0) {
            ans = max(ans,i-b[a[i]]);
        }
    }
    cout << ans;
    return 0;
}