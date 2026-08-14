#include<bits/stdc++.h>
using namespace std;
const int N = 2505;
const int INF = 1e8+10;
long long n,t, a[N], ans[N];
int main()
{
    cin >> n >> t;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        a[i] += a[i-1];
        ans[i] = a[i];
    }
    for (int i=1; i<=n; i++){
    for (int j=i; j>0; j--)
        {
        ans[i] = min(ans[i],a[j]+ans[i-j]);
   // cout << i << " " << ans[i] << endl;
    }
    ans[i] += t*2;
    }
    cout << ans[n]-t;
    return 0;
}