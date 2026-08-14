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
        int s,t;
        cin >> s >> t;
        a[s]++;
        a[t+1]--;
    }
    int ans = 0;
    for(int i = 1;i <= MAXN;i++) {
        a[i] += a[i-1];
        ans = max(ans,a[i]);
    }
    int cnt = 0;
    for(int i = 1;i <= MAXN;i++) {
        if(a[i] == ans) cnt++;
    }
    cout << ans << '\n' << cnt;
    return 0;
}