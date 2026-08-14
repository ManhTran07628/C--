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
    ll n,p;
    cin >> n >> p;
    ll trai = p/2;
    ll phai = (n/2+1)-trai-1;
    cout << min(trai,phai);
    return 0;
}