// Mochi Kasato - MKasato
// FB: https://w...content-available-to-author-only...k.com/mochikasato/
// Problem link: https://c...content-available-to-author-only...s.com/problemset/problem/484/B
#include <bits/stdc++.h>
#define boostcode ios_base::sync_with_stdio(0); cin.tie(0);
#define openf if (fopen("DOLECH.inp", "r")) {freopen("DOLECH.inp", "r", stdin); freopen("DOLECH.out", "w", stdout);}
#define fi first
#define se second
#define pb(x) push_back(x)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n;
int a[200002];
bool check[1000002]; // Để dánh dấu
int b[1000002]; // b[i]: Giá trị a[j] lớn nhất thỏa mãn a[j] < i

int main() {
    boostcode;
    openf;

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    // Đoạn này tìm a[i] lớn nhất và đánh dấu những giá trị a[i] vào mảng check[]:
    int mx = -1;
    for (int i = 1; i <= n; i++) {
        check[a[i]] = true;
        mx = max(mx, a[i]);
    }
    // Đoạn này tính b[i] (1 <= i <= 1e6) dựa vào mảng check[]
    int cur = -1;
    for (int i = 1; i <= mx; i++) {
        if (check[i]) cur = i;
        b[i] = cur;
        check[i] = false;
    }
    // Đoạn này xử lí và tính res (kết quả bài toán cần tìm):
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (check[a[i]]) continue;
        check[a[i]] = true;
        for (int j = a[i]*2; j<=mx; j += a[i]) {
            int val = b[j-1];
            res = max(res, val%a[i]);
        }
        res = max(res, mx%a[i]);
    }
    cout << res;

    return 0;
}