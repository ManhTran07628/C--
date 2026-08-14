#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int n;


void solve1() // 10^4
{
    int cnt = 0;
    for(int i = n-1;i >= 1;i--) {
        int cur = n,pre = i;
        while(cur > 0) {
            if(cur <= cur-pre) break;
            cur = cur - pre;
            pre--;
        }
        if(cur == 0) cnt++;
    }
    cout << cnt << '\n';
}

void solve2() // 10^9
{
    int cnt = 0;
    for(int k = 2;k <= sqrt(n*2);k++) {
        int a = (2*n-k*(k+1));
        int b = (2*(k+1));
        if(a % b == 0 && a / b > 0) cnt++;
    }
    cout << cnt << '\n';
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    solve1();
    solve2();
    return 0;
}