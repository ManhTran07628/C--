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
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int ans = abs(d-c)*b*2 + abs(d-c-1)*a;
    cout << ans;
    return 0;
}