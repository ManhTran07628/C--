#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e5+7;
ll a[N],b[N],c[N],pre[N],suf[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        b[i] = a[i];
        c[i] = a[i];
    }
    for(int i = 2;i <= n;i++) {
        if(a[i] <= a[i-1]) {
            pre[i] = pre[i-1]+a[i-1]-a[i]+1;
            a[i] = a[i-1]+1;
        }
        else pre[i] = pre[i-1];
    }
    for(int i = n-1;i >= 1;i--) {
        if(b[i] <= b[i+1]) {
            suf[i] = suf[i+1]+b[i+1]-b[i]+1;
            b[i] = b[i+1]+1;
        }
        else suf[i] = suf[i+1];
    }
    ll ans = 1e15;
    for(int i = 2;i < n;i++) {
        ans = min(ans,pre[i-1]+suf[i+1]+max(0ll,max(a[i-1],b[i+1])+1-c[i]));
    }
    cout << ans;
    return 0;
}