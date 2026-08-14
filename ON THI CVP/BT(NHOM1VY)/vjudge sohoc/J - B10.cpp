#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a,b,n;
    cin >> a >> b >> n;
    int ans = 0;
    for(int k = a;k <= b;k++) {
        int t = k,cnt = 1;
        for(int i = 2;i <= sqrt(t);i++) {
            int m = 0;
            while(t % i == 0) {
                t /= i;
                m++;
            }
            cnt *= (m+1);
        }
        if(t > 1) cnt *= 2;
        if(cnt == n) ans++;
    }
    cout << ans;
    return 0;
}