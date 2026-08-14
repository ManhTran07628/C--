#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MM = 2e6 + 7;
const int MS = 1001;
const int MOD = 1e9 + 7;
const int LOG = 10;  

ll n, q;
ll A[MM], B[MM], C[MM], D[MM], E[MM], F[MM], L[MM];
int a[MS][MS];
int st[LOG + 1][LOG + 1][MS][MS];

void process_sequences() {
    A[1] = 1 + ((A[0] * A[0]) % MOD);
    B[1] = 1 + ((B[0] * B[0]) % MOD);
    C[1] = 1 + ((C[0] * C[0]) % MOD);
    D[1] = 1 + ((D[0] * D[0]) % n);
    E[1] = 1 + ((E[0] * E[0]) % n);
    F[1] = 1 + ((F[0] * F[0]) % n);
    for (int i = 2; i < MM; i++) {
        A[i] = 1 + ((A[i - 1] + A[i - 2]) % MOD);
        B[i] = 1 + ((B[i - 1] + B[i - 2]) % MOD);
        C[i] = 1 + ((C[i - 1] + C[i - 2]) % MOD);
        D[i] = 1 + ((D[i - 1] + D[i - 2]) % n);
        E[i] = 1 + ((E[i - 1] + E[i - 2]) % n);
        F[i] = 1 + ((F[i - 1] + F[i - 2]) % n);
    }
    for (int i = 0; i < MM; i++) {
        if (D[i] == 0) D[i] = n;
        if (E[i] == 0) E[i] = n;
        L[i] = n - max(D[i], E[i]);
    }
}

void build_sparse_table() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            st[0][0][i][j] = (A[i] + B[j]) % MOD;

    for (int k = 1; k <= LOG; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j + (1 << k) - 1 <= n; j++)
                st[0][k][i][j] = max(st[0][k - 1][i][j], st[0][k - 1][i][j + (1 << (k - 1))]);

    for (int j = 1; j <= LOG; j++)
        for (int k = 0; k <= LOG; k++)
            for (int i = 1; i + (1 << j) - 1 <= n; i++)
                for (int t = 1; t + (1 << k) - 1 <= n; t++)
                    st[j][k][i][t] = max(st[j - 1][k][i][t], st[j - 1][k][i + (1 << (j - 1))][t]);
}

int query_rect(int x1, int y1, int x2, int y2) {
    if (x1 > x2 || y1 > y2) return 0;
    int j = __lg(x2 - x1 + 1);
    int k = __lg(y2 - y1 + 1);
    return max({st[j][k][x1][y1], 
                st[j][k][x2 - (1 << j) + 1][y1],
                st[j][k][x1][y2 - (1 << k) + 1], 
                st[j][k][x2 - (1 << j) + 1][y2 - (1 << k) + 1]});
}

int get_max_cyclic(int x, int y, int z) {
    int r1 = x, r2 = x + z - 1;
    int c1 = y, c2 = y + z - 1;
    
    int row_seg[2][2], col_seg[2][2], rn = 0, cn = 0;
    
    if (r2 <= n) { row_seg[rn][0] = r1; row_seg[rn++][1] = r2; }
    else { row_seg[rn][0] = r1; row_seg[rn++][1] = n; row_seg[rn][0] = 1; row_seg[rn++][1] = r2 - n; }
    
    if (c2 <= n) { col_seg[cn][0] = c1; col_seg[cn++][1] = c2; }
    else { col_seg[cn][0] = c1; col_seg[cn++][1] = n; col_seg[cn][0] = 1; col_seg[cn++][1] = c2 - n; }
    
    int res = 0;
    for (int i = 0; i < rn; i++)
        for (int j = 0; j < cn; j++)
            res = max(res, query_rect(row_seg[i][0], col_seg[j][0], row_seg[i][1], col_seg[j][1]));
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    if (!(cin >> n >> q)) return 0;
    cin >> A[0] >> B[0] >> C[0] >> D[0] >> E[0] >> F[0];

    process_sequences();
    build_sparse_table();

    ll total_res = 0;
    int nx = 0, ny = 0, type1_count = 0;

    for (int i = 1; i <= q; i++) {
        if ((C[i] & 1) == 0) { 
            type1_count++;
            int z = (1 + (L[i] & (L[i] ^ F[i])));
            int cur_x = (D[i] + nx - 1) % n + 1;
            int cur_y = (E[i] + ny - 1) % n + 1;
            total_res = (total_res + get_max_cyclic(cur_x, cur_y, z)) % MOD;
            if (type1_count % 1000 == 0) {
                cout << total_res << "\n";
                total_res = 0;
            }
        } else { 
            nx = (nx + D[i]) % n;
            ny = (ny + E[i]) % n;
        }
    }
    
    if (type1_count % 1000 != 0) cout << total_res << "\n";

    return 0;
}