#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
ll fib[100],a[MAXN],v[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fib[2] = fib[1] = 1;
    for(int i = 3;i <= 50;i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        if(a[i] == 1) v[i] = 1;
        else {
            for(int j = 1;j <= 50;j++) {
                if(fib[j] == a[i]) {
                    v[i] = j;
                    break;
                }
            }
            if(v[i] == 0) v[i] = -1;
        }
    }
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = i;j <= n;j++) {
            bool kt = 0;
            if(v[j] != -1) {
                if(j-i+1 == 1) kt = 1;
                else if(j-i+1 == 2)  if((a[i] == 1 && a[j] == 1) ||
                (a[i] == 1 && a[j] == 2)) kt = 1;
                if(v[j] == v[j-1]+1) kt = 1;
                if(v[j] == 3 && v[j-1] == 1) kt = 1;
            }
            else break;
            ans += kt;
            if(!kt) break;
        }
    }
    cout << ans;
    return 0;
}