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
    for(int i = 1;i <= n;i++) {
        int b,d;
        cin >> b >> d;
        a[b]++;
        a[d]--;
    }
    int ans = 0,cnt = 0;
    for(int i = 1;i < MAXN;i++) {
        a[i] += a[i-1];
        if(ans < a[i]) {
            ans = a[i];
            cnt = i;
        }
    }
    cout << cnt << ' ' << ans;
    return 0;
}