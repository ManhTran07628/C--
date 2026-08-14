#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e6+7;
ll a[N];
ll n;

bool check(ll k) {
    // Lưu vị trí cuối cùng mỗi phần tử
    map<ll, ll> last_pos;
    for (ll i = 1; i <= n; i++) {
        last_pos[a[i]] = 0;
    }

    // Kiểm tra khoảng cách lớn nhất giữa các lần xuất hiện liên tiếp
    for (ll i = 1; i <= n; i++) {
        ll prev_pos = last_pos[a[i]];
        if (i - prev_pos > k) { // Nếu khoảng cách lớn hơn k thì không thỏa
            return false;
        }
        last_pos[a[i]] = i; // Cập nhật vị trí cuối của a[i]
    }

    // Kiểm tra đoạn cuối (tính từ lần xuất hiện cuối cùng đến hết dãy)
    for (auto &[value, last] : last_pos) {
        if (n - last + 1 > k) {
            return false;
        }
    }

    return true; // Tất cả các phần tử thỏa mãn
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    #define taskname "rannum"
    if (fopen(taskname ".inp", "r")) {
        freopen(taskname ".inp", "r", stdin);
        freopen(taskname ".out", "w", stdout);
    }

    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // Tìm kiếm nhị phân để xác định k nhỏ nhất
    ll L = 1, R = n, ans = n;
    while (L <= R) {
        ll mid = (L + R) / 2;
        if (check(mid)) {
            ans = mid;
            R = mid - 1; // Tìm k nhỏ hơn
        } else {
            L = mid + 1; // Tìm k lớn hơn
        }
    }

    cout << ans;
    return 0;
}
