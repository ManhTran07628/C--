#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a = 0;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while(q--) {
        int t,x;
        cin >> t;
        if(t == 1) {
            int x;
            cin >> x;
            a = a ^ x;
        }
        else if(t == 2) {
            if(a != 0) {
                for(int i = 29;i >= 0;i--) {
                    int bit_a = a >> i;
                    if(bit_a & 1) {
                        a = a ^ (bit_a << i);
                        break;
                    }
                }
            }
        }
        else if(t == 3) {
            int cnt = 0;
            for(int i = 29;i >= 0;i--) {
                int bit_a = a >> i;
                if(bit_a & 1) cnt++;
            }
            cout << cnt << '\n';
        }
    }
    return 0;
}