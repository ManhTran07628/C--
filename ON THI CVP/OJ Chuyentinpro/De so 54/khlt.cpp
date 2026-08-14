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
    cin.tie(0);
    #define taskname "khlt"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,s;
    cin >> n >> s;
    for(int i = 1;i <= n;i++) cin >> a[i];
    ll sum = 0,ans = n+1;
    ll i = 1,j = 1;
    while(i <= n && j <= n)
    {
        sum += a[j];
        while(sum >= s) {
            ans = min(ans,j-i+1);
            sum -= a[i];
            i++;
        }
        j++;
    }
    if(ans == n+1) ans = -1;
    cout << ans;
    return 0;
}