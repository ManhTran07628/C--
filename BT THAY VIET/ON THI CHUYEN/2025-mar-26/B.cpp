#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
vector<int> s{6,2,5,5,4,5,6,3,7,6,6+2,2+2,2+5,2+5,2+4,2+5}; 
//             0 1 2 3 4 5 6 7 8 9 10 11  12  13  14  15

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0;i <= 15;i++) {
        for(int j = 0;j <= 15;j++) {
            for(int k = 0;k <= 15;k++) {
                if(s[i]+s[j]+s[k]+4==n&&i+j==k) ans++;
            }
        }
    }
    cout << ans;
    return 0;
}