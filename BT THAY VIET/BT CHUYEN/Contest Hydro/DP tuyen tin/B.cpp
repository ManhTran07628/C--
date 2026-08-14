#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
int n,dpl[MM],dpr[MM],a[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++) {
        dpl[i] = 1;
        for(int j = 1;j < i;j++) 
            if(a[i] > a[j]) dpl[i] = max(dpl[i],dpl[j]+1);
    }

    for(int i = n;i >= 1;i--) {
        dpr[i] = 1;
        for(int j = n;j > i;j--) 
            if(a[i] > a[j]) dpr[i] = max(dpr[i],dpr[j]+1);
    }
    int ans = 0;
    for(int i = 0;i <= n;i++) {
        if(a[i] != a[i+1])
            ans = max(ans,dpl[i]+dpr[i+1]);
    }
    cout << n-ans;
    return 0;
}