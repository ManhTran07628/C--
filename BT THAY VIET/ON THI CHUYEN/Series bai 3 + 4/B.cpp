#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N];

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
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    ll ans = 0,i = 1,j = n,cnt = 0,ans2 = 0;
    while(i <= j) {
        if(cnt % 2 == 0) {
            ans += max(a[i],a[j]);
            cnt++;
        }
        else {
            ans2 += max(a[i],a[j]);
            cnt++;
        }
        if(a[i] > a[j]) i++;
        else j--;
    }
    cout << ans << ' ' << ans2;   
    return 0;
}