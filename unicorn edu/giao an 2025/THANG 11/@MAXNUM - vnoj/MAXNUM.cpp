#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
int mp[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        int a;
        cin >> a;
        mp[a]++;
    }
    for(int i = 9;i >= 1;i--) {
        // neu chu so hang chuc < chu so hang don vi
        for(int j = i * 10 + 9;j >= i * 10 + i;j--) 
            while(mp[j]) {
                cout << j;
                mp[j]--;
            }
        
        // in ra cac so hang don vi
        for(int k = 1;k <= mp[i];k++) 
            cout << i;
        
        // in ra cac so co hang chuc > chu so hang don vi
        for(int j = i * 10 + 9;j >= i * 10;j--) {

            for(int k = 1;k <= mp[j];k++) 
                cout << j;

        }

    }
    return 0;
}