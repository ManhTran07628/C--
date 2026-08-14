#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
int a[15][15];
vector<vector<int>> b(15,vector<int>(15,0));
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int h1,w1,h2,w2;
    cin >> h1 >> w1;

    for(int i = 1;i <= h1;i++) 
        for(int j = 1;j <= w1;j++) 
            cin >> a[i][j];
    
    cin >> h2 >> w2;
    for(int i = 1;i <= h2;i++) 
        for(int j = 1;j <= w2;j++) 
            cin >> b[i][j];
    int ans = 0;
    for(int mask_a = 0;mask_a < (1 << h1);mask_a++) {
        for(int mask_b = 0;mask_b < (1 << w1);mask_b++) {
            int width[15] = {},height[15] = {};
            for(int i = 0;i < h1;i++) 
                if((mask_a >> i) & 1) height[i+1] = 1;

            for(int i = 0;i < w1;i++) 
                if((mask_b >> i) & 1) width[i+1] = 1;

            vector<vector<int>> c(15,vector<int>(15,0));
            int h = 1,w = 1;
            for(int i = 1;i <= h1;i++) {
                if(!height[i]) continue;
                for(int j = 1;j <= w1;j++) {
                    if(!width[j]) continue;
                    c[h][w] = a[i][j];
                    w++;
                }
                h++;
                w = 1;
            }
            ans += (b == c);
        }
    }
    cout << (ans > 0 ? "Yes" : "No");
    return 0;
}