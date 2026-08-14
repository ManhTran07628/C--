#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
ll a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        int p = upper_bound(a+i,a+n+1,a[i]*2) - a;
        ans = max(ans,p-i);
    }
    cout << n-ans << '\n';
    return 0;
}