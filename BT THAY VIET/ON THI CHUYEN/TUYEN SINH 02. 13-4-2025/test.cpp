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
    srand(time(NULL));
    int n;
    cin >> n;
    cout << n << ' ';
    for(int i = 1;i <= n;i++) {
        int a = rand()%1000000+500000;
        cout << a << ' ';
    }
    return 0;
}