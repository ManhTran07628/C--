#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a,b;
    cin >> a >> b;
    int A = a * 2,B = b * 3;
    int ans = A*B-(a*b);
    cout << ans;
    return 0;
}