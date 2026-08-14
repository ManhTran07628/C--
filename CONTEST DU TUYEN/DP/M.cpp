#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 400 + 7;
int n,a[MM];
ll dp[MM][MM],ps[MM][MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++) {
            dp[i][j] = oo;
            ps[i][j] = oo;
        }
    
    for(int i = 1;i <= n;i++) {
        dp[i][i] = a[i]; // chi phi ghep doan
        ps[i][i] = 0; // tong chi phi de ghep 
    }

    

    for(int len = 2;len <= n;len++) {
        for(int L = 1;L + len - 1 <= n;L++) {
            int R = L + len - 1;

            ll x = min(ps[L+1][R],ps[L][R-1]);

            for(int k = L;k < R;k++) {
                ll x = ps[L][k] + ps[k+1][R];
                if(ps[L][R] > dp[L][k] + dp[k+1][R] + x) {
                    ps[L][R] = dp[L][k] + dp[k+1][R] + x;
                    dp[L][R] = dp[L][k] + dp[k+1][R];
                }
            }

        }
    }
    cout << ps[1][n];
    return 0;
}

// gọi ps[i][j] là tổng chi phí tối thiếu để ghép đoạn từ i -> j
// gọi dp[i][j] là chi phí tối thiểu để ghép đoạn từ i -> j 
// (tức là chi phí để ghép mỗi đoạn i -> j) theo ps[i][j]
// dễ dàng nhận thấy dp[i][i] = 1 (do ghép đoạn i thì tốn chi phí là a[i])
// giả sử xét 1 đoạn có độ dài là len 
// ta sẽ duyệt biến len là độ dài khi ta dp trên đoạn có độ dài là len
// sau đó với mỗi len duyệt i, j sao cho i <= j (i + len - 1 == j)
// sau đó giả sử ta sẽ ghép đoạn từ i -> k và đoạn k + 1 -> j với nhau (i <= k <= j)
// khi đó ta sẽ lấy min chi phí khi ghép là dp[i][k] + dp[k+1][j] + ps[i][k] + ps[k+1][j]
// kết quả bài toán là ps[1][n]