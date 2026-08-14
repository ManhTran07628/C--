#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 100 + 7;
int n,m,k;
int a[MM][MM];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++) {
            char c; cin >> c;
            a[i][j] = c - 'A';
        }

    
    int res = 0;
    for(int x = 1;x <= n;x++) {
        for(int u = x;u <= n;u++) {

            int cnt1[26] = {}, cnt2[26] = {}, cur_1 = 0,cur_2 = 0;

            for(int L1 = 1,L2 = 1,j = 1;j <= m;j++) {

                // update
                for(int t = x;t <= u;t++) {
                    if(cnt1[ a[t][j] ] == 0) cur_1++;
                    cnt1[ a[t][j] ]++;
                }
                
                for(int t = x;t <= u;t++) {
                    if(cnt2[ a[t][j] ] == 0) cur_2++;
                    cnt2[ a[t][j] ]++;
                }

                while(L1 <= m && cur_1 > k - 1) {
                    for(int t = x;t <= u;t++) {
                        if(cnt1[ a[t][L1] ] == 1) cur_1--;
                        cnt1[ a[t][L1] ]--;
                    }
                    L1++;
                }
                
                while(L2 <= m && cur_2 > k) {
                    for(int t = x;t <= u;t++) {
                        if(cnt2[ a[t][L2] ] == 1) cur_2--;
                        cnt2[ a[t][L2] ]--;
                    }
                    L2++;
                }
                res += abs(L2 - L1);
            }

        }
    }
    cout << res;
    
    return 0;
}
