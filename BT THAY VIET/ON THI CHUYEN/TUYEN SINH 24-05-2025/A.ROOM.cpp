#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;

int type(int cost1,int cost2,int a,int b)
{
    int ans = 0;
    for(int i = a;i <= b;i++) {
        if(i <= 15) {
            if(i-a+1 > 10) ans += (cost1*0.5);
            else ans += cost1;
        }
        else {
            if(i-a+1 > 10) ans += (cost2*0.5);
            else ans += cost2;
        }
    }
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k;
    int a,b;
    cin >> k >> a >> b;
    if(k == 1) cout << type(500000,600000,a,b);
    else cout << type(700000,800000,a,b);
    return 0;
}