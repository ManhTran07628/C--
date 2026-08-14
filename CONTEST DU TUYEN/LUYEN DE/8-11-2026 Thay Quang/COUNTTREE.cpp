#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int n;
vector<string> a;
vector<vector<int>> g;
vector<int> par, order;

// dp0[u]: số cách khi u không được chọn
// s0[u]: số cách khi u được chọn, cha u không được chọn
// s1[u]: số cách khi u được chọn, cha u cũng được chọn

vector<ll> dp0, s0, s1;

void solve(int K) {
    dp0.assign(n, 0);
    s0.assign(n, 0);
    s1.assign(n, 0);

    for (int ii = n - 1; ii >= 0; --ii) {
        int u = order[ii];

        // u không được chọn
        // Mỗi con có thể: không chọn hoặc chọn (vì cha u không chọn)
        ll ways0 = 1;

        vector<ll> poly(1, 1);

        for (int v : g[u]) {
            if (par[v] != u) continue;

            ways0 *= (dp0[v] + s0[v]);

            vector<ll> np(poly.size() + 1, 0);

            for (int c = 0; c < (int)poly.size(); ++c) {
                // v không chọn
                np[c] += poly[c] * dp0[v];

                // v được chọn
                np[c + 1] += poly[c] * s1[v];
            }

            poly = np;
        }

        dp0[u] = ways0;

        s0[u] = 0;
        for (int c = 0; c <= K && c < (int)poly.size(); ++c)
            s0[u] += poly[c];

        s1[u] = 0;
        for (int c = 0; c < K && c < (int)poly.size(); ++c)
            s1[u] += poly[c];
    }

    cout << dp0[0] + s0[0] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    a.resize(n);
    for (auto &s : a) cin >> s;

    g.assign(n, {});

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i][j] == 'Y') {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    // Root cây tại đỉnh 0
    par.assign(n, -1);
    order.clear();

    par[0] = 0;
    order.push_back(0);

    for (int i = 0; i < (int)order.size(); ++i) {
        int u = order[i];

        for (int v : g[u]) {
            if (v == par[u]) continue;

            par[v] = u;
            order.push_back(v);
        }
    }

    // Đếm cho từng k = 0..N-1
    for (int k = 0; k < n; ++k) {
        solve(k);
    }

    return 0;
}