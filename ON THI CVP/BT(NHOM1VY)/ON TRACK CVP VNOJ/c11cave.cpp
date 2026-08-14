#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN],md[MAXN],nd[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,h;
    cin >> n >> h;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        if(i % 2 == 1) md[a[i]]++;
        else nd[h-a[i]+1]++;
    }
    for(int i = h;i >= 1;i--) md[i] += md[i+1]; 
    // so mang da can vuot qua 
    // o chieu cao thu i de den dich                    
    for(int i = 1;i <= h;i++) nd[i] += nd[i-1];
    // so nhu da can vuot qua
    // o chieu cao thu i de den dich
    int ans = n,cnt = 0;
    for(int i = 1;i <= h;i++) {
        ans = min(ans,md[i]+nd[i]);
    }
    cout << ans << ' ';
    for(int i = 1;i <= h;i++) {
        if(md[i]+nd[i] == ans) cnt++;
    }
    cout << cnt;
    return 0;
}