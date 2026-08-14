#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int mangda[MAXN],nhuda[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,h;
    cin >> n >> h;
    for(int i = 1;i <= n;i++) {
        int x;
        cin >> x;
        if(i % 2 == 1) {
            mangda[x]++;
        }
        else nhuda[h-x+1]++;
    }
    for(int i = h;i >= 1;i--) {
        mangda[i] += mangda[i+1];
    }
    for(int i = 1;i <= h;i++) {
        nhuda[i] += nhuda[i-1];
    }
    int ans = 1e7;
    for(int i = 1;i <= h;i++) {
        ans = min(ans,nhuda[i]+mangda[i]);
    }
    cout << ans << ' ';
    int cnt = 0;
    for(int i = 1;i <= h;i++) {
        if(nhuda[i] + mangda[i] == ans) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}