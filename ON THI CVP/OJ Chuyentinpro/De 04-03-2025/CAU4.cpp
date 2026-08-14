
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
ll a[MAXN];
ll n,k,S;
void sub12()
{
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        a[i] += a[i-1];
    }
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = i;j <= n;j++) {
            if(a[j]-a[i-1] >= S && (j-i+1)%k==0) {
                 ans++;
            }
        }
    }
    cout << ans;
}

void sub3()
{
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        a[i] += a[i-1];
    }
    int ans = 0;
    for(int L = 1;L <= n;L++) {
        int R = lower_bound(a+L,a+n+1,S+a[L-1]) - a;
        double c = (R-L+1);
        int vtd = ceil(c/k);
        int vtc = (n-L+1)/k;
        ans += vtc - vtd + 1;
    }
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> S;
    if(n <= 1000) sub12();
    else sub3();
    return 0;
}