#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    int ans = 0,i = 1,j = n;
    while(i <= j) {
        if(a[i] + a[j] <= m) {
            ans++;
            i++;j--;
        }
        else {
            j--;
            ans++;
        }
    }
    cout << ans;
    return 0;
}