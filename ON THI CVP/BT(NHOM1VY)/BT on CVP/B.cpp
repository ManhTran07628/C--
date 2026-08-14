#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N],l[N],r[N];
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
    for(int i = 2;i <= n;i++) {
        if(a[i] >= a[i-1]) {
            l[i] = l[i-1] + 1;
        }
    }
    for(int i = n-1;i >= 1;i--) {
        if(a[i] >= a[i+1]) {
            r[i] = r[i+1] + 1;
        }
    }
    ll ans = 1;
    for(int i = 1;i <= n;i++) {
        ans = max(ans,l[i]+r[i]+1);
    } 
    cout << ans;
    return 0;
}