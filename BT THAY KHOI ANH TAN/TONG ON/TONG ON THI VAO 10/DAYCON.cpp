#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN],ps[MAXN];
map<int,int> fibos;
int n,p,q,ans = 0;

void sinh()
{
    int fib[1000];
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2;i <= 1000;i++) {
        if(fib[i] > 1e16) break;
        fib[i] = fib[i-1]+fib[i-2];
        fibos[fib[i]] = 1;
    }
    fibos[1] = 1;
    fibos[0] = 1;
}

void sub123(){
    sinh();
    for(int l = p;l <= q;l++) {
        int i = 1,j = 1,sum = 0;
        while(i <= n && j <= n) {
            if(j-i+1 > l) {
                if(fibos[sum]) ans++;
                sum -= a[i];
                i++;
            }
            sum += a[j];
            j++;
        }
        if(dem[sum]) ans++;
    }
    cout << ans;
}

void sub4()
{
    int ans = 0;
    
    for(int i = p;i <= n;i++) {
        for(auto fibo:fibos) {

        }
    }

}

signed main()
{
    ios_base::sync_with_stdio(0);   
    cin.tie(0);
    cin >> n >> p >> q;
    cout << ans;
    return 0;
}