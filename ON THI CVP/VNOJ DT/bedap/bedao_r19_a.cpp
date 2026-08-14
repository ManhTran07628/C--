#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
map<int,int> lt1,lt2;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll x,k;
    cin >> x >> k;
    cout << k / __gcd(x, k);
    return 0;
}