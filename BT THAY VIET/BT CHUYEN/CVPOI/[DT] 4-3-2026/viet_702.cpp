#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define fi first
#define se second
#define oo (ll) 1e18
#define int128 __int128_t
const int MM = 2e3 + 7;
int n,m;
int a[MM][MM],col[MM],row[MM],sum_row[MM],sum_col[MM];

bitset<MM> sq[MM];

void print128(int128 n) {
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n > 9) print128(n / 10);
    putchar(n % 10 + '0');
}

signed main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }       
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        string s; cin >> s;
        for(int j = 1;j <= m;j++) {
            a[i][j] = s[j - 1] - '0';
            if(a[i][j]) {
                sq[i].set(j);
                row[i]++;
                col[j]++;
            }
        }
    }

    int128 res = 0, K = 0;

    // v2 -> col -> v1 -> row
    for(int j = 1;j <= m;j++)
        for(int i = 1;i <= n;i++) {
            if(a[i][j]) {
                sum_col[j] += (row[i] - 1);
            }
        }
    
    // v2 -> row -> v1 col
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++) {
            if(a[i][j]) {
                sum_row[i] += (col[j] - 1);
            }
        }

    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++) {
            if(a[i][j]) {
                int128 cnt1 = sum_col[j] - (row[i] - 1);
                int128 cnt2 = sum_row[i] - (col[j] - 1);
                res += (int128)2 * cnt1 * cnt2;
            }
        }

    for(int i = 1;i <= n;i++)
        for(int j = i + 1;j <= n;j++) {
            bitset<MM> cur = sq[i] & sq[j];
            int128 k = cur.count();
            K += k * (k - 1) / 2;
        }
    res = res - K * 8;
    if (res == 0) cout << "0";
    else print128(res);
    return 0;
}