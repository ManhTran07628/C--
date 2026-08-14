#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    string s;
    cin >> n >> k >> s;
    s = " " + s;
    int i = 1,j = 1,cnt_w = 0,ans = n;
    while(i <= n && j <= n) {
        if(s[j] == 'W') cnt_w++;
        if(j-i+1 > k) {
            if(s[i] == 'W')  cnt_w--;
            i++;
        }
        if(j-i+1 == k) ans = min(ans,cnt_w);
        j++;
    }
    cout << ans;
    return 0;
}

