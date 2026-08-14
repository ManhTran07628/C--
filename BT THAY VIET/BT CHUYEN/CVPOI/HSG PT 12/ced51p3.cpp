#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 100;
int s[MM + 7], cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt[MM + 7], vis[MM + 7];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> s[i]; cnt[ s[i] ]++;
    }
    for(int i = 1;i <= 100;i++) {
        if(cnt[i] == 1) cnt1++;
        if(cnt[i] == 2) cnt2++;
        if(cnt[i] >= 3) cnt3++;
    }
    string res; for(int i = 0;i <= n;i++) res.push_back(' ');
    if(cnt1 % 2 == 0) {
        cout << "YES" << '\n';
        int lim = cnt1 / 2;
        for(int i = 1;i <= n;i++) {
            if(cnt[ s[i] ] == 1 && lim > 0) {
                res[i] = 'A';
                lim--;
            } 
            else res[i] = 'B';
        }
        for(int i = 1;i <= n;i++) cout << res[i];
    }
    else if(cnt1 % 2 == 1 && cnt3 > 0) {
        cout << "YES" << '\n';
        int lim1 = (cnt1 + 1) / 2, lim3 = 1;
        for(int i = 1;i <= n;i++) {
            if(vis[i]) continue;
            if(cnt[ s[i] ] == 1 && lim1) {
                lim1--;
                res[i] = 'A';
            } 
            else if(cnt[ s[i] ] >= 3 && lim3) {
                int cntq = cnt[ s[i] ] - 1;
                for(int j = i;j <= n;j++) {
                    if(cntq == 0) break;
                    if(s[j] == s[i]) {
                        vis[j] = 1; res[j] = 'A'; cntq--;
                    }
                }
                lim3--;
            }
            else res[i] = 'B';
        }
        for(int i = 1;i <= n;i++) cout << res[i];
    }
    else if(cnt1 == 0) {
        cout << "YES" << '\n';
        for(int i = 1;i <= n;i++) cout << 'A';
    }
    else cout << "NO";
    // cout << cnt1 << ' ' << cnt2 << ' ' << cnt3;
    return 0;   
}