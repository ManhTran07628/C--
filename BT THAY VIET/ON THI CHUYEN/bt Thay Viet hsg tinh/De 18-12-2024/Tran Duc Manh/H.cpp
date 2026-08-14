#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N],p[N];

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
    ll n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(int i = 1;i <= n;i++) {
        ll rend = upper_bound(a+1,a+n+1,a[i]+k) - a;
        p[i] = rend;
    }  
    ll max1 = 0;
    for(int i = 1;i <= n;i++) {
        ll ans = 0;
        for(int j = p[i];j <= n;j++) {
            ans = max(ans,p[i]-i+p[j]-j);
        }
        max1 = max(max1,ans);
    } 
    cout << max1;
    return 0;
}