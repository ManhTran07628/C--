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
    #define taskname "tb"
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
    sort(a+1,a+n+1);
    ll ans = 0;
    for(int i = 1;i <= n-2;i++) {
        int c = i;
        for(int j = i+2;j <= n;j++) {
            for(int k = c;k <= n-1;k++) {
                if(a[i]+a[j] == a[k]*2) {
                    ans++;
                }
                else if(a[i] + a[j] < a[k]*2) break;
                c = k;
            }
        }
    }
    cout << ans;
    return 0;
}
