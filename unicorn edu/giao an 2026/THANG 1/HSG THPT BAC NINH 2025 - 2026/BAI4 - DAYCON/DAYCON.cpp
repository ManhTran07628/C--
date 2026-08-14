// Mochi Kasato - MKasato
// FB: https://w...content-available-to-author-only...k.com/mochikasato/
// Problem link:
#include <bits/stdc++.h>
#define boostcode ios_base::sync_with_stdio(0); cin.tie(0);
#define openf if (fopen("DAYCON.inp", "r")) {freopen("DAYCON.inp", "r", stdin); freopen("DAYCON.out", "w", stdout);}
#define fi first
#define se second
#define pb(x) push_back(x)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n;
int a[200002];
map<int, int> mp; // Để nén số a[i] và lưu vào b[i]
int b[200002]; // Là a[] nhưng được nén số
int c[200002]; // c[i]: Là "độ khó" của a[i]
ll seg[800002]; // Dùng để lưu và tính max(l..r).

void update(int id, int l, int r, int pos, ll val) {
    if (pos<l || pos>r) return;
    if (l == r) {
        seg[id] = max(seg[id], val);
        return;
    }
    int mid = (l + r)>>1;
    update(id<<1, l, mid, pos, val);
    update(id<<1 | 1, mid+1, r, pos, val);
    seg[id] = max(seg[id<<1], seg[id<<1 | 1]);
}
ll query(int id, int l, int r, int u, int v) {
    if (r<u || v<l) return 0;
    if (u<=l && r<=v) {
        return seg[id];
    }
    int mid = (l + r)>>1;
    return max(query(id<<1, l, mid, u, v),
               query(id<<1 | 1, mid+1, r, u, v));
}

int main() {
    boostcode;
    openf;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]];
    }
    // Thực hiện nén số a[i] và lưu vào b[i]:
    int m = 0;
    for (pair<const int, int> &cur : mp) {
        cur.se = ++m;
    }
    for (int i = 1; i <= n; i++) b[i] = mp[a[i]];
    // Tính và lưu "độ khó" của a[i] vào c[i]:
    for (int i = 1; i <= n; i++) {
        int val = a[i];
        if (!val) continue; // Xử lí trường hợp đặc biệt: a[i] = 0
        c[i] = 1;
        while (val) {
            c[i] *= (val%10);
            val /= 10;
        }
    }
    // Xử lí chính (tính kết quả bài toán cần tìm):
    for (int i = 1; i <= n; i++) {
        ll mx = query(1, 1, m, 1, b[i]-1);
        update(1, 1, m, b[i], mx+c[i]);
    }
    cout << query(1, 1, m, 1, m);

    return 0;
}
/* TESTS:
Test 1:
5
5 101 54 123 56
-->
55
Test 2:

-->

Test 3:

-->

Test 4:

-->

*/
