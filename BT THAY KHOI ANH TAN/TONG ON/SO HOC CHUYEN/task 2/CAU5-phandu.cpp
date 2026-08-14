#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e7;
const int MOD = 1e9+7;

int binpow(int a,int b)
{
    int ans = 1;
    while(b > 0) {
        if(b % 2) ans = ans * a % MOD;
        b >>= 1;
        a = a * a % MOD;
    }
    return ans;
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin >> k;
    if(k < 10) cout << 1;
    else {
        int num = 1,pos = 1;
        for(int i = 1;i < 1e8;i++) {
            if(num == 0) {
                pos = i;
                break;
            }
            num = (num*10+1)%k;
        }   
        num = 1;
        for(int i = 1;i <= pos;i++) {
            num = (num*10+1)%MOD;
        }
        cout << num*binpow()
    }
    return 0;
}