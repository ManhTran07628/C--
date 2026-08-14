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
    ll n,k,p;
    cin >> n >> k >> p;
    ll tu = n*k*p;
    ll mau = (p*k+p);
    ll sotien = tu/mau;
    if(tu % mau != 0) sotien++;
    cout << sotien*p;
    return 0;
}  