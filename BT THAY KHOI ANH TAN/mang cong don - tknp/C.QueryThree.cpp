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
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        a[i] += a[i-1];
    }
    int i = 1,j = 1,ans = 0;
    while(i <= n && j <= n) {
        while(a[j]-a[i-1]>k && j > i) i++;
        if(a[j]-a[j-1] > k) {
            cout << -1 << '\n';
            j++;continue;
        }
        cout << i << '\n';
        j++;

    }
    return 0;   
}

// a[j] - a[i] <= k   
// a[j] <= k + a[i];