#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 2e5 + 7;

void solve() {
    int n,m;
    cin >> n >> m;
    vector<string> grid;
    grid.resize(n + 1);
    for(int i = 0;i < n;i++) {
        cin >> grid[i];
    }

    for(int j = 0;j < m;j++) {
        int empty_pos = n - 1; 
        for(int i = n - 1;i >= 0;i--) {
            if(grid[i][j] == 'o') empty_pos = i - 1;
            else if (grid[i][j] == '*') {
                char temp = grid[i][j];
                grid[i][j] = '.';
                grid[empty_pos][j] = temp;
                empty_pos--;
            }
        }
    }
    for(int i = 0;i < n;i++) {
        cout << grid[i] << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}