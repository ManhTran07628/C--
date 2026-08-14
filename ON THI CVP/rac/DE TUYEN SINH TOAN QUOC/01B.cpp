#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e7+7;
ll a[MAXN];


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    ll pre = 0,j = 1;
    while(m--) {
        ll r;
        cin >> r;
        ll sum = 0;
        ll sumpre = pre;
        pre += r;
        while(j <= n && a[j] <= pre) {
            sum += a[j]-sumpre;
            j++;
        }
        sum += (n-j+1)*r;
        if(sum > 0) cout << sum << ' ';
        else break;
    }
    return 0;
}