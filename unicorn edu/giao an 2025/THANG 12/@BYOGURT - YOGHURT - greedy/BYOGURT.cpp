#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
int n, s, c[N], y[N];
int main()
{
     cin >> n >> s;
     int cost = INT_MAX;
     long long ans = 0;
     for (int i=1; i<=n; i++){
        cin >> c[i] >> y[i];
     }
     for (int i=1; i<=n; i++){
            cost = INT_MAX;
        for (int j=0; j<i; j++)
            cost = min(cost, c[i-j] + s*j);
        ans += cost*y[i];
     }
     cout << ans;
     return 0;
}