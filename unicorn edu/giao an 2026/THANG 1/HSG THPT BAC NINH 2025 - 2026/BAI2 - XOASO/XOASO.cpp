// Mochi Kasato - MKasato
// FB: https://w...content-available-to-author-only...k.com/mochikasato/
// Problem link: https://d...content-available-to-author-only...j.ca/problem/coci12c4p4
#include <bits/stdc++.h>
#define boostcode ios_base::sync_with_stdio(0); cin.tie(0);
#define openf if (fopen("XOASO.inp", "r")) {freopen("XOASO.inp", "r", stdin); freopen("XOASO.out", "w", stdout);}
#define fi first
#define se second
#define pb(x) push_back(x)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, k;
int a[1000002];
int b[1000002];
deque<int> dq; // Lưu min-max tịnh tuyến

void push(int i) {
    while (dq.size() && b[i]<=b[dq.back()]) dq.pop_back();
    dq.push_back(i);
}
void pop(int i) {
    if (i==dq.front()) dq.pop_front();
}

int main() {
    boostcode;
    openf;

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1, a+n+1);
    // Tính b[i] = a[i+1] - a[i]:
    for (int i = 1; i < n; i++) b[i] = a[i+1] - a[i];
    // Xử lí chính: Duyệt từng đoạn con liên tiếp độ dài N-K và cập nhật |M| + |m| nhỏ nhất vào res:
    for (int i = 1; i < n-k-1; i++) push(i);
    int res = INT_MAX;
    for (int i = 1; i <= k+1; i++) {
        push(i+(n-k)-2);
        pop(i-1);
        int M = a[i+(n-k)-1] - a[i];
        int m = b[dq.front()];
        res = min(res, M + m);
    }
    cout << res;

    return 0;
}
/* TESTS:
Test 1:
5 2
-3 -2 3 8 6
-->
7
Test 2:
6 2
-5 8 10 1 13 -1
-->
13
Test 3:

-->

Test 4:

-->

*/
