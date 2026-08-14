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
    for(int i = 1;i <= n;i++) {
        l[i] = 1;
        for(int j = 1;j < i;j++) {
            if(a[i] > a[j]) {
                l[i] = max(l[i],l[j]+1);
            }
        }
    }
    reverse(a+1,a+n+1);
    for(int i = 1;i <= n;i++) {
        r[i] = 1;
        for(int j = 1;j < i;j++) {
            if(a[i] > a[j]) {
                r[i] = max(r[i],r[j]+1);
            }
        }
    }
    reverse(r+1,r+n+1);
    ll ans = N;
    for(int i = 2;i < n;i++) {
        if(l[i] != 1 && r[i] != 1) {
            ans = min(ans,n-(l[i]+r[i]-1));
        }
    }
    if(ans == N) cout << 0;
    else cout << ans;
    return 0;
}