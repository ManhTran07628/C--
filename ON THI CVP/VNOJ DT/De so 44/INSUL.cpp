#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "INSUL"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    ll ans = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        ans += a[i];
    }
    sort(a+1,a+n+1);
    ll k = 1,j = n;
    for(int i = 1;i <= n;i++) {
        if(i % 2 != 0) {
            b[i] = a[k];
            k++;
        }
        else {
            b[i] = a[j];
            j--;
        }
    }
    if(n % 2 == 1) {
        swap(b[n-1],b[n]);
    }
    for(int i = 2;i <= n;i++) {
        ans += max(0ll,b[i]-b[i-1]);
    }
    cout << ans;
    return 0;
}