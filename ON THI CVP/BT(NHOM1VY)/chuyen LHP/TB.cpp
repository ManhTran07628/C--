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
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(int i = 1;i <= n-2;i++) {
        int c = i;
        for(int j = i+2;j <= n;j++) {
            for(int k = c;k <= n-1;k++) {
                if(a[k]*2 == a[i] + a[j]) ans++;
                else if(a[k]*2 > a[i] + a[j]) break;
                c = k;
            }
        }
    }
    cout << ans;
    return 0;
}