#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
pair<int,int> a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].se >> a[i].fi;
    }
    sort(a+1,a+n+1);
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        if(a[i-1].se <= a[i].fi && a[i+1].se >= a[i].fi) ans++;
    }
    cout << ans;
    return 0;
}