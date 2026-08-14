#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while(q--) {
        int a,b;
        cin >> a >> b;
        int c = 0;
        for(int i = 0;i <= 4;i++) {
            int bita = (a >> i) & 1;
            int bitb = (b >> i) & 1;
            int bitc = bita ^ bitb;
            c = c | (bitc << i);
        }
        for(int i = 5;i <= 9;i++) {
            int bita = (a >> i) & 1;
            int bitb = (b >> i) & 1;
            int bitc = bita & bitb;
            c = c | (bitc << i);
        }
        for(int i = 10;i <= 14;i++) {
            int bita = (a >> i) & 1;
            int bitb = (b >> i) & 1;
            int bitc = bita | bitb;
            c = c | (bitc << i);
        }
        cout << c << '\n';
    }
    return 0;
}