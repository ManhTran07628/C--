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
    int l,r;
    cin >> l >> r;
    int cnt = 0;
    for(int a = l;a <= r-1;a++) {
        for(int b = a+1;b <= r;b++) {
            int ok = 0,k = a*b;
            for(int j = 2;j <= k;j++) {
                if(k % j == 0) {
                    int p = sqrt(j);
                    if(p*p==j) ok = 1;
                }
            }
            cnt += ok;
        }
    }
    cout << cnt;
    return 0;
}