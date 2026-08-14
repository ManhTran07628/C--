#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Hàm tính GCD
ll gcd(ll a, ll b) {
    while (b) {
        ll tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

// Hàm kiểm tra mảng có GCD > 1 không
ll compute_gcd(const vector<ll>& arr) {
    ll g = arr[0];
    for (size_t i = 1; i < arr.size(); i++) {
        g = gcd(g, arr[i]);
    }
    return g;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; ll k;
        cin >> n >> k;
        vector<ll> a(n);
        for (auto &x : a) cin >> x;

        // Thử không thay đổi phần tử nào
        if (compute_gcd(a) > 1) {
            for (auto x : a) cout << x << " ";
            cout << "\n";
            continue;
        }

        // Thử cộng k cho tất cả phần tử
        vector<ll> b(n);
        for (int i = 0; i < n; i++) b[i] = a[i] + k;
        if (compute_gcd(b) > 1) {
            for (auto x : b) cout << x << " ";
            cout << "\n";
            continue;
        }

        // Thử hỗn hợp từng phần tử cộng k hoặc không cộng
        // Dùng cách tìm d từ 2 đến 100000 (heuristic)
        bool found = false;
        for (ll d = 2; d <= 100000 && !found; d++) {
            bool valid = true;
            for (int i = 0; i < n; i++) {
                if ((a[i] % d != 0) && ((a[i] + k) % d != 0)) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                for (int i = 0; i < n; i++) {
                    if (a[i] % d == 0) cout << a[i] << " ";
                    else cout << (a[i] + k) << " ";
                }
                cout << "\n";
                found = true;
            }
        }
        // Nếu không tìm được, in nguyên mảng (vấn đề đã bảo là có cách)
        if (!found) {
            for (auto x : a) cout << x << " ";
            cout << "\n";
        }
    }

    return 0;
}
