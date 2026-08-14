// Mochi Kasato - MKasato
// FB: https://w...content-available-to-author-only...k.com/mochikasato/
// Problem link:
#include <bits/stdc++.h>
#define boostcode ios_base::sync_with_stdio(0); cin.tie(0);
#define openf if (fopen("MATKHAU.inp", "r")) {freopen("MATKHAU.inp", "r", stdin); freopen("MATKHAU.out", "w", stdout);}
#define fi first
#define se second
#define pb(x) push_back(x)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, m;
int a[5000002];
int b[1000002];
int cnt;

void push(int i) { // Hàm này thêm phần tử a[i] vào đoạn [l, r] đang xét
    if (!b[a[i]]) cnt++;
    b[a[i]]++;
}
void pop(int i) { // Hàm này xóa phần tử a[i] khỏi đoạn [l, r] đang xét
    b[a[i]]--;
    if (!b[a[i]]) cnt--;
}

int main() {
    boostcode;
    openf;

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int l = 1;
    int res = n+1;
    for (int r = 1; r <= n; r++) {
        push(r);
        while (cnt >= m) {
            pop(l);
            if (cnt < m) { // Dừng lại khi bỏ a[l] làm giảm cnt xuống thành m-1 (cnt=m thành cnt<m)
                push(l);
                break;
            }
            l++;
        }
        if (cnt == m) res = min(res, r-l+1);
    }
    cout << res;

    return 0;
}
/* TESTS:
Test 1:
10 4
5 2 1 1 3 2 1 3 2 1
-->
5
Test 2:

-->

Test 3:

-->

Test 4:

-->

*/
